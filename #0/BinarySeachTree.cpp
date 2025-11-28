// Binary Search Tree(BST): It is a special type of binary tree that organize data so that searching, insertion, deletion can be done in a organized manner.
// Properties:
//   1.All keys in left subtree of a node are smaller than that node key.
//   2.All keys in the right subtree of a node are larger than that node key.
#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

class BST
{
    Node *root;

    Node *insert_rec(Node *root, int k)
    {
        if (root == NULL)
        {
            return new Node(k);
        }
        if (k < root->key)
        {
            root->left = insert_rec(root->left, k);
        }
        else
        {
            root->right = insert_rec(root->right, k);
        }
        return root;
    }

    int minValue(Node *root)
    {
        int minv = root->key;
        while (root->left != NULL)
        {
            minv = root->left->key;
            root = root->left;
        }
        return minv;
    }

    Node *del_rec(Node *root, int key)
    {
        if (root == NULL)
        {
            return root;
        }

        if (key < root->key)
        {
            root->left = del_rec(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = del_rec(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            {
                return root->right;
            }
            else if (root->right == NULL)
            {
                return root->left;
            }

            root->key = minValue(root->right);

            root->right = del_rec(root->right, root->key);
        }

        return root;
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int k)
    {
        root = insert_rec(root, k);
    }

    void del(int key)
    {
        root = del_rec(root, key);
    }

    void inorder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST obj;
    obj.insert(5);
    obj.insert(3);
    obj.insert(7);
    obj.insert(10);

    obj.display();
    return 0;
}
/*
      5
     / \
    3   7
         \
          10
*/