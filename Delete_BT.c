/*  Delete all nodes of a binary tree one by one. */

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
};

struct node* root=NULL;

struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}



int main()
{
    root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);   
    print_BT(root);
    delete_BT(root);
    print_BT(root);

    return 0;
}