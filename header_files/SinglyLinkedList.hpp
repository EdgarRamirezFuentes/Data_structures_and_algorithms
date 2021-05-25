/*
    File name: SinglyLinkedList.hpp
    Author: Edgar Ramírez
    Last modification date: 05/25/2021
*/

#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP

#include <iostream>

template <typename T>
struct Node {
	T value;
	Node<T> *next;

	/**
     *  Constructor
     *  @param value Integer used to initialize the value of the node
     */ 
	Node (T value) : value(value), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
public:
	Node<T> *head;
	/// Constructor
	SinglyLinkedList();

	/// Destructor
	~SinglyLinkedList();

	/// Methods
	bool is_empty();
	void show_list();
	void push_front(T);
	void push_back(T);
	size_t get_size();
	void push_nth_position(T, int);
	void reverse_list();

private:
	size_t size;
	/// Keep track of the last node added at the end of the list
	Node<T> *tail;
};

#include "../header_files/SinglyLinkedList.hpp"

/// Constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

/// Destructor
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node<T> *aux = nullptr;
    while (head) {
        aux = head;
        head = head->next;
        delete aux;
    }
    size = 0;
    head = nullptr;
}

/**
 *  Complexity:
 *  Time -> O(1) 
 *  Memory -> O(1) 
 *  
 *  Check if the list is empty.  
 *  
 *  @return true if the list is empty, or false if the list has
 *          at least one node
 */
template <typename T>
bool SinglyLinkedList<T>::is_empty() {
    // return (head == nullptr ? true : false);
    return !(head);
}

/**
 *  Complexity: 
 *  Time -> O(n) 
 *  Memory -> O(1) 
 *  
 *   Print the value of each node in the list. 
 */
template <typename T>
void SinglyLinkedList<T>::show_list() {
    Node<T> *aux = nullptr;
    aux = head;
    
    if (is_empty()) {
        std::cout << "The list is empty\n";
        return;
    }

    while (aux) {
        std::cout << aux->value << " ";
        aux = aux->next;
    }
    std::cout << "\n";
}

/**
 *  Complexity: 
 *  Time -> O(1) 
 *  Memory -> O(1) 
 *  
 *   Add a new node at the beginning of the list. 
 *  
 *   @param value T data type used to initialize the value of the new node 
 */
template <typename T>
void SinglyLinkedList<T>::push_front(T value) {
    Node<T> *aux = nullptr;
    Node<T> *new_node = nullptr;
    new_node = new Node<T>(value);
    if (new_node) {
        // The node was created successfully
        size++;
        if (is_empty()) {
            head = new_node;
            tail = new_node;
            return;
        }
        aux = head;
        head = new_node;
        head->next = aux;
    }
}

/**
 *  Complexity: 
 *  Time -> O(1) 
 *  Memory -> O(1) 
 *  
 *   Add a new node at the end of the list. 
 *  
 *   @param value T data type used to initialize the value of the new node 
 */
template <typename T>
void SinglyLinkedList<T>::push_back(T value) {
    Node<T> *aux = nullptr;
    Node<T> *new_node = nullptr;
    new_node = new Node<T>(value);
    if (new_node) {
        size++;
        if (is_empty()) {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        tail = new_node;
    }
}

/**
 *  Complexity: 
 *  Time -> O(1) 
 *  Memory -> O(1) 
 *  
 *  Check the current size of the list. 
 *  
 *  @return the current size of the list 
 */ 
template <typename T>
size_t SinglyLinkedList<T>::get_size() {
    return size;
}

/**
 *  Add a new node at the nth position of the list. 
 *  
 *  If the position is less or equal than 1, the node will be pushed 
 *  at the beginning of the list. 
 *  
 *  if the position is greater than the size of the list, the node will be pushed 
 *  at the end of the list. 
 *  
 *  The first position of the list is 1. 
 *  
 *   @param value T data type used to initialize the value of the new node
 *   @param position Integer used to know in which position the new node
            will be pushed.
*/
template <typename T>
void SinglyLinkedList<T>::push_nth_position(T value, int position) {
    if (is_empty() || position <= 1) {
        push_front(value);
        return;
    } else if(position > size) {
        push_back(value);
        return;
    }
    int counter = 1;
    Node<T> *aux = nullptr;
    Node<T> *new_node = nullptr;
    aux = head;
    while (counter < position - 1) {
        aux = aux->next;
        ++counter;
    }
    new_node = new Node<T>(value);
    if (new_node) {
        // The new node was created successfully
        new_node->next = aux->next;
        aux->next = new_node;
        size++;
    }
}

/**
 *  Reverse the list 
 */ 
template <typename T>
void SinglyLinkedList<T>::reverse_list() {
    Node<T> *prev = nullptr;
    Node<T> *current = nullptr;
    Node<T> *next = nullptr;
    // Set the new tail
    tail = head;
    current = head;
    // Reverse the list
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Set the new head
    head = prev;
}

#endif /* SINGLYLINKEDLIST_HPP */