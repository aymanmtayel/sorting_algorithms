#include "sort.h"

/**
 * _swap - function to swap two nodes
 * @node1: node one to go forward
 * @node2: node two to go backword
 * Return: Void
 */
void _swap(listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the list to be sorted
 * Return:Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *fwd;

	if (!list || !*list || !(*list)->next)
		return;
	fwd = (*list)->next;
	while (fwd)
	{
		curr = fwd;
		fwd = fwd->next;
		while (curr && curr->prev)
		{
			if (curr->prev->n > curr->n)
			{
				_swap(curr->prev, curr);
				if (!curr->prev)
					*list = curr;
				print_list((const listint_t *)*list);
			}
			else
			{
				curr = curr->prev;
			}
		}
	}
}
