#ifndef _GSTACK_
#define _GSTACK_

typedef int bool;

typedef struct {
	void *elements;
	size_t element_size, num_elements, max_elements;
} STACK;


void initStack (STACK *s, int element_size);

void freeStack(STACK *s);

bool  isEmpty(const STACK *s);

void push(STACK *s, const void *eptr);

void pop(STACK *s, void *eptr);

void peek(STACK *s, void *eptr);

#endif	//_GSTACK_

