#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
  int vertex;
  struct Node *next;
} Node;

Node *adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

Node *createNode(int vertex) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->vertex = vertex;
  newNode->next = NULL;
  return newNode;
}

void addEdge(int u, int v) {
  Node *newNode = createNode(v);
  newNode->next = adjList[u];
  adjList[u] = newNode;
}

void sortAdjList(int V) {
  for (int i = 0; i < V; i++) {
    if (adjList[i] == NULL || adjList[i]->next == NULL)
      continue;
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;
    do {
      swapped = 0;
      ptr1 = adjList[i];

      while (ptr1->next != lptr) {
        if (ptr1->vertex > ptr1->next->vertex) {
          int temp = ptr1->vertex;
          ptr1->vertex = ptr1->next->vertex;
          ptr1->next->vertex = temp;
          swapped = 1;
        }
        ptr1 = ptr1->next;
      }
      lptr = ptr1;
    } while (swapped);
  }
}

void DFS(int start) {
  visited[start] = 1;
  printf("%d ", start);

  Node *temp = adjList[start];
  while (temp != NULL) {
    int adjVertex = temp->vertex;
    if (!visited[adjVertex]) {
      DFS(adjVertex);
    }
    temp = temp->next;
  }
}

int main() {
  int V, E;
  int u, v, start;

  scanf("%d %d", &V, &E);

  for (int i = 0; i < V; i++) {
    adjList[i] = NULL;
    visited[i] = 0;
  }

  for (int i = 0; i < E; i++) {
    scanf("%d %d", &u, &v);
    addEdge(u, v);
  }

  sortAdjList(V);

  scanf("%d", &start);

  DFS(start);

  return 0;
}