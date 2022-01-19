#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void initStack (STACK *s, int element_size)
{
	s->element_size = element_size;
	s->num_elements = 0;
	s->max_elements = 10;
	s->elements = malloc(s->max_elements * element_size);
}

void push(STACK *s, const void *eptr)
{
	if(s->num_elements == s->max_elements - 1)
		{			
			s->max_elements *= 2;
			s->elements = realloc(s->elements, s->max_elements * s->element_size);
		}
	void* top = s->elements + s->num_elements * s->element_size;
	memmove(top, eptr, s->element_size);
	s->num_elements++;
}

void pop(STACK *s, void *eptr)
{
	if(s->num_elements == 0) {printf("ERROR : Underflow\n");return;}
	s->num_elements--;
	void* top = s->elements + s->num_elements * s->element_size;
	memmove(eptr, top, s->element_size);
}

void peek(STACK *s, void *eptr)
{
	if(s->num_elements == 0) {printf("ERROR : Underflow\n");return;}
	void* top = s->elements + (s->num_elements) * s->element_size;
	memmove(eptr, top, s->element_size);
}

