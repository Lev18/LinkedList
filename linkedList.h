#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
  void insert(int index, int val);
  void remove_node(int index); 
  int get(int index);
  void printList();
  void printReverse();
};

#endif