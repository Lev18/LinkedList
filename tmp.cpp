#include <iostream>

class DoublyLinkedList {
private:
    int size; 
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node() : value(0), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) {}
 void push_back(int value);
 void push_front(int val);
 void remove_node(int index);
 void insert(int index, int val);
 void printList();
 void printReverse();
    // Define other member functions here, like push_front, push_back, insert, remove, etc.
};

void DoublyLinkedList::push_back(int val) { 
 DoublyLinkedList::Node* newTask = new DoublyLinkedList::Node();
    if(head == nullptr) {
        head = newTask;
        tail = newTask;
        head->value = val;
        head->prev = nullptr; 
        ++size;
    }else {
        DoublyLinkedList::Node*  current = head;
          while(current -> next != nullptr) {
            current  = current -> next;
        }
        current->next = newTask; 
        newTask->prev = current;
        newTask->value = val;
        tail = newTask;
        ++size;

    }
}

void DoublyLinkedList::push_front(int val) {
   DoublyLinkedList::Node* newTask = new DoublyLinkedList::Node();
    if(head == nullptr) {
        head = newTask;
        tail = newTask;
        head->value = val;
        head->prev = newTask->prev; 
        ++size;
    }else {
        DoublyLinkedList::Node*  current = head;
          while(current->prev != nullptr) {
            current  = current -> prev;
        }
        current->prev = newTask; 
        current->prev->next = current;
        newTask->value = val;
        head = newTask;
        ++size;

    }
}

void DoublyLinkedList::insert(int index, int val) {
  if (index < 0 || index >= size) {
    throw std::invalid_argument("index out of range!:");
    std::exit(1);
  }
  DoublyLinkedList::Node* newTask = new DoublyLinkedList::Node();
  
  if (size == 0) {
    head = newTask;
    tail = newTask;
    head->value = val;
    ++size;
    return;
  }
  
  DoublyLinkedList::Node* current = head;
  for (int in = 0; in < index; ++in) {
    current = current->next;
  }
  
  if(current == head) {
    newTask->next = current;
    current->prev = newTask;
    head = newTask;
    head->value = val;
  } else {
    current->prev->next = newTask;
    newTask->next = current;
    newTask->prev = current->prev;
    current->prev = newTask;
  }
  
  if(current == tail) {
    tail = newTask;
    tail->value = val;
  } else {
    newTask->value = val;
  }
}

void DoublyLinkedList::remove_node(int index) {
  if(index < 0 || index >= size) {
    throw std::invalid_argument("Index out of range");
    std::exit(1);
  }
  
  if(size == 0) {
    return;
  }
  
  DoublyLinkedList::Node* indexToRem = head;
  for(int in = 0; in < index; ++in) {
   indexToRem = indexToRem->next; 
  }
  if(indexToRem == head){
    head = indexToRem->next;
  } else {  
    indexToRem->prev->next = indexToRem->next; 
  }
  
  if(indexToRem == tail) {
    tail = indexToRem->prev;  
  } else {
    indexToRem->next->prev = indexToRem->prev; 
  }
  delete indexToRem;
  --size;
}

void DoublyLinkedList::printList() {
  DoublyLinkedList::Node*  current = head;
  while(current != nullptr) {
    std::cout << current->value;
    current = current->next;
  }
  std::cout << std::endl;
}

void DoublyLinkedList::printReverse() {
  DoublyLinkedList::Node*  current = tail;
  while(current != nullptr) {
    std::cout << current->value;
    current = current->prev;
  }
    std::cout << std::endl;
}

int main() {
    DoublyLinkedList l1; 
    DoublyLinkedList l2;
    l1.push_front(4);
     l1.push_front(7);
     l1.push_front(8);
    l2.push_back(5);
    l2.push_back(15);
    l2.push_back(4);
    l1.printList();
    l1.printReverse();
    // You can now call methods on the l1 instance
    }
