/*
    File name: BinarySearchTree.cpp
    Author: Edgar Ramírez
    Last modification date: 06/07/2021
    Repository Link: https://github.com/EdgarRamirezFuentes/Data_structures_and_algorithms
*/

#include "../header_files/BinarySearchTree.hpp"

int main() {
    BinarySearchTree<int> tree;
    tree.add_node(100);
    tree.add_node(200);
    tree.add_node(50);
    tree.add_node(150);
    tree.add_node(400);
    tree.add_node(450);
    tree.add_node(300);
    tree.add_node(160);
    tree.add_node(140);
    tree.add_node(30);
    tree.add_node(70);
    tree.add_node(40);
    tree.add_node(60);
    std::cout << "BFS: ";
    tree.breadth_first_search_traversal();
    return 0;
}