#include "deck.h"

int _strcmp(const char *a, const char *b);
char get_num(deck_node_t *card);
void sort_for(deck_node_t **deck);
void sort_v(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - function that compares two strings
 * @a: First str
 * @b: Second str
 *
 * Return: 0
 */
int _strcmp(const char *a, const char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}

	if (*a != *b)
		return (*a - *b);
	return (0);
}

/**
 * get_num - Function that gets numerical value
 * @card: Ptr to a deck_node_t card
 *
 * Return: Value
 */
char get_num(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_for - Function that sorts a deck of cards
 * @deck: Ptr to the head
 */
void sort_for(deck_node_t **deck)
{
	deck_node_t *i, *j, *k;

	for (i = (*deck)->next; i != NULL; i = k)
	{
		k = i->next;
		j = i->prev;
		while (j != NULL && j->card->kind > i->card->kind)
		{
			j->next = i->next;
			if (i->next != NULL)
				i->next->prev = j;
			i->prev = j->prev;
			i->next = j;
			if (j->prev != NULL)
				j->prev->next = i;
			else
				*deck = i;
			j->prev = i;
			j = i->prev;
		}
	}
}

/**
 * sort_v - Function that sorts a deck of cards
 * @deck: Ptr to the head
 */
void sort_v(deck_node_t **deck)
{
	deck_node_t *i, *j, *k;

	for (i = (*deck)->next; i != NULL; i = k)
	{
		k = i->next;
		j = i->prev;
		while (j != NULL &&
		       j->card->kind == i->card->kind &&
		       get_num(j) > get_num(i))
		{
			j->next = i->next;
			if (i->next != NULL)
				i->next->prev = j;
			i->prev = j->prev;
			i->next = j;
			if (j->prev != NULL)
				j->prev->next = i;
			else
				*deck = i;
			j->prev = i;
			j = i->prev;
		}
	}
}

/**
 * sort_deck - Function that sorts a deck of cards
 * @deck: Ptr to the head
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_for(deck);
	sort_v(deck);
}
