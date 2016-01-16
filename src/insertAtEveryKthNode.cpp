/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K)
{
	if (head == NULL || K<0)
		return NULL;
	struct node * current = head;
	struct node *temp;
	int length = 0, iterator = K;
	while (current != NULL)
	{
		length++;
		current = current->next;
	}
	current = head;
	if (K > length)
		return head;
	while (current != NULL)
	{
		iterator--;
		if (iterator == 0)
		{
			temp = (struct node *)malloc(sizeof(struct node *));
			temp->num = K;
			temp->next = NULL;
			temp->next = current->next;
			current->next = temp;
			current = temp;
			iterator = K;
		}
		current = current->next;
	}
	return head;
}