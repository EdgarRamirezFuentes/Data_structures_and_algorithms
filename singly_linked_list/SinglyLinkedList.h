#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

template <typename T>
struct Node {
	T value;
	Node<T> *next;

	/**
     *  Constructor
     *  @param value Integer used to initial value of the node
     */ 
	Node (T value) : value(value), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
	public:
		Node<T> *head;
		// Constructor
        SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

        // Destructor
        ~SinglyLinkedList() {
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
        * Returns wether the list is empty.
        * true -> The list is empty
        * false -> The list is not empty
		*/
		bool is_empty() {
			// Operador ternario
			return !(head);
		}

        /**
         * Print each node of the list
         */
		void show_list() {
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
         * Add a new node at the beginning of the list
         */
        void push_front(T value) {
            Node<T> *aux = nullptr;
            Node<T> *new_node = nullptr;
            new_node = new Node<T>(value);
            // The node was created successfully
            if (new_node) {
                // Increases the size of the current list
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

        void push_back(T value) {
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

        size_t get_size() {
            return size;
        }


    private:
        size_t size;
        Node<T> *tail;
};

#endif