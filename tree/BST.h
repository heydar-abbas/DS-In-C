// C program to implement binary search tree
#include <stdio.h>
#include <stdlib.h>

#ifndef _INC_BST
#define _INC_BST

// Define a structure for a binary tree node
typedef struct binary_tree_node
{
    int key;
    struct binary_tree_node *left, *right;
} BinaryTreeNode;

// Function to create a new node with a given value
BinaryTreeNode *newNodeCreate(int);
// Function to search for a node with a specific key in the tree
BinaryTreeNode *searchNode(BinaryTreeNode *, int);
// Function to insert a node with a specific value in the tree
BinaryTreeNode *insertNode(BinaryTreeNode *, int);
// Function to find the minimum value
BinaryTreeNode *findMin(BinaryTreeNode *);
// Function to delete a node from the tree
BinaryTreeNode *deleteNode(BinaryTreeNode *, int);
// Function to perform post-order traversal
void postOrder(BinaryTreeNode *);
// Function to perform in-order traversal
void inOrder(BinaryTreeNode *);
// Function to perform pre-order traversal
void preOrder(BinaryTreeNode *);

#endif
