#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define V 6

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for(int v=0; v<V; v++)
    {
        if(mstSet[v] == false && key[v]<min)
            min = key[v], min_index = v;
    }
    return min_index;
}

void printMst(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for(int i=1; i<V; i++)
        printf("%d - %d \t%d \n",parent[i],i,graph[i][parent[i]]);
}

void primMst(int graph[V][V])
{
    int parent[V];

    int key[V];

    bool mstSet[V];

    for(int i=0; i<V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for(int count =0; count<V-1; count++)
    {

        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for(int v=0; v<V; v++)
        {
            if(graph[u][v]!=0 && mstSet[v] == false && graph[u][v]<key[v])
                parent[v] = u, key[v] = graph[u][v];
        }
    }
    printMst(parent, graph);
}



int main()
{

    int graph[V][V] =

    {
        {0,4,2,3,4,2},
        {4,0,4,0,0,0},
        {2,4,0,0,0,0},
        {3,0,0,0,3,0},
        {4,0,0,3,0,3},
        {2,0,0,0,3,0}

    };
    primMst(graph);
    printf("Hello world!\n");
    return 0;
}
