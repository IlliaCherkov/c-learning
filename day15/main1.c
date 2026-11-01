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
    current = current->next;

  current->next = new_node;
}

void print_list(Node *head)
{
  Node *current;
  current = head;

  while (current != NULL)
  {
    printf("%d\n", current->data);
    current = current->next;
  }
}
int list_length(Node *head)
{
  Node *current;
  current = head;
  int count = 0;

  while (current != NULL)
  {
    count++;
    current = current->next;
  }
  return count;
}

int search(Node *head, int value)
{
  Node *current;
  current = head;

  while (current != NULL)
  {

    if (current->data == value)
    {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

Node *max_value(Node *head)
{
  Node *current;
  current = head;
  if (current == NULL)
    return NULL;
  Node *max;
  max = current;

  while (current != NULL)
  {

    if (current->data >= max->data)
    {
      max = current;
    }
    current = current->next;
  }

  return max;
}

void prepend(Node **head, int value)
{
  Node *new_node = create_node(value);

  new_node->next = *head;
  *head = new_node;
}

void delete_first(Node **head)
{
  if (*head == NULL)
    return;

  Node *current = *head;
  Node *next;
  next = current->next;
  free(current);
  *head = next;
}
// task 6;

int get_at(Node *head, int value, int *data)
{
  Node *current = head;
  int count = 0;
  while (count != value)
  {
    count++;
    if (current == NULL)
    {
      break;
    }
    current = current->next;
  }
  if (current == NULL)
  {
    return 0;
  }
  else
  {
    *data = current->data;

    return 1;
  }
}

int main(void)
{

  int x = 3;
  int y = 7;
  int z = 1;
  int i = 1;
  int t = 2;
  int c = 3;

  Node *f = NULL;

  append(&f, x);
  append(&f, y);
  append(&f, z);
  // prepend(&f, i);
  // prepend(&f, t);
  // prepend(&f, c);

  // delete_first(&f);

  Node *max = max_value(f);

  print_list(f);

  printf("Number of blocks : %d\n", list_length(f));

  printf("Data inside : %d\n", search(f, -5));

  if (max == NULL)
  {
    printf("The list is empty.\n");
  }
  else
  {
    printf("max number : %d\n", max->data);
  }

  int result = 0;
  if (get_at(f, 2, &result) == 1)
  {
    printf("Result :%d\n", result);
  }
  else
  {
    printf("we don`t have such number=(\n");
  }

  free_list(&f);
}