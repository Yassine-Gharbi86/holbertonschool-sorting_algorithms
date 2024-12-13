#include "sort.h"
/**
* swap_nodes - Swap two nodes in a doubly linked list of integers.
* @head: A pointer to the head of the doubly linked list.
* @first: A pointer to the first node to swap.
* @second: The second node to swap.
*/
void swap_nodes(listint_t **head, listint_t **first, listint_t *second)
{
(*first)->next = second->next;
if (second->next != NULL)
second->next->prev = *first;
second->prev = (*first)->prev;
second->next = *first;
if ((*first)->prev != NULL)
(*first)->prev->next = second;
else
*head = second;
(*first)->prev = second;
*first = second->prev;
}
/**
* insertion_sort_list - Sort a doubly linked
* list of integers in ascending order.
* @list: A pointer to the head of the doubly linked list.
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *insert_position, *next_node;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
for (current = (*list)->next; current != NULL; current = next_node)
{
next_node = current->next;
insert_position = current->prev;
while (insert_position != NULL && current->n < insert_position->n)
{
swap_nodes(list, &insert_position, current);
print_list((const listint_t *)*list);
}
}
}
