#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

int comparator(void*, void*);
void printData(void*, void*);
size_t element_size;


typedef struct node{
	void *data;
	struct node *left, *right, *parent;
}NODE;


NODE *create(void *d, NODE *par)
{
	NODE *tmp = malloc(sizeof(NODE));
	tmp->data = d;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = par;
	return tmp;
}


void insert(NODE *root, void *d)
{
	if(comparator(root->data, d) > 0)
 		if(root->left == NULL) root->left = create(d, root);
 		else insert(root->left, d);
	else
		if(root->right == NULL) root->right = create(d, root);
		else insert(root->right, d);
}

void insertMain(NODE **root, void *d)
{
	if(NULL == (*root))
	{
		*root = create(d, NULL);
		(*root)->parent = *root;
	}
	else
		insert(*root,d);
}

void inorder(NODE *root)
{
	if(root)
	{
		inorder(root->left);
		printData(root->data, root->parent->data);
		inorder(root->right);
	}
}

NODE *search(NODE *root, void *x)
{
	if(root)
	{
		if(comparator(root->data, x) == 0)
			return root;
		else if(comparator(root->data, x) > 0)
			search(root->left, x);
		else
			search(root->right, x);
	}
	else
	{
		printf("NOT FOUND");
		return NULL;
	}
}


void Delete(NODE *root, void *x)
{
	NODE *tmp = search(root, x);
	if(tmp == NULL)
	{
		printf("NOT FOUND");
		return;
	}
	else
	{
		if(NULL == tmp->left && NULL != tmp->right)//Only right
		{
			tmp->right->parent = tmp->parent;
			if(comparator(tmp->parent->right->data, tmp->data) == 0) tmp->parent->right = tmp->right;
			else tmp->parent->left = tmp->right;
		}
		else if(NULL != tmp->left && NULL == tmp->right)//Only left
		{
			tmp->left->parent = tmp->parent;
			if(comparator(tmp->parent->right->data, tmp->data) == 0) tmp->parent->right = tmp->left;
			else tmp->parent->left = tmp->left;
		}
		else if(NULL == tmp->left && NULL == tmp->right)// Leaf
		{
			if(comparator(tmp->parent->right->data, tmp->data) == 0) tmp->parent->right = NULL;
			else tmp->parent->left = NULL;
		}
		else // 2 children
		{
			NODE  *t2 = tmp->right;
			while(t2->left != NULL) t2 = t2->left; //inorder succesor
			memcpy(tmp->data, t2->data, element_size);
			t2->parent->left = NULL;
			tmp = t2;
		}
		free(tmp);
	}
}


int maxHeight(NODE *root)
{
	if(root == NULL) return 0;
	return 1 + MAX(maxHeight(root->left), maxHeight(root->right));
}
void printGivenLevel(NODE* root,int level)
{
	if(root==NULL) return;
	else if (level == 1)
	    printData(root->data, root->parent->data);
	else
	    printGivenLevel(root->left, level-1);
	    printGivenLevel(root->right, level-1);
}

void printLevelOrder(NODE* root)
{
	int h = maxHeight(root);
	for(int i = 1;i<=h;i++)
		printGivenLevel(root, i), printf("\n");
}