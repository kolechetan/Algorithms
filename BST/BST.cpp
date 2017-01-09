#include "BST.h"

struct node* newNode( int data )
{

    struct node *tmp = (struct node*)malloc(sizeof(node));

    tmp->data = data;
    tmp->left = tmp->right = NULL;

    return tmp;
}

struct node* insert(struct node* root, int data)
{

    if(root == NULL)
        return newNode( data );
    else
    {   struct node* tmp;
        if( data >= root->data )
        {  
            tmp = insert( root, data );
            root->right = tmp;
        
        }
        else
        {   
            tmp = insert( root, data );
            root->left = tmp;
        }
    }
    return root;
}

void inorder(struct node* root)
{

    if(root  == NULL)
        return;
    else
    {
        inorder(root->left);
        std::cout<<root->data;
        inorder(root->right);
    }
}
void deleteTree( struct node* root)
{
    if( root == NULL)
        return;
    else
    {
        deleteTree(root->left);
        deleteTree(root->right);
     	std::cout<<"deleting node - > "<<root->data<<std::endl;  
		free(root);
    }
}


