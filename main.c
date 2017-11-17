#include <stdio.h>
#include "stack.h"

void realeseInt(void* ptr){
	free(ptr);
}

int main(int argc,char* argv[]){
	tstack st;
	createStack(&st,realeseInt);
	int i;
	int* put=NULL;
	printf("empty=%s\n",( emptyStack(st)?"true":"false") );
	for(i=0;i<10;i++){
		put=malloc(sizeof(int));
		*put=i;
		pushStack(&st,put);
	}
	put=NULL;
	printf("size=%d\n",sizeStack(st));

	for(i=0;i<10;i++){
		put=topStack(st);
		popStack(&st);
		printf("el=%d\n",*put);
	}

	freeStack(st);
	printf("empty=%s\n",( emptyStack(st)?"true":"false") );

	return 0;
}
