#include <iostream>

using namespace std;

template <class T>
struct Node {
    T value;
    Node *left;
    Node *right;

    Node(){}
    Node(T val) {
        this->value = val;
    }
};

template <class T>
class BST {
    private:
    Node<T> *root;

    void add_node(Node<T> *root, T val) {
        if (root->value > val) {
            if (!root->left) {
                root->left = new Node<T>(val);
            } else {
                add_node(root->left, val);
            }
        } else {
            if (!root->right) {
                root->right = new Node<T>(val);
            } else {
                add_node(root->right, val);
            }
        }
    }

    Node<T> *search(T value, Node<T> *leaf) {
      if(leaf!=NULL)
      {
        if(value==leaf->value)
          return leaf;
        if(value<leaf->value)
          return search(value, leaf->left);
        else
          return search(value, leaf->right);
      }
      else return NULL;
    }

    bool remove(T value, Node<T> *node) {
        if (value < node->value)
            return remove(value, node->left);
        else if (value > node->value)
            return remove(value, node->right);
        else {
            if (node->left && node->right) {
                Node<T> *tmp = find_min(node->right);
                remove(tmp->value, node->right);
                node = tmp;
            }
            else if (node->left) {
                node = node->left;
            }
            else if (node->right) {
                node = node->right;
            }
            return true;
        }
    }

    Node<T>* find_min(Node<T> *node) {
        while (node->left)
            node = node->left;
        return node;
    }

    // Traverse the left sub-tree, root, right sub-tree
    void traverse_InOr(Node<T> *node) {
        if (node) {
           traverse_InOr(node->left);
           cout << node->value << " ";
           traverse_InOr(node->right);
        }
    }

    // Traverse the root, left sub-tree, right sub-tree
    void traverse_PreOr(Node<T> *node) {
        if (node) {
           cout << node->value << " ";
           traverse_PreOr(node->left);
           traverse_PreOr(node->right);
        }
    }

    // Traverse left sub-tree, right sub-tree, root
    void traverse_PostOr(Node<T> *node) {
        if (node) {
           traverse_PostOr(node->left);
           traverse_PostOr(node->right);
           cout << node->value << " ";
        }
    }

    public:

    void insert(T value) {
        if (root) {
            this->add_node(root, value);
        } else {
            root = new Node<T>(value);
        }
    }

    bool remove(T value) {
        if (root == NULL)
            return false;
        else
            return remove(value, root);
    }

    Node<T> *search(T value) {
        return search(value, root);
    }

    void print() {
        traverse_InOr(root);
    }
};

int main() {
    BST<int> *bst = new BST<int>();
    bst->insert(10);
    bst->insert(1);
    bst->insert(16);
    bst->insert(21);
    bst->insert(5);
    bst->insert(7);
    bst->insert(11);
    bst->print();
    return 0;
}
