#include "list.hpp"

#include <cstddef>
#include <iostream>
#include <stdexcept>

List::List() : begin(nullptr), end(nullptr), m_size(0) {} 

bool List::operator==(const List& other) const {
    if (m_size != other.m_size) {
        std::cout << "Listen sind nicht gleich" << std::endl;
        return false;
        
    } 
    Node* a = begin;
    Node* b = other.begin;
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
// Mein Fehler war, dass ich es nicht geschnallt habe, dass L2 hier ja der linken seite ist.
// So wird nun erstmal L2 leer geräumt, (wie bei destruktor).
// 
List& List::operator=(const List& other) {
    std::cout << "Assign" << std::endl;
    Node* currentVal = begin;
    while (currentVal) {
        Node* next = currentVal->next;
        delete currentVal;
        currentVal = next;
    }
    begin = nullptr;
    end = nullptr;
    m_size = 0; 

    Node* currentOth = other.begin;
    while (currentOth) {
        int val = currentOth->data;
        push_back(val);
        currentOth = currentOth->next;
    }
    return *this;
    
}

List::List(const List& other) {
    std::cout << "Copy" << std::endl;
    Node* currentOth = other.begin;
    while (currentOth) {
        int val = currentOth->data;
        push_back(val);
        currentOth = currentOth->next;
    }
}

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
    if (!end) {
        return ;
    }
    Node* toDelete = end;
    Node* newEnd = end->prev;
    if (newEnd) {
        newEnd->next = nullptr;      //end hat kein nachfolger mehr
        end = newEnd; 
    } else {
        begin = nullptr;
        end = nullptr;
    }
    m_size--;
    delete toDelete;
}

void List::insert_at(int pos, int value) {
    Node* newNode = new Node(value);
    Node* current = begin;
}

void List::pop_front() {
    if (!begin) {return;}
    Node* toDelete = begin;
    Node* newBegin = begin->next;

    if(newBegin) {
        newBegin->prev = nullptr;
        begin = newBegin;
    } else {
        begin = nullptr;
        end = nullptr;
    }
    m_size--;
    delete toDelete;
}

int List::front() {
    if (!begin) {
        throw std::runtime_error("Liste ist leer");
    } else {
    return begin->data;
    }
}

int List::back() {
    if (!end) {
        throw std::runtime_error("Liste ist leer");
    } else {
        return end->data;
    }
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

List::~List() {
    Node* currentVal = begin;
    while (currentVal) {
        Node* next = currentVal->next;
        delete currentVal;
        currentVal = next;
    }
    begin = nullptr;
    end = nullptr;
    m_size = 0;
}
