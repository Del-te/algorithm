#include<stdio.h>
#define maxsize 100
typedef int datatype;
typedef struct {
    datatype data[maxsize];
    int length;
} seqlist;
typedef struct
{
    datatype key;
    int address;
} node;
int index_seqsearch(seqlist l, node index[], int m, datatype key) {
    int i = 0, j;
    while (i < m && key > index[i].key)
        i++;
    if (i >= m)
        return -1;
    else
    {
        if (i == m - 1)
            j = l.length - 1;
        else
            j = index[i + 1].address - 1;
        while (j >= index[i].address && key != l.data[j])
            j--;
        if (j < index[i].address)
            return -1;
        else
            return j;
    }
}
int main() {
    int i, k, m;
    datatype key;
    seqlist list;
    node index[10];
    printf("输入线性表的长度：");
    scanf("%d", &list.length);
    printf("输入线性表的结点内容：\n");
    for (i = 0; i < list.length; i++)
        scanf("%d", &list.data[i]);
    printf("输入索引表的长度：");
    scanf("%d", &m);
    printf("输入索引表的内容（起始地址(从0开始)，块内最大关键字）：\n");
    for (i = 0; i < m; i++)
        scanf("%d %d", &index[i].address, &index[i].key);
    do {
        printf("请输入要查找的关键字(-1结束)：");
        scanf("%d", &key);
        if (key == -1) break;
        k = index_seqsearch(list, index, m, key);
        if (k == -1)
            printf("关键字查找失败!\n");
        else
            printf("\n%d在第%d个位置！\n", key, k+1);
    } while (k != -1);
    return 0;
}