#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY_NODE -1 
#define CURR_RIGHT btree->array[curr]->right
#define CURR_LEFT btree->array[curr]->left

//-----------------------------------------------------------------------------------//
//*****************************Array Implementation**********************************//
//-----------------------------------------------------------------------------------//

typedef struct{
	void *data;
	int left, right, parent;
}NODE;

typedef struct{
	int max_ele, free;
	size_t datasize;
	void (*dataPrint)(void *);
	NODE **array;
}BTREE;

void initTree(BTREE *btree, size_t datasize, void (*dataPrint)(void *));

NODE *createNode(BTREE *btree, void *d, int left, int right);

void insert(BTREE *btree, void *d, int left, int right);

void displayTable(BTREE *btree);

void inorder(BTREE *btree, int i);

void preorder(BTREE *btree, int i);

void postorder(BTREE *btree, int i);

void inorder_iterative(BTREE *btree);

void preorder_iteratice(BTREE *btree);

void postorder_iterative(BTREE *btree); //Using 2 stacks

void postorder_iterative_single_stack(BTREE *btree); //Using 1 stack