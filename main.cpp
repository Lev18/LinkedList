#include "linkedList.h"

int main() {
    DoublyLinkedList l1; 
    DoublyLinkedList l2;
    l1.push_front(4);
    l1.push_front(7);
    l1.push_front(8);
    l2.push_back(5);
    l2.push_back(15);
    l2.push_back(4);
    l2.remove_node(2);
    l1.insert(2,15);
    l1.printList();
    l2.printReverse();
}