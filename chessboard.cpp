//棋盘覆盖问题，分治法算法
#include <iostream>

using namespace std;

int tile = 1;               //L型骨牌的编号
const int Maxnum = 1 << 10; //棋盘的尺寸大小最大为2的10次方
int Board[Maxnum][Maxnum];  //定义一个二维数组表示这个棋盘
//tr , tc分别代表左上角行号和列号,dr和dc分别代表特殊方块的行号和列号,size是棋盘的尺寸
void ChessBoard(int tr, int tc, int dr, int dc, int size) 
{
    if (size == 1)
        return;
    int t = tile++; //tile是全局变量，代表L型骨牌的编号
    int s = size / 2;

    if (dr < tr + s && dc < tc + s) //左上
        ChessBoard(tr, tc, dr, dc, s);
    else
    {
        Board[tr + s - 1][tc + s - 1] = t;             //用t号L型骨牌填充右下角
        ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s); //递归
    }

    if (dr < tr + s && dc >= tc + s) //右上
        ChessBoard(tr, tc + s, dr, dc, s);
    else
    {
        Board[tr + s - 1][tc + s] = t;                 //用t号L型骨牌填充左下角
        ChessBoard(tr, tc + s, tr + s - 1, tc + s, s); //递归
    }

    if (dr >= tr + s && dc < tc + s) //左下
        ChessBoard(tr + s, tc, dr, dc, s);
    else
    {
        Board[tr + s][tc + s - 1] = t;                 //用t号L型骨牌填充右上角
        ChessBoard(tr + s, tc, tr + s, tc + s - 1, s); //递归
    }

    if (dr >= tr + s && dc >= tc + s) //右下角
        ChessBoard(tr + s, tc + s, dr, dc, s);
    else
    {
        Board[tr + s][tc + s] = t;                     //用t号L型骨牌填充左上角
        ChessBoard(tr + s, tc + s, tr + s, tc + s, s); //递归
    }
}
int main(void)
{
    int x, y, size; //x , y分别代表特殊方块的位置,size代表棋盘的大小
    cout << "请输入特殊方块的位置(x,y)和棋盘的尺寸大小size:  ";
    cin >> x >> y >> size;
    if (size == 0)
    {
        cout << "棋盘尺寸输入不合法！" << endl;
        system("pause");
        return 1;
    }
    else if (x >= size || y >= size)
    {
        cout << "特殊方块的位置输入不合法!" << endl;
        system("pause");
        return 1;
    }
    //特殊方块赋值为0
    Board[x][y] = 0;
    //分治法填满棋盘
    ChessBoard(0, 0, x, y, size);
    //输出棋盘
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << Board[i][j] << "\t";
        }
        cout << endl
             << endl
             << endl;
    }
    system("pause");
    return 0;
}