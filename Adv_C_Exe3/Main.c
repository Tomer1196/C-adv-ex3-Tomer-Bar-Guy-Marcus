#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"
void printQueue(Queue* q);

void main()
{
	int num = 0 ,choice = 0 , count = 0, sum = 0, sel = 0;
	Queue* stamp = (Queue*)malloc(sizeof(Queue));
	printf("Please enter a case number:\n For list of commands enter '1'\n");
	initQueue(stamp);
	while (1) {
		printf("\nPress '1' to insert a number into the queue.\nPress '2' to remove an item from the top of the queue.\nPress '3' to print the current queue items.\nPress '4' to Rotate the queue.\nPress '5' to use the cutAndReplace function on the queue.\nPress '6' to destroy the queue.\n");
		scanf("%d", &choice);

		switch (choice) {	

		case 1:
			printf("Please enter a positive number\n\n");
			scanf("%d", &num);
			printf("\n");
			enqueue(stamp, num);
			break;

		case 2:
			printf("\n");
			dequeue(stamp);
			break;

		case 3:
			printQueue(stamp);
			break;

		case 4:
			printf("\n");
			rotateQueue(stamp);
			break;

		case 5:
			cutAndReplace(stamp);
			break;

		case 6:
			destroyQueue(stamp); //sadly doesn't want to work :(
			break;

		case 0:
			exit(1);

		default:
			printf("That is not a valid selection!\n");
		}
	}
	/*printf("Enter a positive number to the queue \n");
	
	scanf("%d", &num);
	if (num < 0)
	{
		while (num < 0) {
			printf("Input error detected! Please enter a positive number to the queue \n");
			scanf("%d", &num);
		}
	}
	*/
/*
	enqueue(stamp, num * 5);
	enqueue(stamp, num * 11);
	enqueue(stamp, num * 14);
	enqueue(stamp, num * 10);
	enqueue(stamp, num * 17);

	sum = sumOfItems(stamp);
	
	printf("The integer added to the queue is %d\n",sum);
	
	//display(stamp); // ???????? ?????? ?? ?? ???? ???? ??? ????? ????
	printf("There are %d items in the queue\n", count);

	//cutAndReplace(stamp);
	
	sortKidsFirst(stamp);

	//display(stamp);
	
	/*int num1 = dequeue(temp);
	printf("%d\n",num1);
	num1 = dequeue(temp);
	printf("%d\n", num1);
	num1 = dequeue(temp);
	printf("%d\n", num1);
	num1 = dequeue(temp);
	printf("%d\n", num1);
	*/

	char temp[100];
	printf("Enter a string : ");
	gets(temp);//Remem#reb# thi#crap s#tice 
	flipBetweenHashes(temp);

	char temp1[100];
	num = 0;
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	initStack(stack);
	printf("enter a sentence to the stack \n");
	gets(temp1); //moonnoom , abcdcrdcba
	printf("enter a number that you wish to move from the bottom of the stack \n");
	scanf("%d", &num);
	int size = strlen(temp1);
	char* str = (char*)malloc(sizeof(size)+1);
	strcpy(str, temp1);
	int i = 0;
	while (*(str + i) != '\0')
	{
		push(stack, *(str + i));
		i++;
	}
	printf("%d",isPalindrome(stack));
	rotateStack(stack,num);
	
}