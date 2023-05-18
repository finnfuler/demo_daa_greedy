#include <stdio.h>

int prev[5];
int leastedge[5];
int included[5];
int mincost=0;
int least()
{
    int min = 100, minvertex;
    for (int j = 1; j < 5; j++)
    {
        if (included[j] == 0 && leastedge[j] < min)
            min = leastedge[j], minvertex = j;
    }
    return minvertex;
}

void main()
{
    int adjmat[5][5];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &adjmat[i][j]);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        leastedge[i] = 100, included[i] = 0;
    }
    leastedge[0] = 0;
    prev[0] = -1;
    for (int i = 0; i < 4; i++)
    {
        int u = least();
        included[u] = 1;
        for (int v = 0; v < 5; v++)
        {
            if (adjmat[u][v] && included[v] == 0 && adjmat[u][v] < leastedge[v])
            {
                prev[v] = u, leastedge[v] = adjmat[u][v];
                // mincost = mincost + adjmat[u][v];
            }
                
        }
    }
    printf("Edges included in the MST will be:\n");
    for (int i = 1; i < 5; i++)
        printf("%c%c\t", prev[i] + 65, i + 65);

    // printf("\nMinimum cost = %d",mincost);
}
