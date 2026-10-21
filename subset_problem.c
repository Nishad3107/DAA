#include <stdio.h>

int a[100], subset[100];
int result[1000][100], resultSize[1000];
int n, target, count = 0;

void subsetSum(int index, int sum, int size) {
  if (index == n) {
    if (sum == target) {
      for (int i = 0; i < size; i++) {
        result[count][i] = subset[i];
      }

      resultSize[count] = size;
      count++;
    }
    return;
  }

  subset[size] = a[index];
  subsetSum(index + 1, sum + a[index], size + 1);

  subsetSum(index + 1, sum, size);
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  scanf("%d", &target);

  subsetSum(0, 0, 0);

  if (count == 0) {
    printf("-1\n");
  } else {
    for (int i = count - 1; i >= 0; i--) {
      for (int j = 0; j < resultSize[i]; j++) {
        printf("%d ", result[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}