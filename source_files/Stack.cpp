/*
    File name: Stack.cpp
    Author: Edgar Ramírez
    Last modification date: 06/02/2021
    Repository Link: https://github.com/EdgarRamirezFuentes/Data_structures_and_algorithms
*/

#include "../header_files/Stack.hpp"

int main(void) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    while (!(stack.is_empty())) {
        std::cout << stack.get_top() << std::endl;
        stack.pop();
    }
    return 0;
}