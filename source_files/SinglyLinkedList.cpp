/*
    File name: SinglyLinkedList.hpp
    Author: Edgar Ramírez
    Last modification date: 05/25/2021
*/

#include <iostream>
#include "../header_files/SinglyLinkedList.hpp"

int main(void) {
    // LinkedList
    SinglyLinkedList<int> myList;
    myList.push_back(5);
    myList.show_list();
    return 0;
}