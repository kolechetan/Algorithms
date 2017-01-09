#include<iostream>
#include "BST.h"

struct node* minNode( struct node* root )
{
    if( root->left == NULL )
        return root;

    return minNode( root->left );
}

struct node* inorderSucc( struct node* root, struct node* key)
{
    if( key->right != NULL )
        return minNode(key->right);
    
    struct node* tmp;
    while( root != NULL )
    {
        if( key->data < root->data )
        {
            tmp    = root;
            root =root->left;
        }
        else if( key->data > root->data)
            root = root->right;
        else
            break;
    }

    return tmp;
}

int main ()
{
    struct node *root = newNode(3); 
    root->left            = newNode(2);
    root->right          = newNode(4);
    root->right->right     = newNode(5);
    root->left->left   = newNode(1); 
    struct node* key =  root->right;;
    struct node* tmp = inorderSucc(root, key);  
    std::cout<<std::endl<<" Inorder successer is : "<<tmp->data<<std::endl;
    
    deleteTree(root);  
return 0;
}
