#include <iostream>
#include "list.hpp"

int main() {
List list;
list.push_back(20);

list.print();


list.push_front(15);
list.print();

list.push_back(55);
list.print();
list.push_back(25);
list.print();
list.pop_back();
list.print();
list.pop_front();
list.print();
list.size();

list.front();
list.back();
}
