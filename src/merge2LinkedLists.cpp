/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) 
{
	if (head1 == NULL && head2 == NULL)
		return NULL;
	else if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else
	{
		struct node * head, *temp;
		if (head1->num < head2->num)
		{
			head = head1;
		}
		else
		{
			head = head2;
			head2 = head1;
			head1 = head;
		}
		while (head1 != NULL && head2 != NULL)
		{
			if (head1->next != NULL)
			{
				if (head1->next->num <= head2->num)
				{
					head1 = head1->next;
				}
				else
				{
					temp = head1->next;
					head1->next = head2;
					head2 = temp;
				}
			}
			else
			{
				temp = head1->next;
				head1->next = head2;
				head2 = temp;
			}
		}
		if (head2 != NULL)
			head1->next = head2;
		return head;
	}
}
