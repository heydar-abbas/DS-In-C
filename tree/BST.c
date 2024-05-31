#include "BST.h"

void main(void)
{
    // Initialize the root node
    BinaryTreeNode *root = NULL;

    // Insert nodes into the binary search tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Search for a node with key 60
    if (searchNode(root, 60) != NULL)
    {
        printf("60 found\n\n");
    }
    else
    {
        printf("60 not found\n\n");
    }

    // Perform post-order traversal
    printf("post-order traversal\n");
    postOrder(root);
    printf("\n\n");

    // Perform pre-order traversal
    printf("pre-order traversal\n");
    preOrder(root);
    printf("\n\n");

    // Perform in-order traversal
    printf("in-order traversal\n");
    inOrder(root);
    printf("\n\n");

    // Perform delete the node (70)
    BinaryTreeNode *temp = deleteNode(root, 70);
    printf("After Delete: \n");
    inOrder(root);

    free(root);
    free(temp);
}

// Function to create a new node with a given value
BinaryTreeNode *newNodeCreate(int value)
{
    BinaryTreeNode *temp = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to search for a node with a specific key in the tree
BinaryTreeNode *searchNode(BinaryTreeNode *root, int target)
{
    if (root == NULL || root->key == target)
    {
        return root;
    }
    if (root->key < target)
    {
        return searchNode(root->right, target);
    }
    return searchNode(root->left, target);
}

// Function to insert a node with a specific value in the tree
BinaryTreeNode *insertNode(BinaryTreeNode *node, int value)
{
    if (node == NULL)
    {
        return newNodeCreate(value);
    }
    if (value < node->key)
    {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->key)
    {
        node->right = insertNode(node->right, value);
    }
    return node;
}

// Function to perform post-order traversal
void postOrder(BinaryTreeNode *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}

// Function to perform in-order traversal
void inOrder(BinaryTreeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}

// Function to perform pre-order traversal
void preOrder(BinaryTreeNode *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to find the minimum value
BinaryTreeNode *findMin(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left != NULL)
    {
        return findMin(root->left);
    }
    return root;
}

// Function to delete a node from the tree
BinaryTreeNode *deleteNode(BinaryTreeNode *root, int x)
{
    if (root == NULL)
        return NULL;

    if (x > root->key)
    {
        root->right = deleteNode(root->right, x);
    }
    else if (x < root->key)
    {
        root->left = deleteNode(root->left, x);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL)
        {
            BinaryTreeNode *temp;
            if (root->left == NULL)
            {
                temp = root->right;
            }
            else
            {
                temp = root->left;
            }
            free(root);
            return temp;
        }
        else
        {
            BinaryTreeNode *temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}
