#include<stdio.h>

int max_index(int a[], int n) {
  int max = a[0], maxInd = 0, i;
  for(i=0; i<n; i++) {
    if(max<=a[i]) {
      max = a[i];
      maxInd = i;
    }
  }
  return maxInd;
}

int main() {
  char buf[128];
  int arr[128], i = 0;
  while(fgets(buf, sizeof(buf), stdin) != NULL && i<128) {
    sscanf(buf, "%d", &arr[i++]);
  }

  printf("%d\n", max_index(arr, i));
  return 0;
}
