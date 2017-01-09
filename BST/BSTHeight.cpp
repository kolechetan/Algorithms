#include<iostream>
#include "BST.h"
int Bstheight( struct node* root )
{
    if( root == NULL )
        return  0;
    int rh = Bstheight(root->right);
    int rl = Bstheight(root->left);

    return rh > rl ? rh + 1 : rl + 1;
}
int main ()
{
    struct node *root = newNode(3); 
    root->left            = newNode(2);
    root->right          = newNode(4);
    root->right->right     = newNode(5);
    root->left->left   = newNode(1); 

    std::cout<<std::endl<<" Height of the tree  is : "<< Bstheight(root)<<std::endl;
    
    deleteTree(root);  
return 0;
}
