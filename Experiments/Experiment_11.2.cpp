#include <iostream>

class Node {
public:
    std::vector<int> keys;
    std::vector<Node*> values;
    bool leaf;
    Node* next;

    Node(bool isLeaf) : leaf(isLeaf), next(nullptr) {}
};

class BPlusTree {
private:
    Node* root;
    int degree;

public:
    BPlusTree(int degree) : degree(degree) {
        root = new Node(true);
    }

    bool search(int key) {
        Node* current = root;
        while (!current->leaf) {
            int i = 0;
            while (i < current->keys.size()) {
                if (key < current->keys[i]) {
                    break;
                }
                i += 1;
            }
            current = current->values[i];
        }

        int i = 0;
        while (i < current->keys.size()) {
            if (key == current->keys[i]) {
                return true;
            }
            i += 1;
        }
        return false;
    }

    void insert(int key) {
        Node* current = root;
        if (current->keys.size() == 2 * degree) {
            Node* newRoot = new Node(false);
            root = newRoot;
            newRoot->values.push_back(current);
            split(newRoot, 0, current);
            insertNonFull(newRoot, key);
        } else {
            insertNonFull(current, key);
        }
    }

    void insertNonFull(Node* current, int key) {
        int i = 0;
        while (i < current->keys.size()) {
            if (key < current->keys[i]) {
                break;
            }
            i += 1;
        }

        if (current->leaf) {
            current->keys.insert(current->keys.begin() + i, key);
        } else {
            if (current->values[i]->keys.size() == 2 * degree) {
                split(current, i, current->values[i]);
                if (key > current->keys[i]) {
                    i += 1;
                }
            }
            insertNonFull(current->values[i], key);
        }
    }

    void split(Node* parent, int index, Node* node) {
        Node* newNode = new Node(node->leaf);
        parent->values.insert(parent->values.begin() + index + 1, newNode);
        parent->keys.insert(parent->keys.begin() + index, node->keys[degree - 1]);

        newNode->keys.insert(newNode->keys.end(), node->keys.begin() + degree, node->keys.end());
        node->keys.erase(node->keys.begin() + degree - 1, node->keys.end());

        if (!node->leaf) {
            newNode->values.insert(newNode->values.end(), node->values.begin() + degree, node->values.end());
            node->values.erase(node->values.begin() + degree, node->values.end());
        }
    }

    void stealFromLeft(Node* parent, int i) {
        Node* node = parent->values[i];
        Node* leftSibling = parent->values[i - 1];
        node->keys.insert(node->keys.begin(), parent->keys[i - 1]);
        parent->keys[i - 1] = leftSibling->keys[leftSibling->keys.size() - 1];
        if (!node->leaf) {
            node->values.insert(node->values.begin(), leftSibling->values[leftSibling->values.size() - 1]);
            leftSibling->values.pop_back();
        }
    }

    void stealFromRight(Node* parent, int i) {
        Node* node = parent->values[i];
        Node* rightSibling = parent->values[i + 1];
        node->keys.push_back(parent->keys[i]);
        parent->keys[i] = rightSibling->keys[0];
        if (!node->leaf) {
            node->values.push_back(rightSibling->values[0]);
            rightSibling->values.erase(rightSibling->values.begin());
        }
    }

    
    void remove(int key) {
        Node* current = root;
        bool found = false;
        int i = 0;
        while (i < current->keys.size()) {
            if (key == current->keys[i]) {
                found = true;
                break;
            } else if (key < current->keys[i]) {
                break;
            }
            i += 1;
        }
        if (found) {
            if (current->leaf) {
                current->keys.erase(current->keys.begin() + i);
            } else {
                Node* pred = current->values[i];
                if (pred->keys.size() >= degree) {
                    int predKey = getMaxKey(pred);
                    current->keys[i] = predKey;
                    removeFromLeaf(predKey, pred);
                } else {
                    Node* succ = current->values[i + 1];
                    if (succ->keys.size() >= degree) {
                        int succKey = getMinKey(succ);
                        current->keys[i] = succKey;
                        removeFromLeaf(succKey, succ);
                    } else {
                        merge(current, i, pred, succ);
                        removeFromLeaf(key, pred);
                    }
                }

                if (current == root && current->keys.size() == 0) {
                    root = current->values[0];
                }
            }
        } else {
            if (current->leaf) {
                return;
            } else {
                if (current->values[i]->keys.size() < degree) {
                    if (i != 0 && current->values[i - 1]->keys.size() >= degree) {
                        stealFromLeft(current, i);
                    } else if (i != current->keys.size() && current->values[i + 1]->keys.size() >= degree) {
                        stealFromRight(current, i);
                    } else {
                        if (i == current->keys.size()) {
                            i -= 1;
                        }
                        merge(current, i, current->values[i], current->values[i + 1]);
                    }
                }

                remove(key);
            }
        }
    }

    void removeFromLeaf(int key, Node* leaf) {
        leaf->keys.erase(std::remove(leaf->keys.begin(), leaf->keys.end(), key), leaf->keys.end());

        if (leaf == root || leaf->keys.size() >= std::floor(degree / 2)) {
            return;
        }

        Node* parent = findParent(leaf);
        int i = std::distance(parent->values.begin(), std::find(parent->values.begin(), parent->values.end(), leaf));

        if (i > 0 && parent->values[i - 1]->keys.size() > std::floor(degree / 2)) {
            rotateRight(parent, i);
        } else if (i < parent->keys.size() && parent->values[i + 1]->keys.size() > std::floor(degree / 2)) {
            rotateLeft(parent, i);
        } else {
            if (i == parent->keys.size()) {
                i -= 1;
            }
            merge(parent, i, parent->values[i], parent->values[i + 1]);
        }
    }

    int getMinKey(Node* node) {
        while (!node->leaf) {
            node = node->values[0];
        }
        return node->keys[0];
    }

    int getMaxKey(Node* node) {
        while (!node->leaf) {
            node = node->values[node->values.size() - 1];
        }
        return node->keys[node->keys.size() - 1];
    }

    Node* findParent(Node* child) {
        Node* current = root;
        while (!current->leaf) {
            int i = 0;
            while (i < current->values.size()) {
                if (child == current->values[i]) {
                    return current;
                } else if (child->keys[0] < current->values[i]->keys[0]) {
                    break;
                }
                i += 1;
            }
            current = current->values[i];
        }
        return nullptr;
    }

    void merge(Node* parent, int index, Node* pred, Node* succ) {
        pred->keys.insert(pred->keys.end(), succ->keys.begin(), succ->keys.end());
        pred->values.insert(pred->values.end(), succ->values.begin(), succ->values.end());
        parent->values.erase(parent->values.begin() + index + 1);
        parent->keys.erase(parent->keys.begin() + index);

        if (parent == root && parent->keys.size() == 0) {
            root = pred;
        }
    }

    void rotateRight(Node* parent, int index) {
        Node* node = parent->values[index];
        Node* prev = parent->values[index - 1];
        node->keys.insert(node->keys.begin(), parent->keys[index - 1]);
        parent->keys[index - 1] = prev->keys[prev->keys.size() - 1];
        if (!node->leaf) {
            node->values.insert(node->values.begin(), prev->values[prev->values.size() - 1]);
            prev->values.pop_back();
        }
    }

    void rotateLeft(Node* parent, int index) {
        Node* node = parent->values[index];
        Node* next = parent->values[index + 1];
        node->keys.push_back(parent->keys[index]);
        parent->keys[index] = next->keys[0];
        if (!node->leaf) {
            node->values.push_back(next->values[0]);
            next->values.erase(next->values.begin());
        }
    }

    void printTree() {
        std::vector<Node*> currentLevel;
        currentLevel.push_back(root);

        while (!currentLevel.empty()) {
            std::vector<Node*> nextLevel;

            for (Node* node : currentLevel) {
                std::cout << "[";
                for (int i = 0; i < node->keys.size(); ++i) {
                    std::cout << node->keys[i];
                    if (i < node->keys.size() - 1) {
                        std::cout << ", ";
                    }
                }
                std::cout << "] ";

                if (!node->leaf) {
                    nextLevel.insert(nextLevel.end(), node->values.begin(), node->values.end());
                }
            }

            std::cout << std::endl;
            currentLevel = nextLevel;
        }
    }
};

int main() {
    // create a B+ tree with degree 3
    BPlusTree tree(3);

    // insert some keys
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);

    // print the tree
    tree.printTree(); // [4] [2, 3] [6, 7, 8, 9] [1] [5]

    // delete a key
    tree.remove(3);

    // print the tree
    tree.printTree(); // [4] [2] [6, 7, 8, 9] [1] [5]

    return 0;
}