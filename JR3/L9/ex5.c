#include<stdio.h>

struct point {int x, y;};

//先頭n番めの要素について昇順に整列
void bucket_sort(struct point a[], int n){
  int i, j, c[100] = {};
  struct point b[n];
  for(i=0; i<n; i++){
    c[a[i].x]++;
    b[i] = a[i];
  }
  for(i=0; i+1<100; i++){
    c[i+1] += c[i];
  }

  for(i=n-1; i>=0; i--){
    c[b[i].x]--;
    a[c[b[i].x]] = b[i];
  }
}

void radix_sort(struct point a[], int n, int r, int dmax){

}


int main() {
  char buf[128];
  struct point p, arr[128];
  int i = 0, n, r, dmax;

  scanf("%d %d ", &r, &dmax);
  while(fgets(buf, sizeof(buf), stdin) != NULL && i<128) {
    sscanf(buf, "%d %d", &p.x, &p.y);
    arr[i] = p;
    i++;
  }
  //nは要素数
  n = i;

  radix_sort(arr, n, r, dmax);

  return 0;
}
