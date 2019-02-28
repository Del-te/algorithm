// 回溯算法：8皇后问题
#include <cstdio>
#include <cstdlib>
using namespace std;
const int DIM = 8;

int is_a_solution(int a[DIM][DIM], int row);
//void construct_candidates(int a[],int k,data input, int c[],int *ncandidates);
void process_solution(int a[DIM][DIM]);
//void make_move(int a[],int k, data input);
//void unmake_move(int a[],int k,data inupt);

// static int finished = 0;
static int count = 0;

int is_a_solution(int chess[DIM][DIM], int row)
{
    return (row == DIM);
}

void process_solution(int chess[DIM][DIM])
{
    int i, j;
    count++;
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
            printf("%d ", chess[i][j]);
        printf("\n");
    }
    printf("\n");
}

int is_collision(int chess[DIM][DIM], int x, int y)
{
    int i, j;
    // 对角线
    for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
        if (chess[i][j] == 1)
            return 1;
    // 列
    for (i = x - 1, j = y + 1; i >= 0 && j < DIM; i--, j++)
        if (chess[i][j] == 1)
            return 1;
    return 0;
}

void backtrack(int chess[DIM][DIM], int row, int *candidates)
{
    if (is_a_solution(chess, row))
        process_solution(chess);
    else
    {
        //construct_candidates(a,k,input,c,&ncandidates);
        for (int i = 0; i < DIM; i++)
        {
            // 剪枝
            if (candidates[i] || is_collision(chess, row, i))
                continue;
            //make_move(a,k,input);进行操作
            chess[row][i] = 1;
            candidates[i] = 1;

            backtrack(chess, row + 1, candidates);

            //unmake_move(a,k,input);撤销操作
            chess[row][i] = 0;
            candidates[i] = 0;
        }
    }
}

void generate_8queen(int chess[8][8])
{
    int candidates[DIM] = {0, 0, 0, 0, 0, 0, 0, 0};
    backtrack(chess, 0, candidates);
    printf("total:%d\n", count);
    return;
}

int main()
{
    int chess[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}};
    generate_8queen(chess);
    system("pause");
    return 0;
}