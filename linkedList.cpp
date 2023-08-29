#include "linkedList.h"
#include <iostream>

void DoublyLinkedList::push_back(int val) { 
 DoublyLinkedList::Node* newNode = new DoublyLinkedList::Node();
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        head->value = val;
        head->prev = nullptr; 
        ++size;
    }else {
        DoublyLinkedList::Node*  current = head;
          while(current -> next != nullptr) {
            current  = current -> next;
        }
        current->next = newNode; 
        newNode->prev = current;
        newNode->value = val;
        tail = newNode;
        ++size;

    }
}

void DoublyLinkedList::push_front(int val) {
   DoublyLinkedList::Node* newNode = new DoublyLinkedList::Node();
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        head->value = val;
        head->prev = newNode->prev; 
        ++size;
    }else {
        DoublyLinkedList::Node*  current = head;
          while(current->prev != nullptr) {
            current  = current -> prev;
        }
        current->prev = newNode; 
        current->prev->next = current;
       newNode->value = val;
        head = newNode;
        ++size;

    }
}

void DoublyLinkedList::insert(int index, int val) {
  if (index < 0 || index >= size) {
    throw std::invalid_argument("index out of range!:");
    std::exit(1);
  }
  DoublyLinkedList::Node* newNode = new DoublyLinkedList::Node();
  
  if (size == 0) {
    head = newNode;
    tail = newNode;
    head->value = val;
    ++size;
    return;
  }
  
  DoublyLinkedList::Node* current = head;
  for (int in = 0; in < index; ++in) {
    current = current->next;
  }
  
  if (current == head) {
    newNode->next = current;
    current->prev = newNode;
    head = newNode;
    head->value = val;
  } else {
    current->prev->next = newNode;
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev = newNode;
  }
  
  if (current == tail) {
    tail = newNode;
    tail->value = val;
  } else {
   newNode->value = val;
  }
  ++size;
}

void DoublyLinkedList::remove_node(int index) {
  if (index < 0 || index >= size) {
    throw std::invalid_argument("Index out of range");
    std::exit(1);
  }
  
  if (size == 0) {
    return;
  }
  
  DoublyLinkedList::Node* indexToRem = head;
  for (int in = 0; in < index; ++in) {
   indexToRem = indexToRem->next; 
  }
  if (indexToRem == head){
    head = indexToRem->next;
  } else {  
    indexToRem->prev->next = indexToRem->next; 
  }
  
  if (indexToRem == tail) {
    tail = indexToRem->prev;  
  } else {
    indexToRem->next->prev = indexToRem->prev; 
  }
  delete indexToRem;
  --size;
}

int DoublyLinkedList::get(int index) {
  if (index < 0 || index >= size) {
    throw std::invalid_argument("Index out of range");
    std::exit(1);
  }
  
  if (size == 0) {
    return;
  }
  
  int valueAtIndex {};
  DoublyLinkedList::Node* indexToGet= head;
  for (int in = 0; in < index; ++in) {
   indexToGet = indexToGet->next; 
  }
  valueAtIndex = indexToGet->value;
  return valueAtIndex;
}

void DoublyLinkedList::printList() {
  DoublyLinkedList::Node*  current = head;
  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

void DoublyLinkedList::printReverse() {
  DoublyLinkedList::Node*  current = tail;
  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->prev;
  }
    std::cout << std::endl;
}

DoublyLinkedList::~DoublyLinkedList() {
   DoublyLinkedList::Node*  current = head;
  while (current != nullptr) {
        DoublyLinkedList::Node*  current = head;   
        delete current;
        current = current->next;
  }
  head = nullptr;
  tail = nullptr;
  size = 0;
}