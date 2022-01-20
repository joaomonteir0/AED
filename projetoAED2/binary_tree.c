#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

typedef struct tree_node_s
{
    int data;                  // index 0 data item
    tree_node_s *left;  // left pointers (one for each index) ---- left means smaller
    tree_node_s* right; // right pointers (one for each index) --- right means larger
};

tree_node_s* GetNewNode(int data)
{
    tree_node_s* newNode = new tree_node_s();
    if(!NewNode){
        printf("memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

tree_node_s* tree_insert(tree_node_s *root, int data) // primeira função a ser feita
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    queue<tree_node_s*> q;
    q.push(root);
}

void main()
{
    struct tree_node_s *root = NULL; // store the adress of the root node
    tree_insert(&root, 15);
    tree_insert(&root, 25);
    tree_insert(&root, 35);
}