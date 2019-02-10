#include <iostream>
#include <cmath>
using namespace std;
int count = 0;
int visit[10] = {0};
int num;
void dfs(int step,int count) {  //step代表7的几次方 
    if(visit[step] > 5) {   //相同金额的份数不能超过5份
        return;
    }
    if(count > 1000000) {
        return;
    } else if(count == 1000000){
        num = 0;
        for(int i = 0; i < 10; i++) {
            num += visit[i];
        }
        cout<< num;
        exit(0);
    }        
    count += pow(7,step);
    visit[step]++;
    dfs(step, count);    //两种路 visit[step]+1
    dfs(step+1, count);   //visit[step+1]+1
    visit[step]--;
    count -= pow(7,step);
} 
int main()
{   
    dfs(0,0);
    return 0;
}