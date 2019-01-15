#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n)
{
    int i = 0, range = 1;
    if(n <= 1) return 0;
    range = floor(sqrt(n) + 0.5);
    for(i = 2; i <= range; i++)
    {
        if (n % i == 0) 
            return 0;
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    int n = 0;
    while(scanf("%d", &n) == 1 && n != 0)
    {
        if (is_prime(n)) 
            printf("is prime!\n");
        else
            printf("is not prime!\n");
    }
    return 0;
}
