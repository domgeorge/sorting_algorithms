#include "sort.h"
/**
 *swap_node - function that helps swap 2 nodes in a doubly-linked list
 *@a: first node
 *@b: second node
 */
void swap_node(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
/**
 *_rev - function that helps sort from the tail back
 *
 *@head: head
 *@tail: tail
 *@list: initial head of the list
 *Return: list head
 */
listint_t *_rev(listint_t *head, listint_t *tail, listint_t *list)
{
	while (tail && tail->prev)
	{
		if (tail->n < tail->prev->n)
		{
			swap_node(tail->prev, tail);
			if (tail->prev == NULL)
				list = tail;
			print_list(list);
		}
		else
			tail = tail->prev;
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}

/**
 *cocktail_sort_list - sorts linked list using cocktail shaker sort
 *@list: doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end, *start, *len;
	int i = 0, j = 0, swap = 1;

	if (!list || !*list)
		return;

	len = *list;
	for (i = 0; len; i++)
	{
		len = len->next;
	}
	if (i < 2)
		return;
	start = *list;
	while (j < i)
	{
		swap = 0;
		while (start && start->next)
		{
			if (start->n > start->next->n)
			{
				swap_node(start, start->next);
				swap++;
				if (start->prev->prev == NULL)
					*list = start->prev;
				print_list(*list);
			}
			else
				start = start->next;
			if (start->next == NULL)
				end = start;
		}
		start = _rev(start, end, *list);
		*list = start;
		j++;
	}
}
