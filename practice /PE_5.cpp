#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define N 4
#define INF 999999

int min(int a, int b) { return a < b ? a : b; }

// Implementing a naive recursive approach to solving TSP
int tsp(int graph[][N], int s, int V, int visited)
{
    visited |= (1 << s); // Mark the current node as visited

    if (visited == (1 << V) - 1) // Check if all vertices are visited
        return graph[s][0];      // Return to starting point cost

    int minCost = INF;
    for (int i = 0; i < V; i++)
    {
        if (!(visited & (1 << i)))
        {
            int cost = graph[s][i] + tsp(graph, i, V, visited); // Recur to find the cost of the next city
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int main()
{
    int graph[][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};
    int result = tsp(graph, 0, N, 0); // Start TSP from the first city
    printf("Minimal cost of travelling using TSP: %d\n", result);
}