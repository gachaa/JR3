#include<stdio.h>

struct point {int x, y;};
struct point_loc {int loc; struct point p;};

//p1が大きければ1、同じなら0を返す
int compare_by(struct point p1, struct point p2, char c) {
  if(c == 'x'){
    if(p1.x > p2.x) return 1;
    else if(p1.x == p2.x) return 0;
    else return -1;
  }else if(c == 'y'){
    if(p1.y > p2.y) return 1;
    else if(p1.y == p2.y) return 0;
    else return -1;
  }else if(c == 'd'){
    int len1, len2;
    len1 = (p1.x)*(p1.x) + (p1.y)*(p1.y);
    len2 = (p2.x)*(p2.x) + (p2.y)*(p2.y);
    //    printf("length: p1 %d, p2 %d\n", len1, len2);
    if(len1 > len2) return 1;
    else if(len1 == len2) return 0;
    else return -1;
  }
}

//最大の要素の添字を返す
int max_index_by(struct point_loc arr[], int n, char c) { 
  struct point max = arr[0].p;
  int index = 0, i, compare_result, arr_index = arr[0].loc;
  
  for(i=1; i<n; i++) {
    compare_result = compare_by(arr[i].p, max, c);
    if(compare_result == 1 || (compare_result == 0 && arr[i].loc > arr_index)){
      //      printf("%5d, %5dで更新 res: %d loc: %d\n", arr[i].p.x, arr[i].p.y, compare_result, arr[i].loc);
      max = arr[i].p;
      arr_index = arr[i].loc;
      index = i;
    }
  }
  //  printf("\n");
  //  printf("ind: %d\n", index);
  return index;
}

/*
//a[]を昇順に整列する関数。
void selection_sort(struct point a[], int n, char c) {
  int k, i;
  struct point x;
  for(k=n; k>=2; --k) {
    i = max_index_by(a, k, c);
    x = a[k-1];
    a[k-1] = a[i];
    a[i] = x;
  }
}
*/

void stable_selection_sort(struct point a[], int n, char c) {
  struct point_loc arr[128] = {}, w;
  int k, i;
  struct point v;

  for(i=0; i<n; i++) {
    arr[i].loc = i;
    arr[i].p = a[i];
  }

  for(k=n; k>=2; --k) {
    i = max_index_by(arr, k, c);
    v = a[k-1];
    a[k-1] = a[i];
    a[i] = v;
    w = arr[k-1];
    arr[k-1] = arr[i];
    arr[i] = w;
  }  
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
  stable_selection_sort(arr, n, c);
  for(i=0; i<n; ++i) {
    printf("%d %d\n", arr[i].x, arr[i].y);
  }
  return 0;
}
