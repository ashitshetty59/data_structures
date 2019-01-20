#include <stdio.h>
#include <stdlib.h>

struct node_ {
  int data;
  struct node_ *next;
};
typedef struct node_ node;

node *add_node(node **head_ptr, int value) {
  node *new_node = (node *)malloc(sizeof(node));

  new_node->data = value;
  new_node->next = *head_ptr;
  *head_ptr = new_node;
  return new_node;
}

void delete_node(node **head_ptr, node *entry) {
  node **traverse = head_ptr;
  while ( *traverse != entry) {
    traverse = &(*traverse)->next;
  }
  printf("%d\n", (*traverse)->data);
  *traverse = entry->next;
  free(entry);
}

void display_list(node *traverse) {
  if (traverse == NULL) {
    printf("empty list\n");
    return;
  }

  printf("head->");
  while (traverse != NULL) {
    printf("%d->", traverse->data);
    traverse = traverse->next;
  }
  printf("null\n");
}

int main(void) {
  node *head = NULL;
  node *n1;
  display_list(head);
  add_node(&head, 2);
  display_list(head);
  add_node(&head, 3);
  display_list(head);
  add_node(&head, 4);
  n1 = add_node(&head, 5);
  add_node(&head, 6);
  add_node(&head, 7);
  display_list(head);
  delete_node(&head, n1);
  display_list(head);
  return 0;
}
