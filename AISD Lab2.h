#pragma once

#include <iostream>
#include <random>
#include <string>
#include "includes/Lab1.h"

template <typename T>
class Node {
private:
    double _val;
    size_t _degree;
    Node<T>* _next;
    Node<T>* _prev;
public:
    // Конструктор по уполчанию п.1 общ часть
    Node() = default;
    // Конструктор копирования п.2 общ часть
    Node(Node& const node) {
        this->_val = node.getValue();
        this->_degree = node.getDegree();
        this->_next = node.getNext();
        this->_prev = node.getPrev();
    }
    Node(T val, size_t degree) {
        this->_val = val;
        this->_degree = degree;
        this->_next = nullptr;
        this->_prev = nullptr;
    }
    Node(T val) {
        this->_val = val;
        this->_degree = 0;
        this->_next = nullptr;
        this->_prev = nullptr;
    }
    Node(T val, Node<T>* prev) {
        this->_val = val;
        this->setDegree(this->getPrev()->getDegree() + 1);
        this->_next = nullptr;
        this->_prev = prev;
    }
    
    Node(const T& val, size_t degree, Node<T>* next, Node<T>* prev) :
        _val(val), _degree(degree), _next(next), _prev(prev){}
    Node<T>* getNext() const{ return this->_next; }
    void setNext(Node<T>* next) {
        this->_next = next;
        return;
    }
    Node<T>* getPrev() const { return this->_prev; }
    void setPrev(Node<T>* prev) {
        this->_prev = prev;
        return;
    }
    T getValue() const { return this->_val; }
    void setValue(T value) {
        this->_val = value;
        return;
    }
    size_t getDegree() { return this->_degree; }
    void setDegree(size_t degree) {
        this->_degree = degree;
        return;
    }

    void print() const {
        std::cout << this->_val;
        return;
    }
    void swap(Node<T>& el_1, Node<T>& el_2) {
        el_1.setNext(el_2.getNext());
        el_1.setPrev(el_2.getPrev());
        el_1.setValue(el_2.getValue());
        return;
    }
    Node<T>& operator=(Node<T> other) 
    {
        this->swap(*this, other);
        return *this;
    }
    bool operator==(const Node<T>& other) const
    {
        if (other._val == this->_val) {
            return true;
        }
        return false;
    }
    ~Node() = default;
};




template<typename T>
class DoublyLinkedList {
private:
    Node<T>* _first;
    Node<T>* _last;
    size_t _countNodes;
    //void randomPasteDouble(size_t length) {
    //    std::random_device rd;   // non-deterministic generator
    //    std::mt19937 gen(rd());  // to seed mersenne twister.
    //    std::uniform_real_distribution<> dist(0, 20);
    //    if (length == 1) {
    //        this->_first = new Node<T>(dist(gen), 0);
    //        this->_last = this->_first;
    //        this->_first->setNext(this->_last);
    //        this->_first->setPrev(this->_last);
    //        return;
    //    }
    //    this->_first = new Node<T>(dist(gen), 0);
    //    this->_last = new Node<T>(dist(gen), 1);
    //    this->_first->setNext(this->_last);
    //    this->_first->setPrev(this->_last);
    //    this->_last->setNext(this->_first);
    //    this->_last->setPrev(this->_first);
    //    this->_countNodes = 2;
    //    for (size_t i = 2; i < length; ++i)
    //    {
    //        this->push_tail(*(new Node<T>(dist(gen), i)));
    //    }
    //}
    //void randomPasteInt(size_t length) {
    //    std::random_device rd;   // non-deterministic generator
    //    std::mt19937 gen(rd());  // to seed mersenne twister.
    //    std::uniform_int_distribution<> dist(0, 20);
    //    if (length == 1) {
    //        double rnd = dist(gen);
    //        this->_first = new Node<T>(T(rnd), 0);
    //        this->_last = this->_first;
    //        this->_first->setNext(this->_last);
    //        this->_first->setPrev(this->_last);
    //        return;
    //    }
    //    this->_first = new Node<T>(dist(gen), 0);
    //    this->_last = new Node<T>(dist(gen), 1);
    //    this->_first->setNext(this->_last);
    //    this->_first->setPrev(this->_last);
    //    this->_last->setNext(this->_first);
    //    this->_last->setPrev(this->_first);
    //    this->_countNodes = 2;
    //    for (size_t i = 2; i < length; ++i)
    //    {
    //        this->push_tail(*(new Node<T>(dist(gen), i)));
    //    }
    //}
protected:
    void setFirst(Node<T>* first) {
        this->_first = first;
        return;
    }
    void setLast(Node<T>* last) {
        this->_last = last;
        return;
    }
    void setCountNodes(const size_t& const countNodes) {
        this->_countNodes = countNodes;
        return;
    }
public:
    DoublyLinkedList() :_first(nullptr), _last(nullptr), _countNodes(0) {}
    DoublyLinkedList(const DoublyLinkedList<T>& list) {
        if (!(list.getCountNodes())) throw std::runtime_error("Вы передаёте пустой список");
        if (list.getCountNodes() < 2) {
            this->_first = new Node<T>(list.getFirst()->getValue(), list.getFirst()->getDegree()); 
            this->_first->setNext(this->_first);
            this->_first->setPrev(this->_first);
        }
        //this->setCountNodes(list.getCountNodes());
        Node<T>* item = list.getFirst();
        //Node<T>* item2 = list.getFirst()->getNext();
        this->_first = new Node<T>(item->getValue(), item->getDegree());
        this->_last = this->_first;
        this->_first->setNext(this->_first);
        this->_first->setPrev(this->_first);
        this->_last->setNext(this->_first);
        this->_last->setPrev(this->_first);
        this->setCountNodes(1);
        item = item->getNext();

        for (size_t i = 2; i <= list.getCountNodes(); ++i)
        {
            //item = item->getNext();
            Node<T>* newItem = new Node<T>(item->getValue(), item->getDegree());
            this->push_tail( *newItem );
            item = item->getNext();
        }
    }
    DoublyLinkedList(Node<T>* _first, Node<T>* _last, const size_t& _countNodes):
        _first(_first), _last(_last), _countNodes(_countNodes){}
    DoublyLinkedList(function_class::Function<T> func) {
        function_class::Function<T> funcCopy = func;
        funcCopy.shrink_to_fit();
        size_t secInd = 0;
        for (size_t i = 0; i <= funcCopy.getMaxDegree(); ++i)
        {
            if (funcCopy.getCoef(i) == 0) continue;
            Node<T>* item = new Node<T>(funcCopy.getCoef(i), i);
            Node<T>* item2 = nullptr;
            for (size_t j = i+1; j <= funcCopy.getMaxDegree(); ++j)
            {
                if (funcCopy.getCoef(j) == 0) continue;
                item2 = new Node<T>(funcCopy.getCoef(j), j);
                secInd = j;
                i = j;
                break;
            }
            if (item2 == nullptr) return;
            this->_first = item;
            this->_last = item2;
            this->_first->setNext(this->_last);
            this->_first->setPrev(this->_last);
            this->_last->setNext(this->_first);
            this->_last->setPrev(this->_first);
            this->_countNodes = 2;
            if (i == funcCopy.getMaxDegree() - 1) return;
            break;
        }
        for (size_t i = secInd + 1; i <= funcCopy.getMaxDegree(); ++i)
        {
            if (funcCopy.getCoef(i) == 0) continue;
            this->push_tail(*(new Node<T>(funcCopy.getCoef(i), i)));
        }
    }
    //DoublyLinkedList(size_t length) {
    //    //std::cout << typeid(T).name() << std::endl;
    //    if (typeid(T).name() == "float" ||
    //        typeid(T).name() == "double")
    //    {  
    //        this->randomPasteDouble(length);
    //    }
    //    else if(typeid(T).name() == "int") {
    //        this->randomPasteInt(length);
    //    }


    //    //if (length == 0) return;
    //    //std::random_device rd;   // non-deterministic generator
    //    //std::mt19937 gen(rd());  // to seed mersenne twister.
    //    //std::uniform_real_distribution<> dist(0, 20);
    //    //if (length == 1) {
    //    //    this->_first = new Node<T>(dist(gen), 0);
    //    //    this->_last = this->_first;
    //    //    this->_first->setNext(this->_last);
    //    //    this->_first->setPrev(this->_last);
    //    //    return;
    //    //}
    //    //this->_first = new Node<T>(dist(gen), 0);
    //    //this->_last = new Node<T>(dist(gen), 1);
    //    //this->_first->setNext(this->_last);
    //    //this->_first->setPrev(this->_last);
    //    //this->_last->setNext(this->_first);
    //    //this->_last->setPrev(this->_first);
    //    //this->_countNodes = 2;
    //    //for (size_t i = 2; i < length; ++i)
    //    //{
    //    //    this->push_tail(*(new Node<T>(dist(gen), i)));
    //    //}
    //}
    void push_tail(T value) {
        if (this->_first == nullptr) {
            this->_first = new Node<T>(value, this->_countNodes);
            this->_first->setNext(this->_first);
            this->_first->setPrev(this->_first);
            this->_last = this->_first;
            this->_countNodes++;
            return;
        }
        this->_last->setNext(new Node<T>(value, this->_countNodes));
        this->_last->getNext()->setPrev(this->_last);
        this->_last = this->_last->getNext();
        this->_last->setNext(this->_first);
        this->_first->setPrev(this->_last);
        this->_countNodes++;
        return;
    }
    void push_tail(Node<T>& node) {
        if (this->_first == nullptr) {
            this->_first = &node;
            this->_first->setNext(this->_first);
            this->_first->setPrev(this->_first);
            this->_last = this->_first;
            this->_countNodes++;
            return;
        }
        this->_last->setNext(&node);
        this->_last->getNext()->setPrev(this->_last);
        this->_last = this->_last->getNext();
        this->_last->setNext(this->_first);
        this->_first->setPrev(this->_last);
        this->_countNodes++;
        return;
    }
    // вставляет другой список в конец данного,
    // ВАЖНО: !!!метод использует новую память, в отличие от изначального списка!!!
    void push_tail(const DoublyLinkedList& list) {
        for (size_t i = 0; i < list.getCountNodes(); i++)
        {
            Node<T>* item = new Node<T>(list.findInInd(i)->getValue(), list.findInInd(i)->getDegree());
            this->_last->setNext(item);
            this->_last->getNext()->setPrev(this->_last);
            this->_last = this->_last->getNext();
            this->_last->setNext(this->_first);
            this->_first->setPrev(this->_last);
        }
        this->_countNodes += list.getCountNodes();
    }
    void push_head(T value) {
        if (this->_first == nullptr) {
            this->_first = new Node<T>(value);
            this->_first->setNext(this->_first);
            this->_first->setPrev(this->_first);
            this->_last = this->_first;
            this->_countNodes++;
            return;
        }
        this->_first->setPrev(new Node<T>(value));
        this->_first->getPrev()->setNext(this->_first);
        this->_first = this->_first->getPrev();
        this->_first->setPrev(this->_last);
        this->_last->setNext(this->_first);
        this->_countNodes++;
        return;
    }
    void push_head(Node<T>& node) {
        if (this->_first == nullptr) {
            this->_first = &node;
            this->_first->setNext(this->_first);
            this->_first->setPrev(this->_first);
            this->_last = this->_first;
            this->_countNodes++;
            return;
        }
        this->_first->setPrev(&node);
        this->_first->getPrev()->setNext(this->_first);
        this->_first = this->_first->getPrev();
        this->_first->setPrev(this->_last);
        this->_countNodes++;
        return;
    }
    // вставляет другой список в начало данного,
    // ВАЖНО: !!!метод использует новую память, в отличие от изначального списка!!!
    void push_head(const DoublyLinkedList& list) {
        for (int i = list.getCountNodes() - 1; i >= 0; --i)
        {
            Node<T>* item = new Node<T>(list.findInInd(i)->getValue(), list.findInInd(i)->getDegree());
            this->_first->setPrev(item);
            this->_first->getPrev()->setNext(this->_first);
            this->_first = this->_first->getPrev();
            this->_last->setNext(this->_first);
            this->_first->setPrev(this->_last);
        }
        this->_countNodes += list.getCountNodes();
    }
    Node<T>* pop_head() {
        this->_last->setNext(this->_first->getNext());
        Node<T>* newFirst = this->_first->getNext();
        newFirst->setPrev(this->_last);
        delete this->_first;
        this->_first = newFirst;
        this->_countNodes--;
        return this->_first;
    }
    Node<T>* pop_tail() {
        this->_first->setPrev(this->_last->getPrev());
        Node<T>* newLast = this->_last->getPrev();
        newLast->setNext(this->_first);
        delete this->_last;
        this->_last = newLast;
        this->_countNodes--;
        return this->_last;
    }
    void delete_node(std::string info) {
        for (int i = this->getCountNodes() - 1; i >= 0; --i)
        {
            this->pop_head();
        }
        std::cout << "\n" << info << "\n";
    }
    void print() const {
        auto node = this->_first;
        for (size_t i = 1; i <= this->_countNodes; ++i) {
            std::cout << i << ") ";
            node->print();
            std::cout << std::endl;
            node = node->getNext();
        }
    }
    Node<T>* getFirst() const { return this->_first; }
    Node<T>* getLast() const { return this->_last; }
    size_t getCountNodes() const { return this->_countNodes; }
    Node<T>* findInInd(size_t index) const {
        if (index < this->_countNodes) {
            Node<T>* node = this->_first;
            for (size_t i = 0; i != index; i++)
            {
                node = node->getNext();
            }
            return node;
        }
        return nullptr;
    }
    Node<T>* findInVal(T val) const {
        Node<T>* node = this->_first;
        for (size_t i = 0; i != this->_countNodes; i++)
        {
            if (node->getValue() == val) {
                return node;
            }
            node = node->getNext();
        }
        return nullptr;
    }
    void swap(DoublyLinkedList<T>& el_1, DoublyLinkedList<T>& el_2) {
        el_1.setFirst(el_2.getFirst());
        el_1.setLast(el_2.getLast());
        el_1.setCountNodes(el_2.getCountNodes());
        return;
    }
    DoublyLinkedList<T>& operator=(DoublyLinkedList<T> other)
    {
        this->swap(*this, other);
        return *this;
    }
    DoublyLinkedList<T>& operator+= (Node<T>* node) {
        this->push_tail(*node);
        return *this;
    }
    bool operator==(const DoublyLinkedList& other) const
    {
        if (!(this->getFirst()->getValue() == other.getFirst()->getValue() && 
            this->getLast()->getValue() == other.getLast()->getValue()) &&
            this->getCountNodes() == other.getCountNodes()) 
        { return false; }

        Node<T>* item_1 = this->getFirst()->getNext();
        Node<T>* item_2 = other.getFirst()->getNext();
        for (size_t i = 1; i <= this->getCountNodes(); ++i)
        {
            if (item_1->getValue() == item_2->getValue()) { 
                item_1 = item_1->getNext();
                item_2 = item_2->getNext();
                continue; 
            }
            else { return false; }
        }
    }
    
    ~DoublyLinkedList() {
        Node<T>* node = this->_first;
        for (size_t i = 1; i <= this->_countNodes; ++i)
        {
            Node<T>* next = node->getNext();
            delete node;
            node = next;
        }
    }
};

template<typename T>
double resultOfPolinomial(const DoublyLinkedList<T>& list, double x) {
    double res = 0;
    for (size_t i = 0; i < list.getCountNodes(); ++i)
    {
        res += list.findInInd(i)->getValue() * powl(x,list.findInInd(i)->getDegree());
    }
    return res;
}