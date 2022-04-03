
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    void *data;
    struct Node *next;
} node;

typedef struct Deque
{
    int size;
    node *next;
} Deque;

void dequeCreate(Deque **deque);
void dequePrint(Deque **deque);
int isEmpty(Deque **deque);
int pushEnd(Deque **deque, void *data);
int pushStart(Deque **deque, void *data);
int popEnd(Deque **deque, void *operand);
int popStart(Deque **deque, void *operand);
int dequeDestroy(Deque **head);

#endif
