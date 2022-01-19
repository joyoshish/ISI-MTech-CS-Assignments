#include "justBinaryTree.h"
#include "stack.h"

void initTree(BTREE *btree, size_t datasize, void (*dataPrint)(void *))
{
	btree->dataPrint = dataPrint;
	btree->max_ele = 10;
	btree->free = 0;
	btree->datasize = datasize;
	btree->array = malloc(btree->max_ele * sizeof(NODE *));
}

NODE *createNode(BTREE *btree, void *d, int left, int right)
{
	NODE *tmp = malloc(sizeof(NODE));
	
	tmp->data = malloc(btree->datasize);
	memcpy(tmp->data, d, btree->datasize);

	tmp->left = left; tmp->right = right;
	return tmp;
}

void insert(BTREE *btree, void *d, int left, int right)
{
	if(btree->free == btree->max_ele - 1)
	{
		btree->max_ele *= 2;
		btree->array = realloc(btree->array, btree->max_ele * sizeof(NODE *));
	}
	btree->array[btree->free] = createNode(btree, d, left, right);
	btree->free++;
}


void displayTable(BTREE *btree)
{
	printf("i\tdata\tleft\tright\n");
	for(int i=0; i<btree->free; i++)
	{		
		printf("%d\t", i);
		NODE *node = btree->array[i];	
		void *data = node->data;
		btree->dataPrint(data);
		printf("\t%d\t%d\n", node->left, node->right);
	}
}

void inorder(BTREE *btree, int i)
{
	if(i != EMPTY_NODE)
	{
		inorder(btree, btree->array[i]->left);
		btree->dataPrint(btree->array[i]->data);
		inorder(btree, btree->array[i]->right);
	}
}

void preorder(BTREE *btree, int i)
{
	if(i != EMPTY_NODE)
	{
		btree->dataPrint(btree->array[i]->data);
		preorder(btree, btree->array[i]->left);
		preorder(btree, btree->array[i]->right);
	}
}

void postorder(BTREE *btree, int i)
{
	if(i != EMPTY_NODE)
	{
		postorder(btree, btree->array[i]->left);
		postorder(btree, btree->array[i]->right);
		btree->dataPrint(btree->array[i]->data);
	}
}


void inorder_iterative(BTREE *btree)
{
	STACK s;
	initStack(&s, sizeof(int));
	int curr = 0;
	while (curr != -1 || s.num_elements != 0) 
    { 
        /* Reach the left most Node of the 
           curr Node */
        while (curr !=  -1) 
        {
            push(&s, &curr); 
            curr = CURR_LEFT;
        } 
  
        /* Current must be NULL at this point */
       	pop(&s, &curr);
	  	btree->dataPrint(btree->array[curr]->data);

        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
		curr = CURR_RIGHT;
  
    }
}

void preorder_iteratice(BTREE *btree) 
{
	// Base Case 
    
    STACK s;
	initStack(&s, sizeof(int));
	int curr = 0;
    push(&s, &curr); 
  
    /* Pop all items one by one. Do following for every popped item 
       a) print it 
       b) push its right child 
       c) push its left child 
    Note that right child is pushed first so that left is processed first */
    while (s.num_elements != 0) 
    { 
        // Pop the top item from stack and print it 
        pop(&s, &curr);
	  	btree->dataPrint(btree->array[curr]->data);
  
        // Push right and left children of the popped node to stack 
        if (CURR_RIGHT != -1) 
        {
            int tmp = CURR_RIGHT;
            push(&s, &tmp);
         } 
        if (CURR_LEFT != -1)
        { 
            int tmp = CURR_LEFT;
            push(&s, &tmp); 
        }
    } 
}


void postorder_iterative(BTREE *btree) //Using 2 stacks
{
	//Base Case
  
    // Create two stacks 
     STACK s, s2; 
     initStack(&s, sizeof(int));
     initStack(&s2, sizeof(int));
  
    // push root to first stack
    int curr = 0; 
    push(&s, &curr);
  
    // Run while first stack is not empty 
    
    
    while (s.num_elements != 0) 

    { 
        // Pop an item from s and push it to s2 
        pop(&s, &curr);
        push(&s2, &curr);

        // Push left and right children 
        // of removed item to s
        
        if (CURR_LEFT != -1)
        { 
            int tmp = CURR_LEFT;
            push(&s, &tmp); 
        }
        if (CURR_RIGHT != -1) 
        {
            int tmp = CURR_RIGHT;
            push(&s, &tmp);
         }
    } 
  
    // Print all elements of second stack 
    while (s2.num_elements != 0) 
    { 
        pop(&s2, &curr);
        btree->dataPrint(btree->array[curr]->data);
    } 
}


void postorder_iterative_single_stack(BTREE *btree)// Not DOne Properly
{
    // Base Case
      
    STACK s; 
    initStack(&s, sizeof(int));
    int curr = 0; 
    do
    { 
        // Move to leftmost node 
        while (curr != -1) 
        { 
            // Push root's right child and then root to stack. 
           
            if (CURR_RIGHT != -1)
            { 
                int tmp = CURR_RIGHT;
                push(&s, &tmp); 
            }
            push(&s, &curr); 
  
            // Set root as root's left child   
            curr = CURR_LEFT; 
        } 
  
        // Pop an item from stack and set it as root     
        pop(&s, &curr);
  
        // If the popped item has a right child and the right child is not 
        // processed yet, then make sure right child is processed before root 
        int tmp; peek(&s, &tmp);
        if (CURR_RIGHT != -1 && tmp == CURR_RIGHT) 
        { 
                        
            pop(&s, &tmp);  
            push(&s, &curr); // push root back to stack 
            curr = CURR_RIGHT; // change root so that the right  
                                // child is processed next 
        } 
        else  // Else print root's data and set root as NULL 
        { 
            btree->dataPrint(btree->array[curr]->data);
            curr = -1;
        } 
    } while (s.num_elements != 0);
}