#include "sort.h"

/**
 * list_size - size of list
 * @list: list
 * Return: size of list
 */
int list_size(listint_t **list)
{
	int len = 0;
	listint_t *current = *list;

	while (current != NULL)
	{
		current = current->next;
		len++;
	}
	return (len);
}

/**
 * swap - swaps
 * @node2: list
 * @node1: list
 * @head: head
*/
void swap(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}


/**
 * insertion_sort_list - insertion sort algorithm
 * @list: list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *cu, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (cu = (*list)->next; cu != NULL; cu = temp)
	{
		temp = cu->next;
		insert = cu->prev;
		while (insert != NULL && cu->n < insert->n)
		{
			swap_nodes(list, &insert, cu);
			print_list((const listint_t *)*list);
		}
	}
}
