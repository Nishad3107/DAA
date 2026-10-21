#include <limits.h>
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {

  int dist[MAX];
  int visited[MAX];
  int parent[MAX];
  int i, j, count;
  int min, u;

  for (i = 1; i <= n; i++) {
    dist[i] = INFINITY;
    visited[i] = 0;
    parent[i] = -1;
  }
  dist[startnode] = 0;
  for (count = 1; count <= n; count++) {
    min = INFINITY;
    u = -1;

    for (i = 1; i <= n; i++) {
      if (visited[i] == 0 && dist[i] < min) {
        min = dist[i];
        u = i;
      }
    }
    if (u == -1)
      break;
    visited[u] = 1;
    for (j = 1; j <= n; j++) {

      if (visited[j] == 0 && G[u][j] != 0 && dist[u] != INFINITY &&
          dist[u] + G[u][j] < dist[j]) {
        dist[j] = dist[u] + G[u][j];
        parent[j] = u;
      }
    }
  }
  printf("Node\tDistance\tPath\n");
  for (i = 1; i <= n; i++) {
    if (i == startnode)
      continue;
    if (dist[i] == INFINITY) {
      printf("%4d\t%8s\tNO PATH\n", i, "INF");
    } else {
      int path[MAX];
      int k = 0;
      int current = i;
      while (current != -1 && k < MAX) {
        path[k] = current;
        k++;
        current = parent[current];
      }
      printf("%4d\t%8d\t", i, dist[i]);

      for (j = 0; j < k; j++) {
        if (j > 0)
          printf("<-");
        printf("%d", path[j]);
      }
      printf("\n");
    }
  }

  // write your code here
}
int main() {
  int s, d, w, i, j;
  printf("Enter the number of vertices : ");
  scanf("%d", &V);
  printf("Enter the number of edges : ");
  scanf("%d", &E);
  for (i = 1; i <= V; i++) {
    for (j = 1; j <= V; j++) {
      graph[i][i] = 0;
    }
  }
  for (i = 1; i <= E; i++) {
    printf("Enter source : ");
    scanf("%d", &s);
    printf("Enter destination : ");
    scanf("%d", &d);
    printf("Enter weight : ");
    scanf("%d", &w);
    if (s > V || d > V || s <= 0 || d <= 0) {
      printf("Invalid index. Try again.\n");
      i--;
      continue;
    } else {
      graph[s][d] = w;
    }
  }
  printf("Enter the source :");
  scanf("%d", &s);
  dijkstra(graph, V, s);
  return 0;
}