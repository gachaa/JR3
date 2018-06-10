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

int max_index_by(struct point a[], int n, char c) {
 
  struct point max = a[0];
  int index = 0, i;
  
  for(i=0; i<n; i++) {
    if(compare_by(max, a[i], c) <= 0){
      max = a[i];
      //      printf("%d, %d\n", max.x, max.y);
      index = i;
    }
  }
  return index;
}

int main() {
  char c, buf[128];
  struct point p, arr[128];
  int i=0;

  scanf("%c ", &c);
  while(fgets(buf,sizeof(buf),stdin)!=NULL && i<128) {
    sscanf(buf,"%d %d",&p.x,&p.y);
    arr[i] = p;
    ++i;
  }
  printf("%d\n", max_index_by(arr, i, c));
  return 0;
}
