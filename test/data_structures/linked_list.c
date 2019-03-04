#include <stdio.h>
#include <stdlib.h>

typedef struct node_ node;
struct node_ {
  int data;
  node *next;
};

node *add_node(node **head_ptr, int value)
{
  node *new_node = (node*)malloc(sizeof(node));

  new_node->data = value;
  new_node->next = *head_ptr;
  *head_ptr = new_node;
  return new_node;
}

node *add_node_pos(node **head_ptr, int value, int n)
{
  node **traverse = head_ptr;
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = value;

  for (int i = 1; i < n && *traverse != NULL; i++)
    {
      traverse = &(*traverse)->next;
    }
  new_node->next = *traverse;
  *traverse = new_node;
  return new_node;
}

void delete_node(node **head_ptr, node *entry)
{
  node **traverse = head_ptr;

  while (*traverse != entry)
    {
      traverse = &(*traverse)->next;
    }
  printf("%d\n", (*traverse)->data);
  *traverse = entry->next;
  free(entry);
}

void delete_node_pos(node **head_ptr, int n)
{
  node **traverse = head_ptr;
  node *node_to_delete;
  for (int i = 1; i < n; i++)
    {
      traverse = &(*traverse)->next;
    }
  node_to_delete = *traverse;
  *traverse = (*traverse)->next;
  free(node_to_delete);
}

void display_list(node *traverse)
{
  if (traverse == NULL)
    {
      printf("empty list\n");
      return;
    }

  printf("head->");
  while (traverse != NULL)
    {
      printf("%d->", traverse->data);
      traverse = traverse->next;
    }
  printf("null\n");
}

int main(void)
{
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
  add_node_pos(&head, 8, 6);
  display_list(head);
  delete_node_pos(&head, 9);
  display_list(head);

  return 0;
}
