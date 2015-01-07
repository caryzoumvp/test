#include <iostream>
using namespace std;

enum COLOR{RED, BLACK};
template <class T>
struct _rbtree_node {
    COLOR color;
	struct _rbtree_node  *parent;
	struct _rbtree_node *left;
	struct _rbtree_node *right;
	T value;

};
typedef struct _rbtree_node<int> rbtree_node;

class rbtree {
	rbtree_node *root;
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

int compare(int a, int  b) {
   return (a-b); 
}
void rbtree::insert_node(rbtree_node *node) {
	if (root == NULL) {
		return ;
	}

	rbtree_node *insert_pos = root;
	rbtree_node *next= root;

	while (next!= NULL) {	
		insert_pos = next;
		if (compare(next->value, node->value) > 0) {
			next = next->left;
		} else {
			next = next->right;
		}	
	}
	if (compare(insert_pos->value, node->value) > 0) {
		insert_pos->left = node;
	} else {
		insert_pos->right = node;
	}
	node->parent = insert_pos;
	insert_fixup(node);
}

void rbtree::insert_fixup(rbtree_node *node) {
    if (node == NULL || node->parent == NULL)
        return;
    if (node->parent->color == BLACK )
        return;

    rbtree_node *parent = node->parent;
    rbtree_node *gparent = node->parent->parent;
    if (node->parent->color == RED) {
        if (gparent->left == parent) {
            if (gparent->right->color == RED) {
                parent->color = BLACK;
                gparent->color = RED;
                gparent->right->color = BLACK;
                insert_fixup(gparent);
            } else {
                if (parent->left == node) {
                    gparent->color = RED;
                    parent->color = BLACK;
                    right_rotate(parent); 
                } else {
                    left_rotate(node);
                    insert_fixup(parent);
                }
            }
        } else {
            if (gparent->left->color == RED) {
                parent->color = BLACK;
                gparent->right->color = BLACK;
                gparent->color = RED;
                insert_fixup(parent);  
            } else {
                if (parent->left == node) {
                    right_rotate(node);
                    insert_fixup(parent);
                } else {
                    gparent->color = RED;
                    parent->color = BLACK;
                    left_rotate(parent);
                }
            }
        }
    }
}

void rbtree::delete_node(rbtree_node *node) {
    if (node == NULL )
        return;
    
    bool needfixup = false;
    rbtree_node *reminder = node;
    if (node->left == NULL ) {
        parent = node->parent;
        child = node->right;    
        if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
        child->parent = parent;
        child->color = node->color;
    } else {
        rbtree_node *child = node->right;
        if (child == NULL) {
            rbtree_node *parent = node->parent;
            child = node->left;    
            if (parent->left == node)
                parent->left = child;
            else
                parent->right = child;
            child->parent = parent;
            child->color = node->color;
        } else {
            child = child->left;
            while(child->left != NULL)
                child = child->left;
            parent = child->parent;
            if (parent->left == child)
                parent->left = NULL;
            else 
                parent->right = NULL;
            if (parent->left == reminder)
                parent->left = child;
            else 
                parent->right = child;
            child->parent = reminder->parent;
            child->left = reminder->left;
            child->right = reminder->right;
            if (child->color == BLACK) {
                delete_fixup(child);
            }
            child->color = reminder->color;
        }
    }
    free(reminder);
}

void rbtree::delete_fixup(rbtree_node *node) {
    
}

int main() 
{
    return 0; 
}
