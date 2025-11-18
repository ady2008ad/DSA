//Binary Tree
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
    void preorder(Node *root)
    { // Root->Left->Right
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(Node *root)
    { // Left->Root->Right
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void postorder(Node *root)
    { // Left->Right->Root
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    void deletDeepest(Node *root, Node *dNode)
    {
        queue<Node *> q;
        q.push(root);

        Node *curr;
        while (!q.empty())
        {
            curr = q.front();
            q.pop();

            if (curr == dNode)
            {
                curr = nullptr;
                delete (dNode);
                return;
            }

            if (curr->right)
            {

                if (curr->right == dNode)
                {
                    curr->right = nullptr;
                    delete (dNode);
                    return;
                }
                q.push(curr->right);
            }

            if (curr->left)
            {

                if (curr->left == dNode)
                {
                    curr->left = nullptr;
                    delete (dNode);
                    return;
                }
                q.push(curr->left);
            }
        }
    }

    Node *deletion(Node *root, int key)
    {

        if (root == nullptr)
            return nullptr;

        if (root->left == nullptr && root->right == nullptr)
        {

            if (root->data == key)
                return nullptr;
            else
                return root;
        }

        queue<Node *> q;
        q.push(root);

        Node *curr;
        Node *keyNode = nullptr;

        while (!q.empty())
        {
            curr = q.front();
            q.pop();

            if (curr->data == key)
                keyNode = curr;

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        if (keyNode != nullptr)
        {

            int x = curr->data;

            keyNode->data = x;

            deletDeepest(root, curr);
        }
        return root;
    }
};
int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(10);
    cout << "Inorder traversing: ";
    root->inorder(root);
    cout << endl;
    cout << "Preorder traversing: ";
    root->preorder(root);
    cout << endl;
    cout << "Postorder traversing: ";
    root->postorder(root);
    cout << endl;
    root->deletion(root,3);
    cout << "Postorder traversing: ";
    root->postorder(root);
    cout<<endl;
    return 0;
}
/*
        5
       / \
      3   7
     /
    10
*/