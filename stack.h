#ifndef _STACK_H_
#define _STACK_H_

#define EmptyTOS    -1  //空栈
#define MinSize    5   //栈的最小值

typedef int elementType;    //数据类型

typedef struct stackRecord
{
    int capacity;//容量
    int Top;//栈顶
    elementType *array; 
}STACK;

int isEmpty(STACK *s);  //判空
int isFull(STACK *s);   //判满
STACK *createStack(int maxElements);    //栈的创建
void clean(STACK *s);        //栈的释放
void initStack(STACK *s);       //创建空栈
void push(elementType element, STACK *s);//入栈
elementType top(STACK *s);      //返回栈顶元素
void pop(STACK *s);         //出栈
elementType popAndTop(STACK *s);    //出栈并返回栈顶元素
void printStack(STACK *S);     // 遍历输出栈全部内容


#endif
