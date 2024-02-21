#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Function that runs insertion sort algorithm in ascending order
 * @list: Head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *asc, *main;

	if (!list || !*list || !(*list)->next)
		return;

	main = (*list)->next;

	while (main)
	{
		asc = main->prev;

		while (asc && asc->n > main->n)
		{
			if (asc->prev)
				asc->prev->next = main;
			if (main->next)
				main->next->prev = asc;

			asc->next = main->next;
			main->prev = asc->prev;

			main->next = asc;
			asc->prev = main;

			if (!main->prev)
				*list = main;

			print_list(*list);

			asc = main->prev;
		}
		main = main->next;
	}
}
