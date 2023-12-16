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
    iList.push_tail(44);
    iList.push_tail(22);
    iList.push_tail(44);
    iList.push_tail(33);
    iList.push_tail(44);
    iList.push_tail(*(new Node<int>(55)));
    iList.push_tail(44);
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

    // Добавление другого списка в конец
    {
        std::cout << "Добавление другого списка в конец\n\n";
        DoublyLinkedList<int> iList2;
        iList2.push_tail(121);
        iList2.push_tail(232);
        iList2.push_tail(343);
        iList2.push_tail(454);

        iList.push_tail(iList2);
        iList.print();
    }

    std::cout << "\n\n";

    // Добавление другого списка в начало
    {
        std::cout << "Добавление другого списка в начало\n\n";
        DoublyLinkedList<int> iList2;
        iList2.push_tail(111);
        iList2.push_tail(222);
        iList2.push_tail(333);
        iList2.push_tail(444);

        iList.push_head(iList2);
        iList.print();
    }

    std::cout << "\n\n";

    // Добавление элемента со степенью
    {
        std::cout << "Добавление элемента со степенью\n\n";
        iList.push_tail(77, 4);
        iList.print();
        std::cout << "\n\n";

        iList.push_head(88, 7);
        iList.print();
        std::cout << "\n\n";
    }

    std::cout << "\n\n";

    // Добавление элемента при помощи оператора +=
    {
        std::cout << "Добавление элемента при помощи оператора +=\n\n";
        Node<int>* item = new Node<int>(555);
        iList += item;
        iList.print();
    }

    std::cout << "\n\n";

    // удаление эл-та из начала списка
    {
        std::cout << "удаление эл-та из начала списка\n\n";
        DoublyLinkedList<int> iList2;

        iList.pop_head();
        iList.print();
    }

    std::cout << "\n\n";

    // удаление эл-та из конца списка
    {
        std::cout << "удаление эл-та из конца списка\n\n";
        DoublyLinkedList<int> iList2;

        iList.pop_tail();
        iList.print();
    }

    std::cout << "\n\n";

    // удаление всех элементов по значению 
    {
        std::cout << "удаление элементов по значению 44\n\n";
        iList.delete_node(44);
        iList.print();

        std::cout << "\n";

        std::cout << "удаление элементов по значению 55\n\n";
        iList.delete_node(55);
        iList.print();

        std::cout << "\n";

        std::cout << "удаление элементов по значению 121\n\n";
        iList.delete_node(121);
        iList.print();
    }

    std::cout << "\n\n";

    // удаление всех эл-ов Node с информационным полем
    {
        std::cout << "удаление всех эл-ов Node с информационным полем\n\n";
        iList.delete_node("Удалил все элементы списка");
        iList.print();
    }

    std::cout << "\n\n";
    
    // Выполнение задания с функциями
    {
        function_class::Function<int> FuncInt1(5, true);
        std::cout << FuncInt1 << std::endl;

        DoublyLinkedList<int> iList2(FuncInt1);
        iList2.print();
        
        std::cout << "\n";
        std::cout << "Вставляем элемент 1000 со степенью 3 в конец\n";
        iList2.push_tail(1000, 3);
        iList2.print();
        std::cout << "Вставляем элемент 2000 со степенью 5 в начало\n";
        iList2.push_head(2000, 5);
        iList2.print();
        std::cout << std::endl << resultOfPolinomial(iList2, 2) << std::endl;

    }

    std::cout << "\n\n";

    // Заполняет рандомными числами при помощи конструктора
    {

        DoublyLinkedList<int> iList2(10);
        iList2.print();

        std::cout << std::endl << resultOfPolinomial(iList2, 10) << std::endl;

    }

}

