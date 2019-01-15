#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int isEmpty(STACK *s)
{
    return (s->Top == EmptyTOS);
}

int isFull(STACK *s)
{
    return (s->Top == s->capacity -1);
}

STACK *createStack(int maxElements)
{
    STACK *s;

    if(maxElements < MinSize) {
        printf("Stack size must be lager than 5!\n");
        system("pause");
        exit(-1);

    }
    s = (STACK *)malloc(sizeof(struct stackRecord));
    s->array = (elementType *)malloc(sizeof(elementType) * maxElements);
    s->capacity = maxElements;
    initStack(s);

    return s;

}
void clean(STACK *s)
{
    if(s != NULL) {
        free(s->array);
        free(s);
    }
}

void initStack(STACK *s)
{
    if(s != NULL) {
        s->Top = EmptyTOS;
    }
}

void push(elementType element, STACK *s)
{
    if(!isFull(s)) {
        printf("push:%d\n", element);
        s->Top++;
        s->array[s->Top] = element;
    } else {
        printf("full stack!\n");
    }
}

elementType top(STACK *s)
{
    if(!isEmpty(s)) {
        return s->array[s->Top];
    } else {
        printf("empty stack!\n");
        return 0;
    }
}

void pop(STACK *s)
{
    if(!isEmpty(s)){
        printf("pop:%d\n", s->array[s->Top]);
        s->Top--;
    }
    else
        printf("empty stack!\n");
}

elementType popAndTop(STACK *s)
{
    if(!isEmpty(s)) {
        return s->array[s->Top--];
    } else {
        printf("empty stack!\n");
        return 0;
    }
}

void printStack(STACK *s)
{
    int i = s->Top;
    if(!isEmpty(s)) {
        printf("\nthe stack:\n\n");
        while(i >= 0){
            printf("|    %d    |\n", s->array[i]);
            i--;
        }
        printf(" --------- \n");
    }else {
        printf("empty stack!\n");
    }
}

// int main(int argc, char const *argv[])
// {
//     STACK *s;
//     int i = 0;
//     int n = 0;
//     printf("please input the capacity:");
//     scanf("%d", &n);
//     s = createStack(n);
//     for(i = 1;i <= n;i++)
//         push(i, s);
//     printStack(s);
//     pop(s);
//     printStack(s);
//     clean(s);
//     system("pause");
//     return 0;
// }
