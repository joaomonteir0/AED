//
// AED, January 2022
//
// Solution of the second practical assignement (multi-ordered tree)
//
// Place your student numbers and names here
// 102690 - João Pedro Ferreira Monteiro
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AED_2021_A02.h"

typedef struct node
{
    char value[MAX_NAME_SIZE + 1];
    struct node *left_child, *right_child;
} node;

struct node *new_node(char value)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    strcpy(tmp->value, value);
    tmp->left_child = tmp->right_child = NULL;
    return tmp;
}

void print(struct node *root_node) // displaying the nodes!
{
    if (root_node != NULL)
    {
        print(root_node->left_child);
        printf("%s \n", root_node->value);
        print(root_node->right_child);
    }
}

struct node* insert_node(struct node* node, char value) // inserting nodes!
{
    if (!(node)) return new_node(value);
    if (strcmp(node->value , value) <= 0)
    {
        node->left_child = insert_node(node->left_child, value);
    }
    else if (strcmp(node->value , value) > 0)
    {
        node->right_child = insert_node(node->right_child, value);
    }
    return node;
}

int main()
{
    struct node *root_node = NULL;
    root_node = insert_node(root_node, "a");
    //insert_node(root_node, "dsad");
    //print(root_node);
    return 0;
}