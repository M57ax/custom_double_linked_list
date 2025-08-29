#include "list.hpp"

#include <cstddef>
#include <iostream>
#include <stdexcept>

List::List() : head(nullptr), tail(nullptr), m_size(0) {} 

void List::clear() {
    Node* currentVal = head;
    while (currentVal) {
        Node* next = currentVal->next;
        delete currentVal;
        currentVal = next;
    }
    head = nullptr;
    tail = nullptr;
    m_size = 0;
}

void List::copyFrom(const List& other) {
    Node* currentOth = other.head;
    while (currentOth) {
        int val = currentOth->data;
        push_back(val);
        currentOth = currentOth->next;
    }
}

bool List::operator==(const List& other) const {
    if (m_size != other.m_size) {
        std::cout << "Listen sind nicht gleich" << std::endl;
        return false;
    } 

    Node* a = head;
    Node* b = other.head;
    while ( a && b) {
        if( a->data != b->data ) {
            std::cout << "UNGLEICH" << std::endl;
            return false;
        } else {
            a = a->next;
            b = b->next;
        }
    } 
    std::cout << "Gleich" << std::endl;
    return true;
}

List& List::operator=(const List& other) {
    std::cout << "Assign" << std::endl;
    clear();
    copyFrom(other);
    return *this;
}

List::List(const List& other) {
    std::cout << "Copy" << std::endl;
    copyFrom(other);
}

void List::push_back(int value) {
    Node* newNode = new Node(value); // legt objekt in heap an und eben zeiger auf erzeuge node
    if (!head) {
        head = newNode;    
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    m_size++;
}

void List::push_front(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head; //neu zeigt auf alten
        head->prev = newNode; //alt zeigt auf neu
        head = newNode; //anfang dem neuen zuweisen 
    }
    m_size++;
}

void List::pop_back() {
    if (!tail) {
        return ;
    }
    Node* toDelete = tail;
    Node* newEnd = tail->prev;
    if (newEnd) {
        newEnd->next = nullptr;      //end hat kein nachfolger mehr
        tail = newEnd; 
    } else {
        head = nullptr;
        tail = nullptr;
    }
    m_size--;
    delete toDelete;
}

void List::insert_at(int pos, int value) {
    Node* newNode = new Node(value);
    Node* current = head;
}

void List::pop_front() {
    if (!head) {return;}
    Node* toDelete = head;
    Node* newBegin = head->next;

    if(newBegin) {
        newBegin->prev = nullptr;
        head = newBegin;
    } else {
        head = nullptr;
        tail = nullptr;
    }
    m_size--;
    delete toDelete;
}

int List::front() {
    if (!head) {
        throw std::runtime_error("Liste ist leer");
    } else {
    return head->data;
    }
}

int List::back() {
    if (!tail) {
        throw std::runtime_error("Liste ist leer");
    } else {
        return tail->data;
    }
}

void List::print() {
    Node* currentVal = head;
    while (currentVal) {
        std::cout << currentVal->data << " ";
        currentVal = currentVal->next;
    }
    std::cout << "\n";
}


void List::size() {
    std::cout << "Die größe der Liste beträgt: " << m_size << std::endl;
}

List::~List() {
    clear();
}
