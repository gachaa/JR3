#include<stdio.h>

int count = 0;
char kijun;

struct point {int x, y;};

int compare(struct point p1, struct point p2) {
  ++count;
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

//mからh番目とh+1からn番目までがそれぞれ昇順に整列されているとき、
//それらを組み合わせて全体が昇順に整列されている状態にする。
void merge(struct point a[], int m, int n, int h) {
  int i = m, j = h+1, k = 0, result;
  struct point b[128];

  while(i <= h && j <= n){
    if(compare(a[i], a[j]) <= 0){
      b[k] = a[i];
      i++;
    } else {
      b[k] = a[j];
      j++;
    }
    k++;
  }
  
  for(; i<=h; i++){
    b[k] = a[i];
    k++;
  }
  for(; j<= n; j++) {
    b[k] = a[j];
    k++;
  }
 
  for(i=m; i<=n; i++) {
    a[i] = b[i];
  }

  return;
}

int main() {
  char buf[128];
  struct point p, arr[128];
  int i = 0, h, n;
  
  scanf("%c %d ", &kijun, &h);
  while(fgets(buf, sizeof(buf), stdin) != NULL && i<128) {
    sscanf(buf, "%d %d", &p.x, &p.y);
    arr[i] = p;
    ++i;
  }
  //nは要素数
  n = i;
  merge(arr, 0, n-1, h);
  printf("%d\n", count);
  for(i=0; i<n; i++) {
    printf("%d %d\n", arr[i].x, arr[i].y);
  }
  return 0;
}
