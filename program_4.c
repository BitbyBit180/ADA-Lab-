// 4. Design and implement C/C++ Program to find shortest paths from a given vertex in a weighted connected graph to other vertices using Dijkstra's algorithm.

#include <stdio.h>

int main()
{
    int n, cost[10][10];
    int dist[10], visited[10];
    int i, j, source, min, u;

    // Read number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Read cost matrix
    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            // Replace 0 with infinity (999)
            // except for self-loops
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    // Read source vertex
    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize distance and visited arrays
    for(i = 0; i < n; i++)
    {
        // Distance from source to each vertex
        dist[i] = cost[source][i];

        // Initially all vertices are unvisited
        visited[i] = 0;
    }

    // Distance from source to itself is 0
    dist[source] = 0;

    // Mark source as visited
    visited[source] = 1;

    // Repeat for remaining vertices
    for(i = 1; i < n; i++)
    {
        min = 999;

        // Find unvisited vertex with minimum distance
        for(j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        // Mark selected vertex as visited
        visited[u] = 1;

        // Update distances of adjacent vertices
        for(j = 0; j < n; j++)
        {
            if(!visited[j] &&
               dist[u] + cost[u][j] < dist[j])
            {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    // Display shortest distances
    printf("\nShortest Distances from Vertex %d:\n", source);

    for(i = 0; i < n; i++)
    {
        printf("%d -> %d = %d\n", source, i, dist[i]);
    }

    return 0;
}