#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge
{
    int src, dest, weight;
};


struct Graph
{
    int V,E;

    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->E = E;
    graph->V = V;
    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
    return graph;
};

struct Edge* sort_edge(struct Edge* edge, struct Graph* graph)
{
    for(int k=0;k < graph->E ; k++)
    {
        for(int l=0;l < graph->E-1-k; l++)
        {
            if(edge[l].weight > edge[l+1].weight)
            {
               struct Edge temp;
               temp = edge[l];
               edge[l] = edge[l+1];
               edge[l+1] = temp;
            }
        }
    }
    return edge;
}


int find(int parent[], int i)
{
    if(parent[i]== -1)
        return i;
    return find(parent, parent[i]);
}
void Union(int parent[],int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    if(xset != yset){
        parent[xset] = yset;
    }
}
void kruskalMST( struct Graph* graph)
{
    int *parent = (int*)malloc(graph->V * sizeof(int));
    memset(parent, -1, sizeof(int) * graph->V);
    int count = 0, weight =0;

    while(count<= graph->V-1){
        for(int i=0; i < graph->E; i++)
        {
            int x = find(parent, graph->edge[i].src);
            int y = find(parent, graph->edge[i].dest);
            if(x!=y)
            {
                Union(parent, x, y);
                count++;
                weight = weight + graph->edge[i].weight;
                printf("edge %d to %d selected \n",graph->edge[i].src,graph->edge[i].dest);
            }
        }
    }
}
int main()
{
    int V=6, E=8;
    struct Graph* graph = createGraph(V,E);

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 2;

    graph->edge[0].src = 0;
    graph->edge[0].dest = 5;
    graph->edge[0].weight = 2;

    graph->edge[3].src = 0;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 3;

    graph->edge[2].src = 3;
    graph->edge[2].dest = 4;
    graph->edge[2].weight = 3;

    graph->edge[4].src = 4;
    graph->edge[4].dest = 5;
    graph->edge[4].weight = 3;


    graph->edge[5].src = 0;
    graph->edge[5].dest = 4;
    graph->edge[5].weight = 4;

    graph->edge[6].src = 0;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 4;

    graph->edge[7].src = 1;
    graph->edge[7].dest = 2;
    graph->edge[7].weight = 4;

    //graph->edge = sort_edge(graph->edge,graph);
    kruskalMST(graph);

    return 0;
}
