#include "list.hpp"

#include <iostream>

List::List() : begin(nullptr), end(nullptr), m_size(0){} 

void List::push_back(int value) {
    Node* newNode = new Node(value); // legt objekt in heap an und eben zeiger auf erzeuge node
    if (!begin) {
        begin = newNode;    
        end = newNode;
    } else {
        newNode->prev = end;
        end->next = newNode;
        end = newNode;
    }
    m_size++;
}

void List::push_front(int value) {
    Node* newNode = new Node(value);
    if (!begin) {
        begin = newNode;
        end = newNode;
    } else {
        newNode->next = begin; //neu zeigt auf alten
        begin->prev = newNode; //alt zeigt auf neu
        begin = newNode; //anfang dem neuen zuweisen 
    }
    m_size++;
}

void List::pop_back() {
    Node* toDelete = end;
    Node* newEnd = end->prev;
    if (newEnd) {
        newEnd->next = nullptr;      //end hat kein nachfolger mehr
        end = newEnd; 
    }
    m_size--;
}

void List::pop_front() {
    Node* toDelete = begin;
    Node* newBegin = begin->next;

    if(newBegin) {
        newBegin->prev = nullptr;
        begin = newBegin;
    }
    m_size--;
    delete toDelete;
}

void List::front() {
    std::cout << "Startwert: " << begin->data << std::endl;
}

void List::back() {
    std::cout << "Endwert: " << end->data << std::endl;
}

void List::print() {
    Node* currentVal = begin;
    while (currentVal) {
        std::cout << currentVal->data << " ";
        currentVal = currentVal->next;
    }
    std::cout << "\n";
}


void List::size() {
    std::cout << "Die größe der Liste beträgt: " << m_size << std::endl;
}
