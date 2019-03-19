#include <stdio.h>  
#include <cstdlib>
int go(int i, int j, int n) 
{      
	//上下对称
    if (i > n * 2 + 3)         
        i = n * 4 + 6 - i;
    //左右对称
    if (j > n * 2 + 3)         
        j = n * 4 + 6 - j;
   	//前两行时显示的为 '.'  
    if (i <= 2 && j <= 2) return 0; 
    //上下左右对称后剩余四分之一，45度角来一刀八分之一，另八分之一需要进行X坐标与Y坐标交换 
    if(i<j)
    {
    	int t;
    	t=i;
    	i=j;
    	j=t;
	}
	//因为i>2的奇数行最右边一定有三个 $  j>i-3 一定返回1； 
	if (i % 2 == 1 && j > i - 3)return 1;
	//i>2的奇数行连续三个 $ 的左边则是 j 为奇数返回1； 
	if (i % 2 == 1 && j % 2 == 1 )return 1;     
	//i>2的偶数行，一定有连续三个小点，所以三个小点的左边 j<=i-3，j为奇数时画 $ 
	if (j % 2 == 1 && j <= i - 3) return 1; 
    // 注意!不满足条件的默认返回0！！
    return 0; 
}


int main() 
{      
    int n;      
    scanf("%d", &n);           
    int i, j;      
    for (i = 1; i <= n*4+5; i++)     
    {          
        for (j = 1; j <= n*4+5; j++)         
        {              
            if (go(i, j, n))                 
            printf("$");             
            else                  
            printf(".");         
        }          
        printf("\n");     
    }
    system("pause");
    return 0; 
} 