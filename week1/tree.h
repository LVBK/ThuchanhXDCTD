#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct
{
  char name[81];
  int count;
  char line[20000];
}data;

typedef data elementtype;
typedef struct node
{
  elementtype element;
  struct node *left,*right;
}node;
typedef struct node *treetype;

void printftree(treetype tree)
{
  if(tree!=NULL)
    {
      printftree(tree->left);
 printf("%s %d%s\n",tree->element.name,tree->element.count,tree->element.line);
      printftree(tree->right);
     
    }
}

void freetree(treetype tree)
{
        if (tree!=NULL)
        {
                freetree(tree->left);
                freetree(tree->right);
                free((void*) tree);
        }
}

void InsertNode(elementtype element,treetype *root)
{
if (*root == NULL){
  *root=(node*)malloc(sizeof(node)); 
  (*root)->element = element;
  (*root)->left = NULL; 
  (*root)->right = NULL; 
 }
 else if (strcmp(element.name,(*root)->element.name)==0) {(*root)->element.count++;
 strcpy(&(*root)->element.line[strlen((*root)->element.line)],element.line);
}
 else if (strcmp(element.name,(*root)->element.name)<0) InsertNode(element, &(*root)->left);
 else if (strcmp(element.name,(*root)->element.name)>0) InsertNode(element, &(*root)->right); 
}


