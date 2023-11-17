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
 * @list2: list
 * @list1: list
 * @head: head
*/
void swap(listint_t **head, listint_t **list1, listint_t *list2)
{
	(*list1)->next = list2->next;
	if (list2->next != NULL)
		list2->next->prev = *list1;
	list2->prev = (*list1)->prev;
	list2->next = *list1;
	if ((*list1)->prev != NULL)
		(*list1)->prev->next = list2;
	else
		*head = list2;
	(*list1)->prev = list2;
	*list1 = list2->prev;
}


/**
 * insertion_sort_list - insertion sort algorithm
 * @list: list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
