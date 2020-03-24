#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * _strlen - determines the string length
 * @str: given string
 *
 * Return: an integer length
 */
int _strlen(const char *str)
{
	int length = 0;

	while (str)
		length++;
	return (length);
}

/**
 * add_node_end - add a node at the end of list
 * @head: the head of the list
 * @str: a given string
 *
 * Return: a pointer to the new element
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *tmp;

	tmp = *head;
	/* nod memeorty allocation */
	new_node = (list_t *)malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);
	/* Nod creation and initialization */
	new_node->str = strdup(str);
	/* check memory allocation for strdup */
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->len = _strlen(new_node->str);
	new_node->next = NULL;
	/* checking if there is more than 2 elements(list exist) */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	/* searcing for n-1 last element of the list where to point */
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return (new_node);
}
