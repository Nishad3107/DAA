#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int main() {
  int n;
  if (scanf("%d", &n) != 1)
    return 0;

  int values[1005];
  for (int i = 0; i < n; i++) {
    scanf("%d", &values[i]);
  }

  int weights[1005];
  for (int i = 0; i < n; i++) {
    scanf("%d", &weights[i]);
  }

  int W;
  scanf("%d", &W);

  int dp[1005] = {0};

  for (int i = 0; i < n; i++) {
    for (int w = W; w >= weights[i]; w--) {
      dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
    }
  }

  printf("%d\n", dp[W]);

  return 0;
}