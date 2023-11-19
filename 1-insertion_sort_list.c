#include "sort.h"
/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 * @list: address of pointer to head node
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i;

	if (list == NULL || (*list)->next == NULL)
		return;
	i = (*list)->next;
	while (i)
	{
		while ((i->prev) && (i->prev->n > i->n))
		{
			i = swap_node(i, list);
			print_list(*list);
		}
		i = i->next;
	}
}
/**
 *swap_node - swap 2 nodes in doubly linked list
 *@a: first node address
 *@b: second node address
 *Return: Return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *a, listint_t **b)
{
	listint_t *back = a->prev, *current = a;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*b = current;
	return (current);
}
