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


//先頭nこがヒープになって入れば1を、そうじゃなければ0を返す
int is_heap(struct point a[], int n) {
  int i;
  for(i=0; 2*i+2<=n; i++) {
    if(i == n/2-1) break;
    if(compare(a[2*i+1], a[i]) == 1 || compare(a[2*i+2], a[i]) == 1)return 0;
  }
  //最後だけ比較
  if(compare(a[2*i+1], a[i]) == 1) return 0;
  else if(n/2 == 1 && compare(a[2*i+2], a[i]) == 1) return 0;
  
  return 1;
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

  if(is_heap(arr, n)) printf("Yes.\n");
  else printf("No.\n");

  return 0;
}
