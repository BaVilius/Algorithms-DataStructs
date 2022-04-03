#include "main.h"

int main()
{
    // To use one needs to initialize a pointer to deque structure as NULL
    // Pass in address of the deque in functions and cast different pointers as variables
    int operand;
    Deque *deque = NULL;
    dequeCreate(&deque);
    pushStart(&deque, (int *)1);
    pushStart(&deque, (int *)2);
    pushStart(&deque, (int *)3);

    dequePrint(&deque);

    popEnd(&deque, (int *)operand);

    dequePrint(&deque);

    popStart(&deque, (int *)operand);

    dequePrint(&deque);

    return 0;
}