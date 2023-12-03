// AISD Lab2.cpp: определяет точку входа для приложения.
//
#include <iostream>
#include <string>
#include "AISD Lab2.h"

int main()
{
    setlocale(LC_ALL, "ru");
    DoublyLinkedList<int> iList;
    iList.addNode(11);
    iList.addNode(22);
    iList.addNode(33);
    iList.addNode(44);
    iList += *(new Node<int>(55));
    iList.print();
    std::cout << std::endl;
    std::cout << "3)";
    iList.findInInd(3)->print();

    std::cout << std::endl;
    std::cout << "2)";
    iList.findInVal(33)->print();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    DoublyLinkedList<std::string> sList;
    sList.addNode(*(new std::string("привет")));
    sList.addNode(*(new std::string("я")));
    sList.addNode(*(new std::string("список")));
    sList.addNode(*(new std::string("в")));
    sList += *(new Node<std::string>(*(new std::string("C++"))));
    sList.print();
    std::cout << std::endl;
    std::cout << "3)";
    auto nodeWord = sList.findInInd(3);
    nodeWord->print();
    std::cout << std::endl;
    std::cout << "2)";
    sList.findInVal("список")->print();
}

