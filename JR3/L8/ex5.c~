#include<stdio.h>
#include<stdlib.h>

char kijun;

struct point {int x, y;};

int compare(struct point p1, struct point p2) {
  if(kijun == 'X'){
    if(p1.x > p2.x){
      return 1;
    }else if(p1.x == p2.x){
      if(p1.y > p2.y){
	return 1;
      }else if(p1.y == p2.y) {
	return 0;
      }else{
	return -1;
      }
    }else{
      return -1;
    }
  }else if(kijun == 'Y'){
    if(p1.y > p2.y){
      return 1;
    }else if(p1.y == p2.y){
      if(p1.x > p2.x){
	return 1;
      }else if(p1.x == p2.x){
	return 0;
      }else{
	return -1;
      }
    }else{
      return -1;
    }
  }else if(kijun == 'D'){
    if(((p1.x)*(p1.x) + (p1.y)*(p1.y)) > ((p2.x)*(p2.x) + (p2.y)*(p2.y))) {
      return 1;
    }else if(((p1.x)*(p1.x) + (p1.y)*(p1.y)) == ((p2.x)*(p2.x) + (p2.y)*(p2.y))){
      if(p1.x > p2.x){
	return 1;
      }else if(p1.x == p2.x){
	if(p1.y > p2.y){
	  return 1;
	}else if(p1.y == p2.y) {
	  return 0;
	}else {
	  return -1;
	}
      }else{
	return -1;
      }
    }else{
      return -1;
    }
  }

}

//mからnについて小さい大きいで移す関数
int partition(struct point a[], int m, int n) {
  int l = m+1, r = n, p = m + rand()%(n-m+1);
  struct point pivot = a[p], t;
  a[p] = a[m]; a[m] = pivot;
  //  printf("m: %d n: %d p: %d\n", m, n, p);

  while(1) {
    while(l<n && compare(pivot, a[l]) == 1) l++;
    while(r>m && compare(a[r], pivot) == 1) r--;

    if(r > l){
      t = a[l];
      a[l] = a[r];
      a[r] = t;
    } else break;
    l++;r--;
  }

  //  printf("r: %d l: %d\na[i]: ", r, l);
  int i;
  for(i=m; i<=n; i++) {
    //    printf("[%d %d]", a[i].x , a[i].y);
  }
  //printf("\n");

  a[m] = a[r];
  a[r] = pivot;

  for(i=m; i<=n; i++) {
    //  printf("[%d %d]", a[i].x , a[i].y);
  }
  //printf("\n");

  return r;
}

void quicksort(struct point a[], int m, int n) {
  int p;
  if(m<n){
    p = partition(a, m, n);
    quicksort(a, m, p-1);
    quicksort(a, p+1, n);
  }
  return;
}


int main() {
  char buf[128];
  struct point p, arr[128];
  int i = 0, n;
  
  scanf("%c ", &kijun);
  while(fgets(buf, sizeof(buf), stdin) != NULL && i<128) {
    sscanf(buf, "%d %d", &p.x, &p.y);
    arr[i] = p;
    i++;
  }
  //nは要素数
  n = i;
  quicksort(arr, 0, n-1);
  for(i=0; i<n; i++) {
    printf("%d %d\n", arr[i].x, arr[i].y);
  }
  return 0;
}
