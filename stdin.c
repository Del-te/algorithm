#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 100
int compare (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main() {
    int A[maxn];
    int i = 0, temp = 0, data = 0, capacity = 0, count = 0;
    memset(A, 0, sizeof(A));
    while (1){
        if (scanf("%d", &data) == 1) {
            if ((temp = getchar()) != '\n') {
                A[i] = data;
                i++;
                capacity++;
            } else {
                A[i] = data;
                i++;
                capacity++;
                break;
            }
        }
    }
    qsort(A, capacity, sizeof(int), compare);
    for (i = 0; i < capacity; i++) {
        if(A[i] % 2 != 0) {
            printf("%d", A[i]);
            count++;
            if (count != capacity)
                printf(",");

        }
    }
    for (i = 0; i < capacity; i++) {
        if(A[i] % 2 == 0) {
            printf("%d", A[i]);
            count++;
            if (count != capacity)
                printf(",");
        }
    }
    return 0;
}