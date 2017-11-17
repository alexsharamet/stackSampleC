#ifndef __STACK__
#define __STACK__

#include <stdlib.h>
#include <stdbool.h>

typedef void (*tf_relese)(void*);

#define STACK_SIZE 128
typedef struct {
	int n,nMax;
	void* *arr;

	tf_relese relese;
} tstack;


void createStack(tstack* const st,tf_relese relese);
void freeStack(tstack st);
bool emptyStack(const tstack st);
int sizeStack(const tstack st);
void* topStack(const tstack st);
void pushStack(tstack* const st,void* el);
void popStack(tstack* const st);

#endif 
