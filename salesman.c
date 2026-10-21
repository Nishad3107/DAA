#include <stdio.h>

int n;
int cost[20][20];
int visited[20];
int min_cost = 9999999;

void tsp(int current_city, int count, int current_cost) {
  if (count == n) {
    if (cost[current_city][0] != -1) {
      if (current_cost + cost[current_city][0] < min_cost) {
        min_cost = current_cost + cost[current_city][0];
      }
    }
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i] && cost[current_city][i] != -1) {
      visited[i] = 1;
      tsp(i, count + 1, current_cost + cost[current_city][i]);
      visited[i] = 0;
    }
  }
}

int main() {
  if (scanf("%d", &n) != 1)
    return 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &cost[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }

  visited[0] = 1;
  tsp(0, 1, 0);

  printf("%d\n", min_cost);

  return 0;
}