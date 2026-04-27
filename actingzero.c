//slip :- 4
//Q1) Write a C program to find the height of the tree and check 
//whether given tree is balanced or not.

#include<stdio.h>
#include<stdlib.h>

// Structure of Tree Node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Create new node
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Find height of tree
int height(struct node* root)
{
    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Check if tree is balanced
int isBalanced(struct node* root)
{
    if(root == NULL)
        return 1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int diff = leftHeight - rightHeight;
    if(diff < 0)
        diff = -diff;

    if(diff <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}

// Main
int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Height of tree = %d\n", height(root));

    if(isBalanced(root))
        printf("Tree is Balanced\n");
    else
        printf("Tree is NOT Balanced\n");

    return 0;
}