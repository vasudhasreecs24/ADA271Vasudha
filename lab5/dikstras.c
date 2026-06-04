#include <stdio.h>

int cost[10][10], dist[10], visited[10], n, src;

void dijkstra()
{
    int i, j, count = 1, min, u;

    for(i = 1; i <= n; i++)
    {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    while(count < n)
    {
        min = 999;
        for(i = 1; i <= n; i++)
        {
            if(dist[i] < min && !visited[i])
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(j = 1; j <= n; j++)
        {
            if(!visited[j] && (dist[u] + cost[u][j] < dist[j]))
            {
                dist[j] = dist[u] + cost[u][j];
            }
        }
        count++;
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra();

    printf("Shortest distances from source %d:\n", src);
    for(i = 1; i <= n; i++)
        printf("To %d = %d\n", i, dist[i]);

    return 0;
}
