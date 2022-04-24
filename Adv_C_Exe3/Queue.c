#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Queue.h"

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q) {
	intNode* temp = (intNode*)malloc(sizeof(intNode));
	temp->data = 0;
	q->head = q->tail = temp;
}

void destroyQueue(Queue* q)
{
	intNode* deleteptr = (intNode*)malloc(sizeof(intNode));

    if(isEmptyQueue(q))
    {
        while(q->head!=NULL)
        {
            free(q->head->data);
			q->head = q->head->next;
			deleteptr = q->head;
			free(deleteptr);
        }
        free(q->head);
    }
    return NULL;
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* temp = (intNode*)malloc(sizeof(intNode));
	temp->data = data;
	q->tail->next = temp;
	q->tail = q->tail->next;
}

unsigned int dequeue(Queue* q)
{
	if (!isEmptyQueue(q));
	else
	{
		intNode* temp = (intNode*)malloc(sizeof(intNode));
		unsigned int num = 0;
		temp = q->head->next;
		num = temp->data;
		q->head->next = temp->next;
		return num;
	}
}
/*unsigned int dequeue(Queue* q) {
	int num = q->head->data;
	intNode* temp = q->head;
	if (q->head == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if (q->head == q->tail) {
		q->head = q->tail = NULL;
	}
	else {
		q->head = q->head->next;
	}
	return num;
	free(temp);
}*/

int isEmptyQueue(const Queue* q)
{
	if (q->tail->next == q->head->next) {
		return 0;
	}
	return 1;
}

/*void display(Queue* q)  // ???????? ?????? ?? ?? ???? ???? - ?? ????? ????
{
	intNode* temp = (intNode*)malloc(sizeof(intNode));
	int num = 0;
	temp = q->head->next;
	num = temp->data;
	printf("%d   ", num);
	q->head = q->head->next;
}*/

int display(Queue* q)
{
	int helper = 0, count = 0;
	while (isEmptyQueue(q))
	{
		helper = dequeue(q);
		printf("%d   ", helper);
		count++;
	}
	printf("\n");
	return;
}
void printQueue(Queue* q) {
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	initQueue(temp);
	int helper = 0;
	while (isEmptyQueue(q))
	{
		helper = dequeue(q);
		printf("%d ", helper);
		enqueue(temp, helper);
	}
	initQueue(q);
	while (isEmptyQueue(temp)) {
		helper = dequeue(temp);
		enqueue(q, helper);
	}
	printf("\n");
}
/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	if (isEmptyQueue(q));
	intNode* temp = (intNode*)malloc(sizeof(intNode));
	intNode* temp1 = (intNode*)malloc(sizeof(intNode));
	temp->data = q->tail->data;
	temp1 = q->head->next;
	while (temp1->next != q->tail)
	{
		temp1 = temp1->next;
	}
	q->tail = temp1;
	free(q->tail->next);
	temp->next = q->head->next;
	q->head->next = temp;
}

int sumOfItems(Queue* q) {
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	initQueue(temp);
	int counter = 0, helper = 0, sum = 0;
	while (isEmptyQueue(q)) {
		helper = dequeue(q);
		counter++;
		sum += helper;
		enqueue(temp, helper);
	}
	initQueue(q);
	while (isEmptyQueue(temp))
		enqueue(q, dequeue(temp));
	return sum/counter;
}

int numOfItems(Queue* q) {
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	initQueue(temp);
	int counter = 0, helper = 0, sum = 0;
	while (isEmptyQueue(q)) {
		helper = dequeue(q);
		counter++;
		enqueue(temp, helper);
	}
	initQueue(q);
	while (isEmptyQueue(temp))
		enqueue(q, dequeue(temp));
	return counter;
}

void cutAndReplace(Queue* q)
{
	int count1 = 0, count2=0;
	Queue* temp1 = (Queue*)malloc(sizeof(Queue));
	Queue* temp2 = (Queue*)malloc(sizeof(Queue));
	initQueue(temp1);
	initQueue(temp2);
	if (numOfItems(q) % 2 != 0) {
		int adder = sumOfItems(q);
		enqueue(q, adder);
	}
	while (isEmptyQueue(q) < (numOfItems(q) / 2)) {
		enqueue(temp1, dequeue(q));
		count1++;
	}
	while (isEmptyQueue(q)) {
		enqueue(temp2, dequeue(q));
	}
	while (count2 <= count1) {
		count1--;
		rotateQueue(temp2);
	}
	initQueue(q);
	while(isEmptyQueue(temp2))
		enqueue(q, dequeue(temp2));
	while (isEmptyQueue(temp1))
		enqueue(q, dequeue(temp1));
}

void sortKidsFirst(Queue* q)
{
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	initQueue(temp);
	intNode* temp1 = (intNode*)malloc(sizeof(intNode));

	int helper = 0, tester = numOfItems(q);
	while (isEmptyQueue(q)) {
		temp1 = q->head->next;
		if (q->head->data > temp1->data)
			rotateQueue(q);
		else
			enqueue(temp, dequeue(q));
	}
	initQueue(q);
	while (isEmptyQueue(temp))
		enqueue(q, dequeue(temp));
	display(q);
}