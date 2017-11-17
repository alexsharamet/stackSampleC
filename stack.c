#include "stack.h"

void createStack(tstack* const st,tf_relese relese){
	st->nMax=STACK_SIZE;
	st->n=0;
	st->arr=malloc(sizeof(void*)*st->nMax);

	st->relese=relese;
	return;
}

void freeStack(tstack st){
	int i;
	for(i=0;i<st.n;i++){
		st.relese(st.arr[i]);
	}
	free(st.arr);
}

bool emptyStack(const tstack st){
	if(st.n>0)return true;
	return false;
}

int sizeStack(const tstack st){
	return st.n;
}

void* topStack(const tstack st){
	if(st.arr==NULL)return NULL;
	if(st.n==0)return NULL;
	return st.arr[st.n-1];
}

void pushStack(tstack* const st,void* el){
	if(st->n==st->nMax){
		st->nMax*=2;
		st->arr=realloc(st->arr,sizeof(void*)*st->nMax);
	}
	st->arr[st->n]=el;
	st->n++;
}

void popStack(tstack* const st){
	if(st->n==0)return;
	st->n--;
	st->relese(st->arr[st->n]);
}
