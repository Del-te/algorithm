#include <iostream>
#include <stack>

using namespace std;
const int maxn = 1000;
int A[maxn];
int B[maxn];
bool IsPopOrder(const int *push, const int *pop, int length)
{
    bool bPossible = false;
    if (push != NULL && pop != NULL && length > 0)
    {
        std::stack<int> stackData;
        int i = 0;
        int j = 0;
        while (j < length)
        {
            while (stackData.empty() || stackData.top() != pop[j])
            {
                if (i > length - 1)
                    break;
                stackData.push(push[i]);
                ++i;
            }
            if (stackData.top() != pop[j])
                break;
            stackData.pop();
            ++j;
        }
        if (stackData.empty() && j == length)
            bPossible = true;
    }
    return bPossible;
}

int main()
{
    int count = 0;
    char c;
    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            A[count] = c - '0';
            count++;
        }
    }
    count = 0;
    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            B[count] = c - '0';
            count++;
        }
    }
    if (IsPopOrder(A, B, count + 1))
        cout << "True";
    else
        cout << "False";
    return 0;
}