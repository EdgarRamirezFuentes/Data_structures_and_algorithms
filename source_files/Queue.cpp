/*
    File name: Queue.cpp
    Author: Edgar Ramírez
    Last modification date: 06/01/2021
    Repository Link: https://github.com/EdgarRamirezFuentes/Data_structures_and_algorithms
*/

#include "../header_files/Queue.hpp"

int main(void) {
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    std::cout << "Last value added: " << queue.get_back() << std::endl;
    queue.push(4);
    std::cout << "Last value added: " << queue.get_back() << std::endl;
    while (!(queue.is_empty())) {
        std::cout << queue.get_front() << std::endl;
        queue.pop();
    }
}