#include <cstdio>
#include <cstdlib>
int main()  
{  
    char buffer[20]="10549stend#12";  
    char *stop;  
    int ans=strtol(buffer, &stop, 8); 
    // 将八进制数1054转成十进制，后面均为非法字符(大于等于第三个参数的数也非法)
    printf("%d\n",ans);  
    printf("%s\n", stop);  
    system("pause"); 
    return 0;
}