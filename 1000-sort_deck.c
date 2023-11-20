#include "deck.h"
#include <stdio.h>
/**
 *_strcmp - compare two strings
 *@str1: first string
 *@str2: second string
 *Return: 1 str1 and str2 is equal, 0 they are not equal
 */
int _strcmp(const char *str1, char *str2)
{
	size_t ind = 0;

	if (str1[ind] == '\0')
		return (0);
	while (str1[ind])
	{
		if (str1[ind] != str2[ind])
			return (0);
		ind++;
	}
	if (str1[ind] == '\0' && str2[ind])
		return (0);
	return (1);
}

/**
 * get_card_position - Return the position based on card you put in
 * @node: represent the card
 * Return: return the card position
 */
int get_card_position(deck_node_t *node)
{
	int value;

	value = (*node).card->value[0] - '0';
	if (value < 50 || value > 57)
	{
		if (_strcmp((*node).card->value, "Ace") == 1)
			value = 1;
		else if (_strcmp((*node).card->value, "10") == 1)
			value = 10;
		else if (_strcmp((*node).card->value, "Jack") == 1)
			value = 11;
		else if (_strcmp((*node).card->value, "Queen") == 1)
			value = 12;
		else if (_strcmp((*node).card->value, "King") == 1)
			value = 13;
	}
	value += (*node).card->kind * 13;
	return (value);
}

/**
 *swap_card - swap a card for his previous one card
 *@a: first node address
 *@b: second node address
 *Return: Return a pointer to a card which was enter it.
 */
deck_node_t *swap_card(deck_node_t *a, deck_node_t **b)
{
	deck_node_t *back = a->prev, *current = a;

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
 * insertion_sort_deck - function that sorts a doubly-linked deck
 *                       using the Insertion sort algorithm
 * @deck: Dobule-linked deck to sort
 */
void insertion_sort_deck(deck_node_t **deck)
{
	int v_prev, v_current;
	deck_node_t *i;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	i = (*deck)->next;
	while (i)
	{
		if (i->prev)
		{
			v_prev = get_card_position((i->prev));
			v_current = get_card_position(i);
		}
		while ((i->prev) && (v_prev > v_current))
		{
			v_prev = get_card_position((i->prev));
			v_current = get_card_position(i);
			i = swap_card(i, deck);

		}
		i = i->next;
	}
}

/**
 * sort_deck - sort a deck of cards
 *             using insertion sort algorithm
 * @deck: deck
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}
