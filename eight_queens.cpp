#include <cstdio>
#include <cstdlib>
using namespace std;  
int a[9][9];
bool flag;  //判断已给定位置的皇后之间是否有冲突
//第i行第j列为皇后，把该皇后能影响的位置设置为1
void setValue(int m, int n){
    int i, j;
    for(i=1; i<=8; i++){    //行、列占满
        a[m][i]=a[i][n]=1;
    }
    for(i=1;(m-i)>=0 && (n-i)>=0; i++) //左上角
        a[m-i][n-i]=1;
    for(i=1;(m-i)>=0 && (n+i)<=8; i++) //右上角
        a[m-i][n+i]=1;
    for(i=1;(m+i)<=8 && (n-i)>=0; i++) //左下角
        a[m+i][n-i]=1;
    for(i=1;(m+i)<=8 && (n+i)<=8; i++) //右下角
        a[m+i][n+i]=1;
}
int main(){
    char str[10];
    while(scanf("%s", str)!=EOF){
        int i, j, last;
        //初始化
        flag=true; //无冲突
        for(i=1;i<=8;i++)
            for(j=1;j<=8;j++)
                a[i][j]=0;
        for(i=0;i<8;i++){
            if(str[i]=='*'){
                last=i+1;  //行、列都从1开始编号
                continue;
            }
            int tmp=str[i]-'0';
            if(a[i+1][tmp]==0){    //当前皇后位置与之前皇后无冲突
                setValue(i+1, tmp);
            }else{
                flag=false;
                break;
            }
        }
        for(i=1;i<=8;i++)
            if(a[last][i]==0)
                break;
        if(flag && i!=9)
            printf("%d\n", i);
        else 
            printf("No Answer!\n");
    }
    return 0;
    system("pause");
}