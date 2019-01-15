#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define INF 32767
typedef struct{
    int vertices[100];
    int edge[100][100];
    int NoV;
    int NoE;
}Adj_Matrix;

void create(Adj_Matrix *g)
{
    int a,b,vi,vj,weight,i,j;
    printf("Please input the number of vertices and edges of the graph (_,_):");
    scanf("%d,%d",&a,&b);
    g->NoV=a;
    g->NoE=b;
    for(i=0;i<a;i++)
        for(j=0;j<a;j++)
        {
            if(i==j)
                g->edge[i][j]=0;
            else
                g->edge[i][j]=INF;
        }
    for(i=0;i<g->NoV;i++)
    {
        printf("Input the data for the vertex of %d(integer):",i+1);
        scanf("%d",&g->vertices[i]);
    }
    printf("\n");
    for(i=0;i<g->NoE;i++)
    {
        printf("Please input the starting point, terminating point, weight (_,_,_):");
        scanf("%d,%d,%d",&vi,&vj,&weight);
        //若为不带权值的图，则weight输入1
        g->edge[vi-1][vj-1]=weight;
        g->edge[vj-1][vi-1]=weight;
        // 无向图具有对称性
    }
}
void display(Adj_Matrix g)
{
    int i,j;
    printf("\nvertex data:\n");
    for(i=0;i<g.NoV;i++)
        printf("%8d",g.vertices[i]);
    printf("\nthe adjacency matrix:\n");
    printf("\t");
    for(i=0;i<g.NoV;i++)
        printf("%8d",g.vertices[i]);
    for(i=0;i<g.NoV;i++)
    {
        printf("\n%8d",i+1);
        for(j=0;j<g.NoV;j++)
        {
            if(g.edge[i][j]==INF)
                printf("%8s", "∞");
            else
                printf("%8d",g.edge[i][j]);
        }
        printf("\n");
    }
}
void traverse(int index, Adj_Matrix g, int *visited, int numv)
{
    int next;
    visited[index] = 1;
    printf("vertice: %d\n", index);
    for(int iter = 0; iter < numv; iter++){
        if(g.edge[index][iter] == 1 && (!visited[iter])){
            traverse(iter, g, visited, numv);
        }
    }
}
int dfs(Adj_Matrix g, int numv)
{
    int visited[(const int) numv];
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < numv; i++){
        traverse(i, g, visited, numv);
    }
    return 0;
}
int main()
{
    Adj_Matrix g;
    create(&g);
    display(g);
    dfs(g,3);
    system("pause");
    return 0;
}