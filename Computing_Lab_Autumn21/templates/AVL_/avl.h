#if !defined(__G_AVL_TREE__)
#define __G_AVL_TREE__

typedef struct AVL_Tree_Node{
	int key;
	struct AVL_Tree_Node *left;
	struct AVL_Tree_Node *right;
	int height;
    // assumption , leaf node is of height 1 and root height = height of the tree
}AVL_Tree_Node;

int avl_tree_height(AVL_Tree_Node *N);
// returns the height of the AVL_Tree_Node N supplied
int avl_tree_height_difference(AVL_Tree_Node *N);
// returns the height difference between the left and right childern of the AVL_Tree_Node N

AVL_Tree_Node *avl_tree_init_new_node(int value);
// returns the new node with key = value
AVL_Tree_Node *avl_tree_right_rotate(AVL_Tree_Node *y);
// right rotate to help maintain the avl property
AVL_Tree_Node *avl_tree_left_rotate(AVL_Tree_Node *x);
// left rotate to help maintain the avl property
AVL_Tree_Node *avl_tree_insert(AVL_Tree_Node* root, int key);
// insert the key in the tree defined under AVL_Tree_Node root at appropritate position and returns the new node where it was inserted


#endif // __G_AVL_TREE__
