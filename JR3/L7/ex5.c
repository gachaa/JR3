#include<stdio.h>

int count = 0;
struct point { int x, y; };

int compare_by(struct point p1, struct point p2, char c) {
  ++count;
  if(c == 'X'){
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
  }else if(c == 'Y'){
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
  }else if(c == 'D'){
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

void insert_by(struct point a[], int n, char c) {
  int j;
  struct point v;
  v = a[n-1];
  j = n-1;
  while(j>0 && compare_by(a[j-1], v, c) == 1) {
    a[j] = a[j-1];
    j--;
  }
  a[j] = v;
  return;
}

void insertion_sort(struct point a[], int n, char c) {
  int k;
  for(k=2; k<=n; k++) {
    insert_by(a, k, c);
  }
  return;
}

int main() {
  char c, buf[128];
  struct point p, arr[128];
  int i=0, n;

  scanf("%c ", &c);
  while(fgets(buf,sizeof(buf),stdin)!=NULL && i<128) {
    sscanf(buf,"%d %d",&p.x,&p.y);
    arr[i] = p;
    ++i;
  }

  n = i;
  insertion_sort(arr, n, c);
  printf("%d\n", count);
  for(i=0; i<n; ++i) {
    printf("%d %d\n", arr[i].x, arr[i].y); 
  }
  return 0;
}
