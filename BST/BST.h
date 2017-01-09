#include<iostream>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};


struct node* newNode( int data );
struct node* insert(struct node* root, int data);
void inorder(struct node* root);
void deleteTree( struct node* root);


