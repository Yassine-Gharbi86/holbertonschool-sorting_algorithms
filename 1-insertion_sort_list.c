#include "sort.h"
/**
* insertion_sort_list - Sorts a doubly linked list of integers
* in ascending order using the Insertion sort algorithm.
* @list: A pointer to the head of the list.
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *prev_node;
if (!list || !(*list) || !(*list)->next)
return;
current = (*list)->next;
while (current)
{
prev_node = current->prev;
while (prev_node && prev_node->n > current->n)
{
if (prev_node->prev)
prev_node->prev->next = current;
if (current->next)
current->next->prev = prev_node;
current->prev = prev_node->prev;
prev_node->next = current->next;
current->next = prev_node;
prev_node->prev = current;
if (!current->prev)
*list = current;
print_list(*list);
}
current = current->next;
}
}
