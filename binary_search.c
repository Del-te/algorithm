#include <stdio.h>
#include <stdlib.h>

int binary_search(int key, int *a, int n)
{
    int i,low,high,mid,count=0,count1=0;
    low = 0;
    high = n-1;
    while(low<high) //查找范围不为0时，进行循环
    {
        count++;//记录查找次数
        mid = (low + high)/2;//中间位置
        if(key<a[mid])//key值小于中间值时
        {
            high = mid - 1;//确定左子表范围
        }
        else if(key>a[mid])//key值大于中间值时
        {
            low = mid + 1;//确定右字表的范围
        }
        else if(key == a[mid])//key值等于中间值时
        {
            printf("查找成功!\n第%d次查找成功！\na[%d]=%d\n", count, mid, a[mid]);
            count1++;
            break;
        }
    }
    if (0==count1)
    {
        printf("查找失败!\n");
    }
    return 0;
}

int main()
{
    int i,j,len,key=0;
    int *a;
    printf("请输入需要查找的序列元素的个数：\n");
    scanf("%d", &len );
    a = (int *)malloc(sizeof(int) * len);
    printf("请输入需要查找的序列：\n");
    for(i=0;i<len;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("请输入需要查找的数值：\n");
    scanf("%d", &key);
    binary_search(key, a, 10);
    free(a);
    return 0;
}