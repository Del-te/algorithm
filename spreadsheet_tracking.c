#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct command
{
    char cmd_[3]; // 操作指令
    int A;        // 需要操作的行列的个数
    int todo[20]; // 需要操作的行列
} cmd[10000];

int r = 0, c = 0, n = 0;

int simulation(int *q_r, int *q_c)
{
    int i = 0, j = 0;
    for (i = 0; i < n; i++) // 执行n次操作，操作后结果为r_ans,c_ans
    {
        if (cmd[i].cmd_[0] == 'E') // 交换操作
        {
            if (cmd[i].todo[0] == *q_r && cmd[i].todo[1] == *q_c)
            {
                *q_r = cmd[i].todo[2];
                *q_c = cmd[i].todo[3];
            }
            else if (cmd[i].todo[2] == *q_r && cmd[i].todo[3] == *q_c)
            {
                *q_r = cmd[i].todo[0];
                *q_c = cmd[i].todo[1];
            }
        }
        else
        {
            int dr = 0, dc = 0; // 需要刷新
            for (j = 0; j < cmd[i].A; j++)
            {
                int x = cmd[i].todo[j];
                if (cmd[i].cmd_[0] == 'D')
                {
                    if (cmd[i].cmd_[1] == 'R' && *q_r == x)
                        return 0;
                    if (cmd[i].cmd_[1] == 'C' && *q_c == x)
                        return 0;
                    if (cmd[i].cmd_[1] == 'R' && *q_r > x) // 删除行操作
                        dr--;
                    if (cmd[i].cmd_[1] == 'C' && *q_c > x) // 删除列操作
                        dc--;
                }
                else
                {
                    if (cmd[i].cmd_[1] == 'R' && *q_r >= x) // 插入行操作
                        dr++;
                    if (cmd[i].cmd_[1] == 'C' && *q_c >= x) // 插入列操作
                        dc++;
                }
            }
            *q_r += dr;
            *q_c += dc;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int i = 0, j = 0, count = 0;
    int q_sum = 0, q_r = 0, q_c = 0;
    while (scanf("%d%d%d", &r, &c, &n) == 3 && r)
    {
        for (i = 0; i < n; i++) // 读取操作命令
        {
            scanf("%s", cmd[i].cmd_);  // 操作指令
            if (cmd[i].cmd_[0] == 'E') // 如果是交换操作
            {
                for (j = 0; j < 4; j++) // 需要交换的两个坐标
                    scanf("%d", &cmd[i].todo[j]);
            }
            else // 不是交换操作的话
            {
                scanf("%d", &cmd[i].A);        // 需要操作的行列的个数
                for (j = 0; j < cmd[i].A; j++) // 需要操作的行列
                    scanf("%d", &cmd[i].todo[j]);
            }
        }
        if (count > 0)
            printf("\n");
        printf("Spreadsheet #%d\n", ++count);
        scanf("%d", &q_sum);
        while (q_sum--) // 进行q次查询
        {
            scanf("%d%d", &q_r, &q_c);
            printf("Cell data in (%d,%d) ", q_r, q_c);
            if (!simulation(&q_r, &q_c)) // 模拟操作并得到结果
                printf("GONE\n");
            else
                printf("moved to (%d,%d)\n", q_r, q_c);
        }
    }
    return 0;
}
// 7 9
// 5
// DR 2 1 5
// DC 4 3 6 7 9
// IC 1 3
// IR 2 2 4
// EX 1 2 6 5
// 4
// 4 8
// 5 5
// 7 8
// 6 5
// 0 0
// Spreadsheet #1
// Cell data in (4,8) moved to (4,6)
// Cell data in (5,5) GONE
// Cell data in (7,8) moved to (7,6)
// Cell data in (6,5) moved to (1,2)
