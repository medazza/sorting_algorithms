#include "sort.h"

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

/**
 *cocktail_sort_list - this is a cocktail sort algorithm
 *                   working on a double-linked lists
 *@list: list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swp_done = 1;

	if (!list || !(*list) || !(*list)->next)
		return;
	node = *list;
	while (swp_done == 1)
	{
		swp_done = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swp_done = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swp_done == 0)
			break;
		swp_done = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swp_done = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
