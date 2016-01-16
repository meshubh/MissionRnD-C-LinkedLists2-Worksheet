/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head)
{
	struct node *slow_ptr = head;
	struct node *fast_ptr = head;
	struct node* current = head;
	int count = 0;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	if (head != NULL)
	{
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			if (fast_ptr == head)
				slow_ptr = head;
			else
				slow_ptr = slow_ptr->next;
			fast_ptr = fast_ptr->next->next;
		}
		if (count % 2 == 1)
		{
			if (count == 1)
				return head->num;
			else
				return slow_ptr->next->num;
		}
		else
		{
			return (slow_ptr->num + (slow_ptr->next->num)) / 2;
		}
	}
	else
		return -1;
}