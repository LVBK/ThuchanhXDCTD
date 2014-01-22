#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
  char name[81];
  int count;
  char line[30];
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
void standardized(char s[])
{

  	char tmp[81];
  	int i;


  	for(i=1;i<strlen(s)-1;i++)
    	{

	      if(isupper(s[i])) s[i]=tolower(s[i]);
	      if((s[i]<'a'||s[i]>'z')&&(s[i]<'A'||s[i]>'Z')){
      		s[i]='\0';
      	}
      	}
		  
	
	if((s[strlen(s)-1]<'a'||s[strlen(s)-1]>'z')&&(s[strlen(s)-1]<'A'||s[strlen(s)-1]>'Z')) {s[strlen(s)-1]='\0';}
	if((s[0]<'a'||s[0]>'z')&&(s[0]<'A'||s[0]>'Z'))
	      for(i=0;i<strlen(s);i++) s[i]=s[i+1];
 	s[0]=tolower(s[0]);
}
treetype banword(treetype root){
	elementtype el;
	FILE *f;
	char s[81];
	if((f=fopen("stopw.txt","r"))==NULL){
		printf("Can not open stopw.txt.\n");
		exit(1);
	}
	while(!feof(f)){
		fscanf(f,"%s\n",el.name);
		el.count=0;
		InsertNode(el,&root);
	}
	fclose(f);
	return root;
}
char* itostr(int num){
  char buf[5];  
  sprintf(buf,"%d",num);
  char * buff=(char*)malloc((strlen(buf)+1)*sizeof(char));
  strcpy(buff,buf);
  return buff;
}
treetype Search(char *key,treetype root)
{
 if(root==NULL) return NULL;
 else if(strcmp(root->element.name,key)==0)
      return root;
     else if(strcmp(root->element.name,key)<0)
      return Search(key,root->right);
    else
      {
    return Search(key,root->left);
      }
}
treetype count(FILE *f,char name[],treetype root,treetype stopw)
{
  elementtype el;
  char s[255];
  char temp[81];
  char *part[30];
  int i;
  int line=0;
  if((f=fopen(name,"r"))==NULL)
    {printf("Can not open file %s.\n",name);
      exit(1);}
  while(fgets(s,255,f)!=NULL)
    {	
    	line++;
    	int size=parse(s,part);
    	for(i=0;i<size;i++){
      	el.count=1;if(i>0)strcpy(temp,part[i-1]);
      	if(i>0&&temp[strlen(temp)-1]!='.'&&isupper(part[i][0])){}
      	else{     	
  			strcpy(el.name,part[i]);
  		
			standardized(el.name);
			strcpy(el.line,",");
 			char*tmp=itostr(line);
 			strcpy(&el.line[1],tmp);
			if(strcmp(el.name,"\0")!=0&&(Search(el.name,stopw)==NULL))InsertNode(el,&root);
    }}}
  fclose(f);
	return root;
}


int parse(char*buff,char *part[])
{
  char*p;
  int i=0;
  p=strtok(buff," ");
  while(p!=NULL)
    {
      part[i++]=strdup(p);
      p=strtok(NULL," ");
    }
  return i;
}

int main()
{
  	FILE *f;
  	treetype root=NULL;
  	treetype stopw=NULL;
  	stopw=banword(stopw);
  	root=count(f,"vanban.txt",root,stopw);
	printftree(root);
  	freetree(root);
  	freetree(stopw);
	  int choose;
  	return 0;
}

