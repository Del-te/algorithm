#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}node;
int len = 0;

node *Create_Node(int i)//新建并初始化节点
{
    node *p = (node *) malloc(sizeof(node));
    if (!p) {
        printf("Error,the memory is not enough!\n");
        exit(-1);
    }
    p->data = i;
    p->next = NULL;
    // printf("The New Node is:%d\n",p->data);
    return p;
}

void Create_List(node *head, int n)//把其余数据添加到循环单链表中
{
    int i = 0;
    node *pNew, *p;
    if(len == 0) {
        pNew = Create_Node(2);
        head->data = 1;
        pNew->data = 2;
        head->next = pNew;
        p = pNew;
        pNew->next = NULL;
        len = 2;
    }
    for (i = 3; i <= n; i++) {
        pNew = Create_Node(i);
        p->next = pNew;
        pNew->next = NULL;
        p = pNew;
        len++;
    }
    p->next = head;
}

void Print_List(node *head)//输出链表内容
{
    node *p = head;
    int i = 1;
    printf("The joseph ring:\n");
    while(i <= len){
        if(p)
            printf("%d\n", p->data);
        p = p->next;
        i++;
    }
    printf("The length of the List:%d\n", len);
}

void joseph(node *head, int count)//约瑟夫回环函数实现
{
    node *p1 = head, *p2 = head;
    int i = 0;
    while (len != 1) {
        for(i = 0;i < count -1 ;i++)
            p1 = p1->next;
        p2 = p1->next;
        p1->next = p2->next;
        printf("%d is out!\n", p2->data);
        free(p2);
        len--;
    }
    printf("The last one is:%d\n", p1->data);
}

int main() {
    int n = 0;
    int count = 0;
    printf("Please input the length of the joseph ring:");
    scanf("%d", &n);
    printf("Please input the numbers oof steps you want to calculate:");
    scanf("%d", &count);
    node *head = Create_Node(1);
    Create_List(head, n);
    Print_List(head);
    joseph(head, count);
    system("pause");
    return 0;
}