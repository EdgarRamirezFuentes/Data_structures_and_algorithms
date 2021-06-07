/*
    File name: BinarySearchTree.hpp
    Author: Edgar Ramírez
    Last modification date: 06/07/2021
    Repository Link: https://github.com/EdgarRamirezFuentes/Data_structures_and_algorithms
*/

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "./Queue.hpp"

template <typename T>
struct TreeNode {
    T value;
    TreeNode<T> *left;
    TreeNode<T> *right;

    /// TreeNode Constructor
    TreeNode (T value) : value(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
public:
    /// Constructor
    BinarySearchTree() : root (nullptr) {}
    ~BinarySearchTree();
    bool is_empty(void);
    TreeNode<T>* search_value(T);
    void add_node(T);
    void preorder_traversal(void);
    void posorder_traversal(void);
    void inorder_traversal(void);
    void delete_node(void);
    void breadth_first_search_traversal(void);
private:
    void get_preorder_traversal(TreeNode<T>*);
    void get_posorder_traversal(TreeNode<T>*);
    void get_inorder_traversal(TreeNode<T>*);
    TreeNode<T>* root;
};

/// Destructor
template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    if (is_empty()) { return; }
    Queue<TreeNode<T>*> q;
    TreeNode<T>* current_node = nullptr;
    q.push(root);
    // Frees each TreeNode allocated in memory
    while (!(q.is_empty())) {
        current_node = q.get_front();
        if (current_node->left) { q.push(current_node->left); }
        if (current_node->right) { q.push(current_node->right); }
        delete current_node;
        q.pop();
    }
}

/**
 * Complexity:
 * Time -> O(1)
 * Memory -> O(1)
 * 
 * Checks if the Binary Search Tree is empty
 * 
 * @return true if the Binary Search Tree is empty, false if the Binary Search Tree
 *         at least has one element
 */ 
template <typename T>
bool BinarySearchTree<T>::is_empty(void) {
    return !(this->root);
}

/**
 * Complexity:
 * Time -> O(log n), where n is the number of elements in the Binary Search Tree
 * Memory -> O(1)
 * 
 * Adds a new node into the Binary Search Tree
 * 
 * @param value is the value that will be inserted into the Binary Search Tree
 */ 
template <typename T>
void BinarySearchTree<T>::add_node(T value) {
    TreeNode<T> *new_node = nullptr;
    new_node = new TreeNode<T>(value);
    if (!new_node) { return; } // The new node could not be allocated

    if (is_empty()) {
        this->root = new_node;
        return;
    }

    TreeNode<T> *aux = nullptr; 
    aux = root;
    while (true) {
        if (aux->value == value) { // The value already exists
            return;
        } else if (value < aux->value) {
            if (aux->left) { // Continues looking for a place for the new node on the left subtree
                aux = aux->left;
            } else { // There is no left subtree. Hence, the new node is placed on the left child of the current node 
                aux->left = new_node;
                break;
            }
        } else {
            if (aux->right) { // Continues looking for a place for the new node on the right subtree
                aux = aux->right;
            } else { // There is no right subtree. Hence, the new node is placed on the right child of the current node 
                aux->right = new_node;
                break;
            }
        }
    }
}

/**
 * Complexity:
 * Time -> O(log n), where n is the number of elements in the Binary Search Tree
 * Memory -> O(1)
 * 
 * Looks for a value into the Binary Search Tree and returns a pointer to the TreeNode that contains
 * that value if it was found.  
 * 
 * @param value is the value that will be looked for into the Binary Search Tree
 * 
 * @return a pointer to the TreeNode that contains the value, or nullptr if it was not found
 * 
 */ 
template <typename T>
TreeNode<T>* BinarySearchTree<T>::search_value(T value) {
    TreeNode<T>* aux = nullptr;
    aux = root;
    while (aux) {
        if (value == aux->value) {
            return aux;
        } else if (value < aux->value) {
            aux = aux->left;
        } else {
            aux = aux->right;
        }
    }
    return nullptr; // The value was no found in the tree
}

/**
 * Complexity:
 * Time -> O(n), where n is the number of elements in the Binary Search Tree
 * Memory -> O(n), where n is the number of elements in the binary Search Tree
 * 
 * Prints the BFS traversal of the Binary Search Tree
 */ 
template <typename T>
void BinarySearchTree<T>::breadth_first_search_traversal(void) {
    if (is_empty()) { return; }
    Queue<TreeNode<T>*> q;
    TreeNode<T>* current_node = nullptr;
    q.push(root);
    while (!(q.is_empty())) {
        current_node = q.get_front();
        std::cout << current_node->value << " ";
        if (current_node->left) { q.push(current_node->left); }
        if (current_node->right) { q.push(current_node->right); }
        q.pop();
    }
}

template <typename T>
void BinarySearchTree<T>::preorder_traversal(void) {
    get_preorder_traversal(root);
}

template <typename T>
void BinarySearchTree<T>::inorder_traversal(void) {
    get_inorder_traversal(root);
}

template <typename T>
void BinarySearchTree<T>::posorder_traversal(void) {
    get_posorder_traversal(root);
}
/**
 * Complexity:
 * Time -> O(n), where n is the number of elements in the Binary Search Tree
 * Memory -> O(n), where n is the number of elements in the Binary Search Tree
 * 
 * Prints the DFS (preorder) traversal of the Binary Search Tree
 * 
 * @param current_node is the node that is being analized in the current recursive call 
 */ 
template <typename T>
void BinarySearchTree<T>::get_preorder_traversal(TreeNode<T>* current_node) {
    if (!(current_node)) { return; }
    std::cout << current_node->value << " ";
    get_preorder_traversal(current_node->left);
    get_preorder_traversal(current_node->right);
}

/**
 * Complexity:
 * Time -> O(n), where n is the number of elements in the Binary Search Tree
 * Memory -> O(n), where n is the number of elements in the Binary Search Tree
 * 
 * Prints the DFS (posorder) traversal of the Binary Search Tree
 * 
 * @param current_node is the node that is being analized in the current recursive call 
 */ 
template <typename T>
void BinarySearchTree<T>::get_posorder_traversal(TreeNode<T>* current_node) {
    if (!(current_node)) { return; }
    get_posorder_traversal(current_node->left);
    get_posorder_traversal(current_node->right);
    std::cout << current_node->value << " ";
}

/**
 * Complexity:
 * Time -> O(n), where n is the number of elements in the Binary Search Tree
 * Memory -> O(n), where n is the number of elements in the Binary Search Tree
 * 
 * Prints the DFS (inorder) traversal of the Binary Search Tree
 * 
 * @param current_node is the node that is being analized in the current recursive call 
 */ 
template <typename T>
void BinarySearchTree<T>::get_inorder_traversal(TreeNode<T>* current_node) {
    if (!(current_node)) { return; }
    get_inorder_traversal(current_node->left);
    std::cout << current_node->value << " ";
    get_inorder_traversal(current_node->right);
}
#endif