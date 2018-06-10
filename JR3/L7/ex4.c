#include<stdio.h>

struct point { int x, y; };

int compare_by(struct point p1, struct point p2, char c) {
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
  int i, j;
  struct point b;
  for(i=1; i<n; i++) {
    b = a[i];
    j = i;
    while(j>0 && compare_by(a[j-1], b, c) >= 0) {
      a[j] = a[j-1];
      j--;
    }
    a[j] = b;
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
  insert_by(arr, n, c);
  for(i=0; i<n; ++i) {
    printf("%d %d\n", arr[i].x, arr[i].y); 
  }
  return 0;
}
