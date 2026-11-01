#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *create_node(int value)
{
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL)
    exit(1);

  new_node->data = value;
  new_node->next = NULL;
  return new_node;
}

void free_list(Node **head)
{
  Node *current = *head;
  while (current != NULL)
  {
    Node *next = current->next;
    free(current);
    current = next;
  }
  *head = NULL;
}

void append(Node **head, int value)
{
  Node *new_node = create_node(value);
  if (*head == NULL)
  {
    *head = new_node;
    return;
  }

  Node *current = *head;
  while (current->next != NULL)
  {
    current = current->next;
  }
  current->next = new_node;
}

int main(void)
{
}