/*
    File name: Stack.hpp
    Author: Edgar Ramírez
    Last modification date: 06/02/2021
    Repository Link: https://github.com/EdgarRamirezFuentes/Data_structures_and_algorithms
*/

#ifndef STACK_HPP
#define STACK_HPP

#include "./SinglyLinkedList.hpp"

template <typename T>
class Stack {
public:
    /**
     * Constructor
     * Create an empty Stack
     * 
     */ 
    Stack()  : top(new SinglyLinkedList<T>()) {}
    ~Stack();
    void push(T);
    void pop(void);
    T get_top(void);
    bool is_empty(void);
    size_t get_size(void);
private:
    SinglyLinkedList<T> *top;
};

/// Destructor
template <typename T>
Stack<T>::~Stack() {
    this->top->~SinglyLinkedList();
}

/**
 *  Complexity:
 *  Time -> O(1) 
 *  Memory -> O(1) 
 *  
 *  Check if the stack is empty.  
 *  
 *  @return true if the stack is empty, or false if the stack has
 *          at least one element
 */
template <typename T>
bool Stack<T>::is_empty(void) {
    return this->top->is_empty();
}

/**
 *  Complexity: 
 *  Time -> O(1) 
 *  Memory -> O(1) 
 *  
 *  Check the current size of the stack. 
 *  
 *  @return the current size of the stack
 */ 
template <typename T>
size_t Stack<T>::get_size(void) {
    return this->top->get_size();
}

/**
 *  Complexity: 
 *  Time -> O(1) 
 *  Memory -> O(1) 
 *  
 *   Add a new element to the stack. 
 *  
 *   @param value T data type used to add the new value to the stack
 */
template <typename T>
void Stack<T>::push(T value) {
    this->top->push_front(value);
}

/**
 *  Complexity:
 *  Time -> O(1)
 *  Memory -> O(1)
 *  
 *  Pop the element on the top of the stack
*/
template <typename T>
void Stack<T>::pop(void) {
    this->top->pop_front();
}

/**
 * Complexity:
 * Time -> O(1)
 * Memory -> O(1)
 * 
 * Get and return the last value added in the stack
 * 
 * @return the last value added in the stack
 */ 
template <typename T>
T Stack<T>::get_top(void) {
    return this->top->get_head_value();
}

#endif