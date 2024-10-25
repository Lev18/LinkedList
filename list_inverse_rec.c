#include <stdlib.h>

typedef struct Node{
  int value;
  struct Node* next;
}Node;


Node* init_node(int node_amount, int* values) {
  Node* head = (Node*)malloc(sizeof(Node));
  Node* iter = head;
  
  int in = 0;
  while (in < node_amount - 1) {
    iter->next = (Node*)malloc(sizeof(Node));
    iter->value = values[in];
    iter = iter->next;
    ++in;
  }
  
  iter->value = values[in];
  iter->next = NULL;
  return head;
}

Node* rec_rev(Node* head) {
  
  if (head->next == NULL) {
    return head;
  }
  
  // n_node is head next node
  Node* n_node = head->next;
  // keeping new head 
  Node* new_head = rec_rev(head->next);
  
  //this part is working after recursion goes to the list end
  n_node->next = head;
  head->next = NULL;
  
  return new_head;
}

int main() {
  int values[] = {4, 5, 6, 7};
  Node* head = init_node(4, values);
  Node* rev_list = rec_rev(head);

  return 0;
}
