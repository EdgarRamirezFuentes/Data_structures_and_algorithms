#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>

template <typename T>
struct Node {
    T value;
    Node *left;
    Node *right;

    Node (T value) : value(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
public:
    BinarySearchTree() : root (nullptr) {}
    ~BinarySearchTree() {}
    size_t get_size(void);
    void add_node(T);
    Node<T>* search_value(T);
    void delete_node(void);
    bool is_empty(void);
private:
    Node<T>* root;
    size_t size;
};


template <typename T>
bool BinarySearchTree<T>::is_empty(void) {
    return !(this->root);
}

template <typename T>
void BinarySearchTree<T>::add_node(T value) {
    Node<T> *new_node = nullptr;
    new_node = new Node<T>(value);
    if (!new_node) { return; } // The new node could not be allocated

    if (!root) {
        this->root = new_node;
        this->size++;
        return;
    }

    Node<T> *aux = nullptr; 
    aux = root;
    while (true) {
        if (aux->value == value) { // The value already exists
            return;
        } else if (value < aux->value) {
            if (aux->left) { // Continue looking for a place for the new node on the left subtree
                aux = aux->left;
            } else { // There is no left subtree. Hence, the new node is placed on the left child of the current node 
                aux->left = new_node;
                break;
            }
        } else {
            if (aux->right) { // Continue looking for a place for the new node on the right subtree
                aux = aux->right;
            } else { // There is no right subtree. Hence, the new node is placed on the right child of the current node 
                aux->right = new_node;
                break;
            }
        }
    }
    this->size++;
}

template <typename T>
size_t BinarySearchTree<T>::get_size(void) {
    return this->size;
}

template <typename T>
Node<T>* BinarySearchTree<T>::search_value(T value) {
    Node<T>* aux = nullptr;
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

#endif