/*
    File name: SinglyLinkedList.hpp
    Author: Edgar Ramírez
    Last modification date: 05/25/2021
*/

#include <iostream>
#include "../header_files/SinglyLinkedList.hpp"

int main(void) {
    std::cout << "Hola mundo" << std::endl;
    // LinkedList
    SinglyLinkedList<int> myList;
    myList.push_front(1);
    myList.push_back(2);
    myList.show_list();

    return 0;
}