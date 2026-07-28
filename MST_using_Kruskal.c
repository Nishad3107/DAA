#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int find(int parent[], int i) {
  if (parent[i] == i)
    return i;
  return parent[i] = find(parent, parent[i]);
}

// Helper function to perform union of two subsets
void unionSets(int parent[], int u, int v) {
  int root_u = find(parent, u);
  int root_v = find(parent, v);
  parent[root_u] = root_v;
}
void kruskalMST(int **cost, int V) {
  int parent[V];
  for (int i = 0; i < V; i++) {
    parent[i] = i;
  }
  int edge_count = 0;
  int mincost = 0;
  while (edge_count < V - 1) {
    int min = 9999;
    int a = -1, b = -1;
    for (int i = 0; i < V; i++) {
      for (int j = i + 1; j < V; j++) {
        if (cost[i][j] < min) {
          min = cost[i][j];
          a = i;
          b = j;
        }
      }
    }
    if (a == -1 || b == -1 || min == 9999) {
      break;
    }
    if (find(parent, a) != find(parent, b)) {
      printf("Edge %d:(%d, %d) cost:%d\n", edge_count, a, b, min);
      mincost += min;
      unionSets(parent, a, b);
      edge_count++;
    }
    cost[a][b] = 9999;
    cost[b][a] = 9999;
  }
  printf("Minimum cost= %d\n", mincost);
}

int main() {
  int V;
  printf("No of vertices: ");
  scanf("%d", &V);

  int **cost = (int **)malloc(V * sizeof(int *));
  for (int i = 0; i < V; i++)
    cost[i] = (int *)malloc(V * sizeof(int));

  printf("Adjacency matrix:\n");
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      scanf("%d", &cost[i][j]);

  kruskalMST(cost, V);

  for (int i = 0; i < V; i++)
    free(cost[i]);
  free(cost);

  return 0;
}