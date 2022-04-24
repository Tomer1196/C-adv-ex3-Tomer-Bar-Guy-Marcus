#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack.h"

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	charNode* start = (charNode*)malloc(sizeof(charNode));
	start->data = -1;
	s->head = start;
	return s;
}
//void destroyStack(Stack* s) //need to check if the realise is correct - GUY !
//{
//	while (s != -1)
//	{
//		free(s->head->data);
//		s->head->data == s->head->next->data;
//	}
//}

void push(Stack* s, char data)
{
	charNode* temp = (charNode*)malloc(sizeof(charNode));
	temp->next = s->head;
	temp->data = data;
	s->head = temp;
	return;
}

char pop(Stack* s)
{
	char Tav = '0';
	if (isEmptyStack(s))
	{
		printf("The stack is empty");
		return 0;
	}
	Tav = s->head->data;
	s->head = s->head->next; // need to check if correct - GUY !
	return Tav;
}


int isEmptyStack(const Stack* s)
{
	return (s->head < 0);
}

int Counter(Stack* s)
{
	int i = 0;
	while (s->head->data != -1)
	{
		s->head = s->head->next;
		i++;
	}
	return i;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	initStack(stack);
	int i = 0;
	char* read;
	read = sentence;
	while (*(read + i) != '\0')
	{
		if (*(read + i) == '#')
		{
			i += 1;
			while (*(read + i) != '#')
			{
				push(stack, *(read + i));
				i++;
			}
			while (stack->head->data != -1)
			{
				printf("%c", pop(stack));
			}
			i++;
		}
		printf("%c", *(read + i));
		i++;
	}
}

int isPalindrome(Stack* s)
{
	Stack* temp1 = (Stack*)malloc(sizeof(Stack));
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	temp->head = s->head;
	initStack(temp1);
	while (temp->head->data != -1)
	{
		char tav = pop(temp);
		push(temp1, tav);
	}
	while (s->head->data != -1)
	{
		if ((s->head->data) != (temp1->head->data))
		{
			return 0;
		}
		temp1->head = temp1->head->next;
		s->head = s->head->next;
	}
	return 1;
}

void rotateStack(Stack* s, int n)
{
	if (n < 0)
		return;
	Stack* temp1 = (Stack*)malloc(sizeof(Stack));
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	initStack(temp1);
	temp->head = s->head;
	int count = Counter(temp);
	if (n > count)
	{
		return;
	}
	for (int i = 0; i < count - n; i++)
	{
		char tav = pop(s);
		push(temp, tav);
	}
	for (int i = 0; i < n; i++)
	{
		char tav = pop(s);
		push(temp1, tav);
	}
	while (temp->head->data != -1)
	{
		char tav = pop(temp);
		push(s, tav);
	}
	while (temp1->head->data != -1)
	{
		char tav = pop(temp1);
		push(s, tav);
	}
	while (s->head->data != -1)
	{
		printf("%c", pop(s));
		s->head = s->head->next;
	}
}
