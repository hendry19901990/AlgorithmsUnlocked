#include <iostream>
#include <vector>
 
using namespace std;
 
 
struct TNode {
    int color;      // 0 - black, 1 - red, 2 - double-black;
    bool is_nil;    // Is nil?
    int val;        // Node's value.
    TNode *left;    // Left sub-tree.
    TNode *right;   // Right sub-tree.
    TNode *parent;  // Parent of the node.
};
class RBtree {
    private:
        TNode *root;
 
        TNode *new_node(int);
        void set_node(TNode *, TNode *);
        void check_nil(TNode *&);
       
        int get_color(TNode *);
        void set_color(TNode *&, int);
 
        TNode *_find(TNode *, int);
        TNode *_find_least(TNode *);
        void rotate_left(TNode *);
        void rotate_right(TNode *);
 
        void _insert(int, TNode *&, TNode *);
        void insert_fix(TNode *);
 
        void _remove(TNode *&);
        void remove_fix(TNode *);
 
    public:
        RBtree() {
            root = nullptr;
        }
 
        TNode *find(int);
        void insert(int);
        void remove(int);
        void print(TNode *root=nullptr, int offset=0);
};
 
// Private functions {
TNode *RBtree::new_node(int val) {
    TNode *node = new TNode({1, 0, val, nullptr, nullptr, nullptr});
    return node;
}
void RBtree::set_node(TNode *node, TNode *new_node) {
    if (new_node != nullptr) {
        new_node->parent = node->parent;
    }
    if (node->parent != nullptr) {
        if (node == node->parent->left) {
            node->parent->left = new_node;
        } else {
            node->parent->right = new_node;
        }
    } else {
        this->root = new_node;
    }
}
void RBtree::check_nil(TNode *&node) {
    if (node->is_nil) {
        if (node->parent != nullptr) {
            if (node == node->parent->left) {
                node->parent->left = nullptr;
            } else {
                node->parent->right = nullptr;
            }
        } else {
            this->root = nullptr;
        }
        free(node);
    }
}
 
int RBtree::get_color(TNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return node->color;
}
void RBtree::set_color(TNode *&node, int color) {
    if (node != nullptr) {
        node->color = color;
    }
}
 
TNode *RBtree::_find(TNode *root, int val) {
    if (root == nullptr) {
        return nullptr;
    } else if (val == root->val) {
        return root;
    } else if (val < root->val) {
        return _find(root->left, val);
    } else {
        return _find(root->right, val);
    }
}
TNode *RBtree::_find_least(TNode *root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}
void RBtree::rotate_left(TNode *prev_root) {
    TNode *new_root = prev_root->right;  
 
    prev_root->right = new_root->left;  
    if (new_root->left != nullptr) {
        new_root->left->parent = prev_root;
    }
    new_root->parent = prev_root->parent;
 
    if (prev_root->parent == nullptr) {
        this->root = new_root;
    } else if (prev_root == prev_root->parent->left) {
        prev_root->parent->left = new_root;
    } else {
        prev_root->parent->right = new_root;
    }
 
    new_root->left = prev_root;
    prev_root->parent = new_root;
}
void RBtree::rotate_right(TNode *prev_root) {
    TNode *new_root = prev_root->left;
 
    prev_root->left = new_root->right;
    if (new_root->right != nullptr) {
        new_root->right->parent = prev_root;
    }
    new_root->parent = prev_root->parent;
 
    if (prev_root->parent == nullptr) {
        this->root = new_root;
    } else if (prev_root == prev_root->parent->left) {
        prev_root->parent->left = new_root;
    } else {
        prev_root->parent->right = new_root;
    }
 
    new_root->right = prev_root;
    prev_root->parent = new_root;
}
 
void RBtree::_insert(int val, TNode *&root, TNode *parent) {
    if (root == nullptr) {
        root = new_node(val);
        root->parent = parent;
        insert_fix(root);
        return;
    }
    if (val < root->val) {
        _insert(val, root->left, root);
    } else if (val > root->val) {
        _insert(val, root->right, root);
    }
}
void RBtree::insert_fix(TNode *root) {
    // Case 0. Root is always black.
    // Case 1. Root's uncle is red.
    // Case 2. Root's uncle is black, triangle.
    // Case 3. Root's uncle is black, line.
 
    while (root && get_color(root->parent) == 1) {  // While parent is RED.
        // Root's parent is on the left side.
        if (root->parent == root->parent->parent->left) {
            TNode *uncle = root->parent->parent->right;
            if (get_color(uncle) == 1) {             // Case 1. Uncle is RED.
                set_color(root->parent, 0);          // Case 1. Recolor parent.
                set_color(uncle, 0);                 // Case 1. Recolor uncle.
                set_color(root->parent->parent, 1);  // Case 1. Recolor granp.
                // Continue from grandparent, if exists.
                root = root->parent ? root->parent->parent : nullptr;
            } else {
                if (root == root->parent->right) {   // Case 2. Triangle.
                    root = root->parent;             // Case 2.
                    rotate_left(root);               // Case 2.
                }
                set_color(root->parent, 0);          // Case 3. Line.
                set_color(root->parent->parent, 1);  // Case 3.
                rotate_right(root->parent->parent);  // Case 3. Rotate granp.
            }
        }
        // Root's parent is on the right side.
        else {  
            TNode *uncle = root->parent->parent->left;
            if (get_color(uncle) == 1) {             // Case 1. Uncle is RED.
                set_color(root->parent, 0);          // Case 1. Recolor parent.
                set_color(uncle, 0);                 // Case 1. Recolor uncle.
                set_color(root->parent->parent, 1);  // Case 1. Recolor granp.
                // Continue from grandparent, if exists.
                root = root->parent ? root->parent->parent : nullptr;
            } else {
                if (root == root->parent->left) {    // Case 2. Triangle.
                    root = root->parent;             // Case 2.
                    rotate_right(root);              // Case 2.
                }
                set_color(root->parent, 0);          // Case 3. Line.
                set_color(root->parent->parent, 1);  // Case 3.
                rotate_left(root->parent->parent);   // Case 3. Rotate granp.
            }
        }
    }
    set_color(this->root, 0);
}
 
void RBtree::_remove(TNode *&root) {
    if (root->left && root->right) {                 // Both children
        TNode *successor = _find_least(root->right);
        root->val = successor->val;
        _remove(successor);
    }
    else if (!root->left && !root->right) {          // Leaf
        if (get_color(root) == 1) {                  // Root is red
            set_node(root, nullptr);
            free(root);
        } else {                                     // Root is black
            root->is_nil = 1;
            root->color = 2;
            remove_fix(root);
        }
    }
    else if (root->left || root->right) {            // One child.
        TNode *child;
        if (root->left) {                            // Left child.
            child = root->left;
        } else {                                     // Right child.
            child = root->right;
        }
 
        set_node(root, child);
        // Either root or it's child is red.
        if (get_color(root) == 1 or get_color(child) == 1) {
            set_color(child, 0);
            free(root);
        }
        // Both root and it's child are black.
        else {
            set_color(child, 2);
            remove_fix(child);
        }
    }
}
void RBtree::remove_fix(TNode *node) {
    while (true) {
        // Case 0. TERMINAL. Node is tree's root.
        if (node->parent == nullptr) {
            set_color(node, 0);
            check_nil(node);
            break;
        }
       
        // The node is not root, so we can find it's sibling.
        TNode *sib = nullptr;
        bool node_side = 0;
        if (node == node->parent->left) {
            sib = node->parent->right;
            node_side = 0;
        } else {
            sib = node->parent->left;
            node_side = 1;
        }
 
        // Case 1. Sibling is red.
        if (get_color(sib) == 1) {
            set_color(node->parent, 1);
            set_color(sib, 0);
            if (node_side == 0) {
                rotate_left(node->parent);
            } else {
                rotate_right(node->parent);
            }
            continue;
        }
 
        // Case 2. Sibling is black, sib's children are black.
        if (!get_color(sib) &&
                !get_color(sib->left) && !get_color(sib->right)) {
            set_color(sib, 1);
            set_color(node, 0);
            // Parent is red, terminal state.
            if (get_color(node->parent) == 1) {
                set_color(node->parent, 0);
                check_nil(node);
                break;
            }
            // Parent is black. Moving double-black to it.
            else {
                set_color(node->parent, 2);
                check_nil(node);
                node = node->parent;
            }
            continue;
        }
 
        // Case 3. Sibling is black, sib-inner:red, sib-outer: black.
        // Case 4. Sibling is black, sib-inner:---, sib-outer: red.
        if (get_color(sib) == 0) {
            if (node_side == 0) {  // Node is left child, sibling is right.
                // Case 3.
                if (get_color(sib->left) == 1 && get_color(sib->right) == 0) {
                    set_color(sib, 1);
                    set_color(sib->left, 0);
                    rotate_right(sib);
                }
                // Case 4. TERMINAL.
                if (get_color(sib->right) == 1) {
                    set_color(sib->right, 0);
                    set_color(sib, get_color(sib->parent));
                    set_color(sib->parent, 0);
                    set_color(node, 0);
                    check_nil(node);
                    rotate_left(sib->parent);
                    break;
                }
            } else {               // Node is right child, sibling is left.
                // Case 3.
                if (get_color(sib->right) == 1 && get_color(sib->left) == 0) {
                    set_color(sib, 1);
                    set_color(sib->right, 0);
                    rotate_left(sib);
                }
                // Case 4. TERMINAL.
                if (get_color(sib->left) == 1) {
                    set_color(sib->left, 0);
                    set_color(sib, get_color(sib->parent));
                    set_color(sib->parent, 0);
                    set_color(node, 0);
                    check_nil(node);
                    rotate_right(sib->parent);
                    break;
                }
            }
        }
    }
    set_color(this->root, 0);
}
// }
 
 
// Public functions {
TNode *RBtree::find(int val) {
    return _find(this->root, val);
}
 
void RBtree::insert(int val) {
    _insert(val, this->root, nullptr);
}
 
void RBtree::remove(int val) {
    TNode *node = find(val);
    if (node != nullptr) {
        _remove(node);
    }
}
 
void RBtree::print(TNode *root, int offset) {
    if (root == nullptr && offset == 0) {
        root = this->root;
    }
    if (root == nullptr) {
        return;
    }
    this->print(root->right, offset + 1);
 
    for (int i = 0; i < offset; i++) cout << "     ";
    if (root->color == 0) {
        system("Color 1A");
        cout << "\033[1;34m";
    } else if (root->color == 1) {
        system("Color B2");
        cout << "\033[1;31m";
    } else if (root->color == 2) {
        system("Color E5");
        cout << "\033[1;30m";
    }
 
    if (root->is_nil) {
        cout << "N";
    } else {
        cout << root->val;
    }
 
    cout << "\033[0m\n";
       
    this->print(root->left, offset + 1);
}
// }
 
 
int main() {
    RBtree tree;
 
 
    vector<int> v = {7,12,54,11,25,3,2,54,4,1,25,2,3,6,5,21,4,5,9,85,4,1,24,1,2,3,5,2,14,5,2,1,45,21,1,4,556,9,8,7,5,5,41,2,23,3,6,5,2,39,8,41,21,23,854,1,2,5,63,2,988,7,4,58,8,9,56,211,4,5,96,7,8996,8,556,9,85,5263,20,56,63,256,4,2,0,45,56,0,41,4787,65,41,585,1,5,10,0,54,112,25,0,12,52,0,4,21,52,5848,6,2,00,5,87,89,6,5,10,25,54,251,54,0,54,5,25,54,0,2554,1,87};
    for (auto i : v) {
        tree.insert(i);
    }
    tree.print();
    
 
    int t, x;
    while (1) {
        cin >> t >> x;
        if (t == 0) {
            cout << "Inserting " << x << "...\n";
            tree.insert(x);
        } else {
            cout << "Removing " << x << "...\n";
                for (auto i : v) {
                tree.remove(i);
                    tree.print();
    }
        }
        cout << "----------------------------------------\n";
        tree.print();
        cout << "----------------------------------------\n\n\n";
    }
 
 
    return 0;
}