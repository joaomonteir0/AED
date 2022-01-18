#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node_s
{
    int data;                  // index 0 data item
    struct tree_node_s *left;  // left pointers (one for each index) ---- left means smaller
    struct tree_node_s *right; // right pointers (one for each index) --- right means larger
} tree_node_t;

struct tree_node_s GetNewNode(int val)
{
    struct tree_node_s *newNode;
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return *newNode;
}

void tree_insert(struct tree_node_s **root, int val) // primeira função a ser feita
{
    if (*root == NULL)
    {
        *root = GetNewNode(val);
    }
    int buceta;
    if (buceta == 0)
    {
        cona;
    }
}

void main()
{
    struct tree_node_s *root = NULL; // store the adress of the root node
    tree_insert(&root, 15);
    tree_insert(&root, 25);
    tree_insert(&root, 35);
}