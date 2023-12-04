// AISD Lab2.cpp: определяет точку входа для приложения.
//
#include <iostream>
#include <string>
#include "AISD Lab2.h"

int main()
{
    setlocale(LC_ALL, "ru");
    // Конструктор по умолчанию
    DoublyLinkedList<int> iList;
    // работа push_tail
    iList.push_tail(11);
    iList.push_tail(22);
    iList.push_tail(33);
    iList.push_tail(44);
    iList.push_tail(*(new Node<int>(55)));
    // работа push_head
    iList.push_head(00);
    iList.print();

    std::cout << "\n\n";

    // Показываю, что список двусвязный циклический
    {
        Node<int>* item = iList.getFirst();
        for (size_t i = 0; i < 12; i++)
        {
            std::cout << " ";
            item->print();
            item = item->getNext();
        }
        std::cout << "\n\n";
        item = iList.getLast();
        for (size_t i = 0; i < 12; i++)
        {
            std::cout << " ";
            item->print();
            item = item->getPrev();
        }

        std::cout << "\n\n работа конструктора копирования";
        DoublyLinkedList<int> iList2(iList);
        std::cout << "\n\n";
        item = iList2.getFirst();
        for (size_t i = 0; i < 12; i++)
        {
            std::cout << " ";
            item->print();
            item = item->getNext();
        }
        std::cout << "\n\n";
        item = iList2.getLast();
        for (size_t i = 0; i < 12; i++)
        {
            std::cout << " ";
            item->print();
            item = item->getPrev();
        }
    }

    std::cout << "\n\n";

    // работа оператора присваивания
    {
        std::cout << "работа оператора присваивания\n\n";
        DoublyLinkedList<int> iList2 = iList;
        Node<int>* item = iList2.getFirst();
        for (size_t i = 0; i < 12; i++)
        {
            std::cout << " ";
            item->print();
            item = item->getNext();
        }
        std::cout << "\n\n";
        item = iList2.getLast();
        for (size_t i = 0; i < 12; i++)
        {
            std::cout << " ";
            item->print();
            item = item->getPrev();
        }
    }

    std::cout << "\n\n";

    {
        std::cout << "Добавление другого списка в конец и в начало\n\n";
        DoublyLinkedList<int> iList2;
        iList2.push_tail(121);
        iList2.push_tail(232);
        iList2.push_tail(343);

        iList.push_tail(iList2);
        iList.print();

    }

    
    /*std::cout << std::endl;
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
    sList.findInVal("список")->print();*/
}

