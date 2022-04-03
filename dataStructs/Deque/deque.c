#include "main.h"

void dequeCreate(Deque **deque)
{
    *deque = (Deque *)malloc(sizeof(Deque));
    (*deque)->size = 0;
    (*deque)->next = NULL;

    return;
}

void dequePrint(Deque **deque)
{
    if (*deque != NULL)
    {
        node *current = (*deque)->next;
        while (current != NULL)
        {
            printf("%d \n", current->data);
            current = current->next;
        }
    }
    return;
}

int isEmpty(Deque **deque)
{
    if (*deque == NULL)
        return -1;

    return ((*deque)->size == 0);
}

int dequeDestroy(Deque **deque)
{
    if (*deque == NULL)
        return -1;

    node *current = (*deque)->next;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(deque);
    (*deque)->size = 0;

    return 0;
}

int pushEnd(Deque **deque, void *data)
{
    if (*deque == NULL)
        return -1;

    node *newNode = NULL;
    node *lastDeque = NULL;
    node *current = NULL;

    newNode = (node *)malloc(sizeof(node));

    if (newNode == NULL)
        return -1;

    newNode->data = (void *)data;
    newNode->next = NULL;
    current = (*deque)->next;

    if (isEmpty(deque))
    {
        (*deque)->next = newNode;
    }
    else
    {
        while (current != NULL)
        {
            lastDeque = current;
            current = current->next;
        }

        lastDeque->next = newNode;
    }

    (*deque)->size++;

    return 0;
}

int pushStart(Deque **deque, void *data)
{
    if (*deque == NULL)
        return -1;

    node *newNode = NULL;
    newNode = (node *)malloc(sizeof(node));

    newNode->data = (void *)data;
    newNode->next = (*deque)->next;

    (*deque)->next = newNode;
    (*deque)->size++;

    return 0;
}

int popEnd(Deque **deque, void *operand)
{
    if (*deque == NULL)
        return -1;

    node *secondLast = NULL;
    node *current = NULL;

    current = (*deque)->next;

    if (isEmpty(deque))
        return -1;

    if (current->next != NULL)
    {
        while (current->next != NULL)
        {
            operand = current->next->data;
            secondLast = current;
            current = current->next;
        }
    }
    else
    {
        secondLast = (*deque)->next;
        operand = (*deque)->next->data;
        (*deque)->next = NULL;
    }

    free(secondLast->next);
    secondLast->next = NULL;
    (*deque)->size--;

    return 0;
}

int popStart(Deque **deque, void *operand)
{
    if (*deque == NULL)
        return -1;

    node *temp = NULL;

    if (isEmpty(deque))
        return -1;

    operand = (*deque)->next->data;
    temp = (*deque)->next;
    (*deque)->next = (*deque)->next->next;
    free(temp);
    (*deque)->size--;

    return 0;
}
