#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "./SinglyLinkedList.hpp"

/// Queue implemented using a Singly Linked List
template <typename T>
class Queue {
public:
    /**
     * Constructor
     * Create an empty Queue
     * 
     */ 
    Queue(void) : front(new SinglyLinkedList<T>()) {};
    ~Queue();
    bool is_empty(void);
    void push(T value);
    void pop(void);
    size_t get_size(void);
    T get_front(void);
    T get_back(void);
private:
    SinglyLinkedList<T> *front;
};

/// Destructor
template <typename T>
Queue<T>::~Queue() {
    this->front->~SinglyLinkedList();
}

/**
 *  Complexity:
 *  Time -> O(1) 
 *  Memory -> O(1) 
 *  
 *  Check if the list is empty.  
 *  
 *  @return true if the queue is empty, or false if the queue has
 *          at least one element
 */
template <typename T>
bool Queue<T>::is_empty(void) {
    return this->front->is_empty();
}

/**
 *  Complexity: 
 *  Time -> O(1) 
 *  Memory -> O(1) 
 *  
 *   Add a new element to the queue. 
 *  
 *   @param value T data type used to add the new value to the queue
 */
template <typename T>
void Queue<T>::push(T value) {
    this->front->push_back(value);
}

/**
 *  Complexity:
 *  Time -> O(1)
 *  Memory -> O(1)
 *  
 *  Pop the element on the front of the queue
*/
template <typename T>
void Queue<T>::pop(void) {
    this->front->pop_front();
}

/**
 *  Complexity: 
 *  Time -> O(1) 
 *  Memory -> O(1) 
 *  
 *  Check the current size of the queue. 
 *  
 *  @return the current size of the queue
 */ 
template <typename T>
size_t Queue<T>::get_size(void) {
    return this->front->get_size();
}

/**
 * Complexity:
 * Time -> O(1)
 * Memory -> O(1)
 * 
 * Get and return the value on the front of the list
 * 
 * @return the value that is on the front of the queue
 */ 
template <typename T>
T Queue<T>::get_front(void) {
    return this->front->get_head_value();
}

/**
 * Complexity:
 * Time -> O(1)
 * Memory -> O(1)
 * 
 * Get and return the last value added in the queue
 * 
 * @return the last value added in the queue
 */ 
template <typename T>
T Queue<T>::get_back(void) {
    return this->front->get_tail_value();
}

#endif
