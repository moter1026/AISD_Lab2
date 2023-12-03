

#include <iostream>
#include <string>

template <typename T>
class Node {
private:
    T _val;
    Node<T>* _next;
    Node<T>* _prev;
public:
    // Конструктор по уполчанию п.1 общ часть
    Node() = default;
    // Конструктор копирования п.2 общ часть
    Node(Node& const node) {
        this->_val = node.getValue();
        this->_next = node.getNext();
        this->_prev = node.getPrev();
    }
    Node(T val) {
        this->_val = val;
        this->_next = nullptr;
        this->_prev = nullptr;
    }
    Node(T val, Node<T>* prev) {
        this->_val = val;
        this->_next = nullptr;
        this->_prev = prev;
    }
    
    Node(const T& _val, Node<T>* _next, Node<T>* _prev) :
        _val(_val), _next(_next), _prev(_prev) {}
    Node<T>* getNext() const{
        return this->_next;
    }
    void setNext(Node<T>* next) {
        this->_next = next;
        return;
    }
    Node<T>* getPrev() const {
        return this->_prev;
    }
    void setPrev(Node<T>* prev) {
        this->_prev = prev;
        return;
    }
    T getValue() const {
        return this->_val;
    }
    void setValue(T value) {
        this->_val = value;
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
protected:
    void setFirst(const Node<T>* const first) {
        this->_first = first;
        return;
    }
    void setLast(const Node<T>* const last) {
        this->_last = last;
        return;
    }
    void setCountNodes(const size_t& const countNodes) {
        this->_countNodes = countNodes;
        return;
    }
public:
    DoublyLinkedList() :_first(nullptr), _last(nullptr), _countNodes(0) {}
    DoublyLinkedList(const DoublyLinkedList& list) {
        this->_first = list._first;
        this->_last = list._last;
        this->_countNodes = list._countNodes;
    }
    DoublyLinkedList(Node<T>* _first, Node<T>* _last, const size_t& _countNodes):
        _first(_first), _last(_last), _countNodes(_countNodes){}
    void push_tail(T value) {
        if (this->_first == nullptr) {
            this->_first = new Node<T>(value);
            this->_first->setNext(this->_first);
            this->_first->setPrev(this->_first);
            this->_last = this->_first;
            this->_countNodes++;
            return;
        }
        this->_last->setNext(new Node<T>(value));
        this->_last->setPrev(this->_last);
        this->_last = this->_last->getNext();
        this->_first->setPrev(this->_last);
        this->_countNodes++;
        return;
    }
    void push_tail(const Node<T>& node) {
        if (this->_first == nullptr) {
            this->_first = node;
            this->_first->setNext(this->_first);
            this->_first->setPrev(this->_first);
            this->_last = this->_first;
            this->_countNodes++;
            return;
        }
        this->_last->setNext(node);
        this->_last->setPrev(this->_last);
        this->_last = this->_last->getNext();
        this->_first->setPrev(this->_last);
        this->_countNodes++;
        return;
    }
    // вставляет другой список в конец данного,
    // ВАЖНО: !!!метод использует те же указатели, что и изначальный список!!!
    void push_tail(const DoublyLinkedList& list) {
        if (list.getFirst() == nullptr) { return; }
        if (this->_first == nullptr) {
            *this = list;
        }
        this->_last->setNext(list.getFirst());
        this->_last = list.getLast();
        this->_first->setPrev(this->_last);
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
        this->_countNodes++;
        return;
    }
    void push_head(const Node<T>& node) {
        if (this->_first == nullptr) {
            this->_first = node;
            this->_first->setNext(this->_first);
            this->_first->setPrev(this->_first);
            this->_last = this->_first;
            this->_countNodes++;
            return;
        }
        this->_first->setPrev(node);
        this->_first->getPrev()->setNext(this->_first);
        this->_first = this->_first->getPrev();
        this->_first->setPrev(this->_last);
        this->_countNodes++;
        return;
    }
    // вставляет другой список в начало данного,
    // ВАЖНО: !!!метод использует те же указатели, что и изначальный список!!!
    void push_head(const DoublyLinkedList& list) {
        if (list.getFirst() == nullptr) { return; }
        if (this->_first == nullptr) {
            *this = list;
        }
        this->_first->setPrev(list.getLast());
        this->_first->getPrev()->setNext(this->_first);
        this->_first = list.getFirst();
        this->_first->setPrev(this->_last);
        this->_last->setNext(this->_first);
        this->_countNodes++;
        return;
    }
    Node<T>* pop_head() {
        this->_last->setNext(this->_first->getNext());
        Node<T>* newFirst = this->_first->getNext();
        newFirst->setPrev(this->_last);
        delete this->_first;
        this->_first = newFirst;
        return this->_first;
    }
    Node<T>* pop_tail() {
        this->_first->setPrev(this->_last->getPrev());
        Node<T>* newLast = this->_last->getPrev();
        newLast->setNext(this->_first);
        delete this->_last;
        this->_last = newLast;
        return this->_last;
    }
    void delete_node(std::string info) {
        for (size_t i = 0; this->getCountNodes() != 0; --(this->getCountNodes()))
        {
            this->pop_head();
        }
        std::cout << "\n" << info << "\n";
    }
    void print() const {
        auto node = this->_first;
        for (size_t i = 0; node != nullptr; ++i) {
            std::cout << i << ") ";
            node->print();
            std::cout << std::endl;
            node = node->getNext();
        }
    }
    Node<T>* getFirst() const { return this->_first; }
    Node<T>* getLast() const { return this->_last; }
    Node<T>* getCountNodes() const { return this->_countNodes; }
    Node<T>* findInInd(size_t index) {
        if (index < this->_countNodes) const {
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
    DoublyLinkedList<T>& operator+= (Node<T>& node) {
        if (this->_first == nullptr) {
            this->_first = &node;
            this->_last = this->_first;
            this->_countNodes++;
            return *this;
        }
        this->_last->setNext(&node);
        this->_last = this->_last->getNext();
        this->_countNodes++;
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
        while (node != nullptr) {
            Node<T>* next = node->getNext();
            delete node;
            node = next;
        }
    }
};


