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


//
// the custom tree node structure
//
// we want to maintain three ordered trees (using the same nodes!), so we need three left and three right pointers
// so, when inserting a new node we need to do it three times (one for each index), so we will end upo with 3 three roots
//

typedef struct tree_node_s
{
  char name[MAX_NAME_SIZE + 1];                         // index 0 data item
  char zip_code[MAX_ZIP_CODE_SIZE + 1];                 // index 1 data item
  char telephone_number[MAX_TELEPHONE_NUMBER_SIZE + 1]; // index 2 data item
  struct tree_node_s *left[3];                          // left pointers (one for each index) ---- left means smaller
  struct tree_node_s *right[3];                         // right pointers (one for each index) --- right means larger
}
tree_node_t;


//
// the node comparison function (do not change this)
//

int compare_tree_nodes(tree_node_t *node1,tree_node_t *node2,int main_idx)
{
  int i,c;

  for(i = 0;i < 3;i++)
  {
    if(main_idx == 0)
      c = strcmp(node1->name,node2->name);
    else if(main_idx == 1)
      c = strcmp(node1->zip_code,node2->zip_code);
    else
      c = strcmp(node1->telephone_number,node2->telephone_number);
    if(c != 0)
      return c; // different on this index, so return
    main_idx = (main_idx == 2) ? 0 : main_idx + 1; // advance to the next index
  }
  return 0;
}


//
// tree insertion routine (place your code here)
//
/*
void tree_insert(tree_node_t ** tree, char *val)
{
  printf("ISTO É O VAL: %s \n", val);
  tree_node_t *temp = NULL;
    if(!(*tree))
    {
        temp = (tree_node_t *)malloc(sizeof(tree_node_t));
        temp->left[0] = temp->right[0] = NULL;
        temp->name[0] = *val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->name)
    {
        printf("<- inserting left: %s\n", val);
        tree_insert(&((*tree)->left[0]), val);

    }else{
        printf("-> inserting right: %s\n", val);
        tree_insert(&((*tree)->right[0]), val);
    }
}
*/
void tree_insert(tree_node_t ** tree, tree_node_t *val, int index){
  tree_node_t *temp = NULL;
  
  if(index == 0){
    if(!(*tree)){
      temp = (tree_node_t*)malloc(sizeof(tree_node_t));
      temp->left[0] = temp->right[0] = NULL;
      strcpy(temp->name, &val->name);
      *tree = temp;
      return;
    }
    int comp = strcmp(&(*tree)->name, &val->name);
    if(comp > 0){
      printf("%s < %s ==> vai para a esquerda %d \n",&val->name, &(*tree)->name,(strcmp(&(*tree)->name, &val->name)));
      tree_insert(&(*tree)->left[0], val, index);
      
    } if(comp < 0){
      printf("%s > %s ==> vai para a direita %d \n",&val->name, &(*tree)->name,(strcmp(&(*tree)->name, &val->name)));
      tree_insert(&(*tree)->right[0], val->name, index);
    }
  }
  if (index == 1)
  {
    if(!(*tree)){
      temp = (tree_node_t*)malloc(sizeof(tree_node_t));
      temp->left[1] = temp->right[1] = NULL;
      strcpy(temp->zip_code, &val->zip_code);
      *tree = temp;
      return;
    }
    int comp = strcmp(&(*tree)->zip_code, &val->zip_code);
    if(comp > 0){
      printf("%s < %s ==> vai para a esquerda %d \n",&val->zip_code, &(*tree)->zip_code,(strcmp(&(*tree)->zip_code, &val->zip_code)));
      tree_insert(&(*tree)->left[1], val, index);
      
    } if(comp < 0){
      printf("%s > %s ==> vai para a direita %d \n",&val->zip_code, &(*tree)->zip_code,(strcmp(&(*tree)->zip_code, &val->zip_code)));
      tree_insert(&(*tree)->right[1], val->zip_code, index);
    }
  }
  
  if (index == 2)
  {
    if(!(*tree)){
      temp = (tree_node_t*)malloc(sizeof(tree_node_t));
      temp->left[2] = temp->right[2] = NULL;
      strcpy(temp->telephone_number, &val->telephone_number);
      *tree = temp;
      return;
    }
    /*char phone[MAX_TELEPHONE_NUMBER_SIZE+1],phone_val[MAX_TELEPHONE_NUMBER_SIZE+1];
    strcpy(phone, &val->telephone_number);
    strcpy(phone_val, &(*tree)->telephone_number);
    int c = 0, j = 0, d = 0, f = 0;
    do{
      if(phone[c]!=' '){
        phone[j++]=phone[c];
      }
      if(phone_val[d]!=' '){
        phone_val[f++]=phone_val[d];
      }
      c++;
      d++;
    }while(phone[c]!='\0');
    phone[j]='\0';
    phone_val[f]='\0';

    //int comp = strcmp(&(*tree)->telephone_number, &val->telephone_number);
    //printf("comp: %d", comp);
    if(strcmp(phone, phone_val) < 0){
      printf("%s < %s ==> vai para a esquerda %d \n",&val->telephone_number, &(*tree)->telephone_number,(strcmp(&(*tree)->telephone_number, &val->telephone_number)));
      tree_insert(&(*tree)->left[2], val, index);
      
    } if(strcmp(phone, phone_val) > 0){
      printf("%s > %s ==> vai para a direita %d \n",&val->telephone_number, &(*tree)->telephone_number,(strcmp(&(*tree)->telephone_number, &val->telephone_number)));
      tree_insert(&(*tree)->right[2], val->telephone_number, index);
    }*/
    int comp = strcmp(&(*tree)->telephone_number, &val->telephone_number);
    if(comp > 0){
      tree_insert(&(*tree)->left[2], val, index);
      
    } if(compare_tree_nodes(*tree, val, index)){
      tree_insert(&(*tree)->right[2], val->telephone_number, index);
    }
  }
}

//
// tree search routine (place your code here)
//
/*
tree_node_t *find(tree_node_t ** tree, int val)
{
}
*/

//
// tree depdth
//
/*
int tree_depth( ... )
{
}
*/

//
// list, i,e, traverse the tree (place your code here)
//

int list(tree_node_t * tree)
{
  return 0;
}


//
// main program
//

int main(int argc,char **argv)
{
  double dt;

  // process the command line arguments
  if(argc < 3)
  {
    fprintf(stderr,"Usage: %s student_number number_of_persons [options ...]\n",argv[0]);
    fprintf(stderr,"Recognized options:\n");
    fprintf(stderr,"  -list[N]              # list the tree contents, sorted by key index N (the default is index 0)\n");
    // place a description of your own options here
    return 1;
  }
  int student_number = atoi(argv[1]);
  if(student_number < 1 || student_number >= 1000000)
  {
    fprintf(stderr,"Bad student number (%d) --- must be an integer belonging to [1,1000000{\n",student_number);
    return 1;
  }
  int n_persons = atoi(argv[2]);
  if(n_persons < 3 || n_persons > 10000000)
  {
    fprintf(stderr,"Bad number of persons (%d) --- must be an integer belonging to [3,10000000]\n",n_persons);
    return 1;
  }
  // generate all data
  tree_node_t *persons = (tree_node_t *)calloc((size_t)n_persons,sizeof(tree_node_t));
  if(persons == NULL)
  {
    fprintf(stderr,"Output memory!\n");
    return 1;
  }
  aed_srandom(student_number);
  for(int i = 0;i < n_persons;i++)
  {
    random_name(&(persons[i].name[0]));
    random_zip_code(&(persons[i].zip_code[0]));
    random_telephone_number(&(persons[i].telephone_number[0]));
    for(int j = 0;j < 3;j++)
      persons[i].left[j] = persons[i].right[j] = NULL; // make sure the pointers are initially NULL
  }

  // create the ordered binary trees
  dt = cpu_time();
  tree_node_t *roots[3]; // three indices, three roots
  for(int main_index = 0;main_index < 3;main_index++)
    roots[main_index] = NULL;
  for(int i = 0;i < n_persons;i++){
    for(int main_index = 0;main_index < 3;main_index++){
      tree_insert(&(roots[main_index]),&(persons[i]),main_index); // passar como argumento a root e a index em que está
    }
    printf("\n");
  }
  dt = cpu_time() - dt;
  printf("Tree creation time (%d persons): %.3es\n",n_persons,dt);
  /*
  // search the tree
  for(int main_index = 0;main_index < 3;main_index++)
  {
    dt = cpu_time();
    for(int i = 0;i < n_persons;i++)
    {
      tree_node_t n = persons[i]; // make a copy of the node data
      if(find( ... ) != &(persons[i])) // place your code here to find a given person, searching for it using the tree with number main_index
      {
        fprintf(stderr,"person %d not found using index %d\n",i,main_index);
        return 1;
      }
    }
    dt = cpu_time() - dt;
    printf("Tree search time (%d persons, index %d): %.3es\n",n_persons,main_index,dt);
  }
  */
  /*
  // compute the largest tree depdth
  for(int main_index = 0;main_index < 3;main_index++)
  {
    dt = cpu_time();
    //int depth = tree_depth( ... ); // place your code here to compute the depth of the tree with number main_index
    dt = cpu_time() - dt;
    printf("Tree depth for index %d: %d (done in %.3es)\n",main_index,depth,dt);
  }
  // process the command line optional arguments
  for(int i = 3;i < argc;i++)
  {
    if(strncmp(argv[i],"-list",5) == 0)
    { // list all (optional)
      int main_index = atoi(&(argv[i][5]));
      if(main_index < 0)
        main_index = 0;
      if(main_index > 2)
        main_index = 2;
      printf("List of persons:\n");
      (void)list( ... ); // place your code here to traverse, in order, the tree with number main_index
    }
    // place your own options here
  }
  // clean up --- don't forget to test your program with valgrind, we don't want any memory leaks
  */
  free(persons);
  return 0;
}
