#include <stdio.h>

#define INF 999999

struct Edge {
  int u, v, w;
};

void printPath(int parent[], int vertex) {
  if (parent[vertex] == -1) {
    printf("%d", vertex);
    return;
  }

  printPath(parent, parent[vertex]);
  printf("->%d", vertex);
}

int main() {
  int V, E;

  scanf("%d", &V);
  scanf("%d", &E);

  struct Edge edges[E];

  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
  }

  int source;
  scanf("%d", &source);

  int dist[V + 1];
  int parent[V + 1];

  for (int i = 1; i <= V; i++) {
    dist[i] = INF;
    parent[i] = -1;
  }

  dist[source] = 0;

  for (int i = 1; i <= V - 1; i++) {
    int updated = 0;

    for (int j = 0; j < E; j++) {
      int u = edges[j].u;
      int v = edges[j].v;
      int w = edges[j].w;

      if (dist[u] != INF && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        parent[v] = u;
        updated = 1;
      }
    }

    if (!updated)
      break;
  }

  for (int i = 0; i < E; i++) {
    int u = edges[i].u;
    int v = edges[i].v;
    int w = edges[i].w;

    if (dist[u] != INF && dist[u] + w < dist[v]) {
      printf("Negative cycle detected\n");
      return 0;
    }
  }

  for (int i = 1; i <= V; i++) {
    if (i == source)
      continue;

    if (dist[i] == INF) {
      printf("%d INF None\n", i);
    } else {
      printf("%d %d ", i, dist[i]);
      printPath(parent, i);
      printf("\n");
    }
  }

  return 0;
}