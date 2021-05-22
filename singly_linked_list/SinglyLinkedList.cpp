#include "SinglyLinkedList.h"

int main() {
    SinglyLinkedList<int> my_list;
    my_list.show_list(); // The list is empty
    my_list.push_front(5); // 5
    my_list.push_front(4); // 4 5
    my_list.push_front(3); // 3 4 5
    my_list.push_front(2); // 2 3 4 5 
    my_list.push_front(1); // 1 2 3 4 5
    my_list.show_list(); // 1 2 3 4 5
    my_list.push_back(6); // 1 2 3 4 5 6
    my_list.push_back(7); // 1 2 3 4 5 6 7
    my_list.push_back(8); // 1 2 3 4 5 6 7 8
    my_list.show_list(); // 1 2 3 4 5 6 7 8
    std::cout << my_list.get_size() << std::endl; // 8

    /*SinglyLinkedList<std::string> *my_list2 = new SinglyLinkedList<std::string>();
    my_list2->show_list(); // nullptr
    my_list2->push_front("R"); // R
    my_list2->push_front("A"); // A R
    my_list2->push_front("G"); // G A R
    my_list2->push_front("D"); // D G A R 
    my_list2->push_front("E"); // E D G A R
    my_list2->show_list(); // E D G A R 

    SinglyLinkedList<float> my_list3;
    my_list3.show_list(); // nullptr
    my_list3.push_front(5.2); // 5
    my_list3.push_front(4.45); // 4 5
    my_list3.push_front(0.23); // 3 4 5
    my_list3.push_front(2.39); // 2 3 4 5 
    my_list3.push_front(1.5); // 1 2 3 4 5
    my_list3.show_list(); // 1 2 3 4 5
    my_list3.~SinglyLinkedList();
    my_list3.show_list(); // nullptr
    */
    return 0;
}