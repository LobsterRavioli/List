#include<stdio.h>
#include<stdlib.h>
#include"list.h"
int main()
{
	list new=newList();
	int n=5;
	new=inputList(n);
	outputList(new);
	new=reverseList(new);
	printf("lista reversata:\n");
	outputList(new);

}
