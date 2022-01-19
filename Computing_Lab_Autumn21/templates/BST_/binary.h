#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

typedef struct{
	
	int key;
}DATA;


typedef struct treeNode{
	DATA d;
	struct treeNode *leftChild, *rightChild;
	struct treeNode *parent; // This is optional
}NODE;

NODE *create(int x, NODE *par)
{
	NODE *tmp = (NODE *)malloc(sizeof(NODE));
	tmp->leftChild = NULL;
	tmp->rightChild = NULL;
	tmp->parent = par;
	tmp->d.key = x;
	return tmp;
}

void insert(int x, NODE **ptr)
{
	NODE *node = *ptr;
	if(node == NULL)
		*ptr = create(x, NULL);
	else if(x <= node->d.key)
	{
		if(node->leftChild)
			insert(x,&node->leftChild);
		else
			node->leftChild = create(x,node);
	}
	else
	{
		if(node->rightChild)
			insert(x,&node->rightChild);
		else
			node->rightChild = create(x,node);
	}
}


void inorder(NODE* root)
{
	if(root)
	{
		inorder(root->leftChild);
		printf("%d(%d) ", root->d.key, root->parent==NULL?-1:root->parent->d.key);
		inorder(root->rightChild);
	}
}


int minEle(NODE* node)
{
	if(node->leftChild)
		minEle(node->leftChild);
	else
		return node->d.key;
}

int maxHeight(NODE *node)
{
	if(node == NULL) return 0;
	return 1 + MAX(maxHeight(node->leftChild), maxHeight(node->rightChild));
}

void printGivenLevel(NODE* node,int level)
{
	if(node==NULL) return;
	else if (level == 1)
	    printf("%d(%d) ", node->d.key, node->parent==NULL?-1:node->parent->d.key);
	else
	    printGivenLevel(node->leftChild, level-1);
	    printGivenLevel(node->rightChild, level-1);
}

void printLevelOrder(NODE* root)
{
	int h = maxHeight(root);
	for(int i = 1;i<=h;i++)
		printGivenLevel(root, i), printf("\n");
}

void freeMem(NODE *root)
{
	if(root)
	{
		freeMem(root->leftChild);
		freeMem(root->rightChild);
		free(root);
	}
}