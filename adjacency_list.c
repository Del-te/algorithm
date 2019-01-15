#include <stdio.h>
#include <stdlib.h>
typedef struct node{   //边表
    int adj_vex;
    struct node* next;
}edge_node;
typedef struct{     //顶点表
    int vertex;
    edge_node* edge_next;
}vertex_node;
typedef vertex_node AdjList[100];
typedef struct{
    AdjList adj_list;
    int n,e;
}adj_matrix;
void create(adj_matrix* g)
{
    int i,j,k,w,v;
    edge_node *s;
    printf("Please input the number of vertices and edges of the graph (_,_):");
    scanf("%d,%d",&g->n,&g->e);
    printf("create vertices list:\n");
    for (i=0;i<g->n;i++)
    {
        getchar();
        printf("Input the data for the vertex of %d(integer):",i+1);
        g->adj_list[i].vertex=getchar();
        g->adj_list[i].edge_next=NULL;
    }
    //前插法
    printf("create edge list:\n");
    for (k=0;k<g->e;k++)
    {
        printf("Please input the starting point, terminating point(_,_):");
        scanf("%d,%d",&i,&j);
        i-=1;j-=1;//①
        //对于直接相连的进行编入(即对输入“0 1”时，在0对应的边表中编入1)
        s=(edge_node*)malloc(sizeof(edge_node));
        s->adj_vex=j;//边表赋值
        s->next=g->adj_list[i].edge_next;
        g->adj_list[i].edge_next=s;
        s=(edge_node*)malloc(sizeof(edge_node));
        s->adj_vex=i;
        s->next=g->adj_list[j].edge_next;
        g->adj_list[j].edge_next=s;
    }
}
void display(adj_matrix *g)
{
    printf("adjacency list:\n\n");
    int i;
    for (i=0;i<g->n;i++)
    {
        printf("%d->",i+1);
        while(1)
        {
            if(g->adj_list[i].edge_next==NULL)
            {
                printf("^");
                break;
            }
            printf("%d->",g->adj_list[i].edge_next->adj_vex+1);
            g->adj_list[i].edge_next=g->adj_list[i].edge_next->next;

        }
        printf("\n");
    }
}

void bfs(adj_matrix g)
{
    int head = 0;
    int rear = 0;
    int queue[100];     // 辅组队列
    int visited[100];   // 顶点访问标记
    int i, j, k;
    edge_node *node;
    for (i = 0; i < g.n; i++)
        visited[i] = 0;
    printf("bfs: ");
    for (i = 0; i < g.n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            printf("%d ", g.adj_list[i].vertex);
            queue[rear++] = i;  // 入队列
        }
        while (head != rear) 
        {
            j = queue[head++];  // 出队列
            node = g.adj_list[j].edge_next;
            while (node != NULL)
            {
                k = node->adj_vex;
                if (!visited[k])
                {
                    visited[k] = 1;
                    printf("%d ", g.adj_list[k].vertex);
                    queue[rear++] = k;
                }
                node = node->next;
            }
        }
    }
    printf("\n");
}
int main()
{
    adj_matrix* g= (adj_matrix*)malloc(sizeof(adj_matrix));
    create(g);
    display(g);
    bfs(*g);
    printf("1 2 3\n");
    system("pause");
    return 0;
}