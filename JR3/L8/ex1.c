#include<stdio.h>

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

//mからnについて小さい大きいて移す関数
int partition(struct point a[], int m, int n) {
  struct point pivot = a[m], t;
  int l = m+1, r = n;

  while(1) {
    while(compare(a[l], pivot) <= 0 && l<n) l++;
    while(compare(a[r], pivot) >= 0 && m<r) r--;
    if(r<=l) break;
    t = a[l]; a[l] = a[r]; a[r] = t;
    l++;
    r--;
  }
  a[m] = a[r];
  a[r] = pivot;
  return r;
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
  printf("%d\n", partition(arr, 0, n-1));
  //
  for(i=0; i<n; i++) {
    printf("%d %d\n", arr[i].x, arr[i].y);
    //
  }
  //
  return 0;
}
