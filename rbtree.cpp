#include <iostream>
using namespace std;

template <class T>
struct _rbtree_node {
	enum color {RED, BLACK};
	struct _rbtree_node  *parent;
	struct _rbtree_node *left;
	struct _rbtree_node *right;
	T node;

};
typedef struct _rbtree_node rbtree_node;

class rbtree {
	rb_tree_node *root;
	void left_rotate(rbtree_node *node);
	void right_rotate(rbtree_node *node);
	void insert_node(rbtree_node *node);
	void delete_node(rbtree_node *node);
	void insert_fixup(rbtree_node *node);
};


void rbtree::left_rotate(rbtree_node *node) {
	if (node == NULL || node->right== NULL)
		return ;
	rbtree_node *right = node->right; 
	rbtree_node *parent = node->parent;
	if (parent != NULL) {
		if (parent->left == node) {
			parent->left = right;
			right->parent = parent;
		} else if (parent->right == node) {
			parent->right = right;
			right->parent = parent;
		} else {
			return ;
		}
	} else {
		right->parent = NULL;
	}
	node->right = right->left;
	right->left = node;	
	node->parent = right;
}

void rbtree::right_rotate(rbtree_node *node) {
	if (node == NULL || node->left== NULL)
		return ;
	rbtree_node *left= node->left; 
	rbtree_node *parent = node->parent;
	if (parent != NULL) {
		if (parent->left == node) {
			parent->left = left;
			left->parent = parent;
		} else if (parent->right == node) {
			parent->right = left;
			left->parent = left;
		} else {
			return ;
		}
	} else {
		left->parent = NULL;
	}
	node->left= left->right;
	left->right= node;	
	node->parent = left;
}


void rbtree::insert_node(rbtree_node *node) {
	if (root == NULL) {
		return ;
	}

	rbtree_node *insert_pos = root;
	rbtree_node *next= root;

	while (next!= NULL) {	
		insert_pos = next;
		if (compare(next, node) > 0) {
			next = next->left;
		} else {
			next = next->right;
		}	
	}
	if (compare(insert_pos, node) > 0) {
		insert_pos->left = node;
	} else {
		insert_pos->right = node;
	}
	node->parent = insert_pos;
	insert_fixup(node);
}

void rbtree::insert_fixup(rbtree_node *node) {
		

}

void rbtree::delete_node(rbtree_node *node) {
	
}
