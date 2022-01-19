#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;


node *create(int x)
{
	node *tmp = (node *)malloc(sizeof(node));
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}


void show(node *head)
{
	if(head == NULL) {printf("EMPTY\n");return;}
	while(head)
	{
		printf("%d ", head->data); head = head->next;
	}printf("\n");
}

void insert(node **head, int x)
{
	if(*head == NULL) *head = create(x);
	else
	{
		node *p = *head;
		while(p->next) p = p->next;
		p->next = create(x);
	}
}

void sorted_insert(node **head, int x)
{
	if(*head == NULL) *head = create(x);
	else if((*head)->data>x)
		{
			node *tmp = create(x);
			tmp->next = *head;
			*head = tmp;
		}
	else
	{
		node *p = *head;
		while(p->next!=NULL && p->next->data < x) p = p->next;
		node *tmp = create(x); tmp->next = p->next;
		p->next = tmp;
	}
}


void delete_node(node **head, int x)
{
	if(*head == NULL) printf("ERR : Empty\n");
	else if((*head)->data == x)
	{
		node *tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	else
	{
		node *p = *head;
		while(p->next!=NULL && p->next->data != x) p = p->next;
		if(p->next == NULL) {printf("ERR : NOT FOUND\n"); return;}
		node *tmp = p->next;
		p->next = p->next->next;
		free(tmp);
	}
}

void copy_list(node **a, node **new)
{
	node *p = *a;
	if(p != NULL)
	{
		(*new) = create(p->data); 
		p = p->next;
		node *n = *new;
		while(p != NULL)
		{
			n->next = create(p->data);
			n = n->next;
			p = p->next;
		}
	}

}

void merge(node **a, node **b, node **new)
{
	node *n;
	node *p = *a, *q = *b;
	if(p == NULL)
		copy_list(b,new);
	else if(q == NULL)
		copy_list(a,new);

	else
		{
			while(p != NULL && q != NULL)
			{
				if((*new) != NULL)
				{
					if(p->data < q->data)
					{
						n->next = create(p->data);
						n = n->next;
						p = p->next;
					}
					else
					{
						n->next = create(q->data);
						n = n->next;
						q = q->next;
					}
				}
				else
				{
					if(p->data < q->data)
					{
						*new = create(p->data); p = p->next;
					}
					else
					{
						*new = create(q->data); q = q->next;
					}
					n = *new;
				}
			}
			if(q == NULL)
			{
				while(p != NULL)
				{
					n->next = create(p->data);
					n = n->next;
					p = p->next;
				}
			}
			else if(p == NULL) 
			{
				while(q != NULL)
				{
					n->next = create(q->data);
					n = n->next;
					q = q->next;
				}
			}
		}
}


void merge_same(node **a, node **new)
{
	node *p = *a, *q = *new;
	if(q == NULL)
	{
		return;
	}
	else if(p->next == NULL)
	{
		if(p->data > q->data);
	}
	else
	{
		while(p->next != NULL && q != NULL)
		{
			while(p->next->data <= q->data) p = p->next;
			node *tmp = create(q->data);
			tmp->next = p->next;
			p->next = tmp;
			p = p->next;


		}
	}
			
}