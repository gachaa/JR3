#include<stdio.h>
#define SETMAX 10600
char buf[256];

int dist[SETMAX] = { 81, 52, 46, 80, 31, 67, 56, 31, 38, 40 };

struct set { int elements[SETMAX]; int size; };

//pの要素のうち、dist[m]の値がもっとも小さくなる要素mを削除し、
//その要素を返す関数
int delete_min(struct set *p) {
  if(p->size == 0) return -1;
  else {
    int i, min = dist[p->elements[0]], min_id = 0;
    for(i=0; i<p->size; i++){
      if(min > dist[p->elements[i]]){
	min = dist[p->elements[i]];
	min_id = i;
      }
    }
    min = p->elements[min_id];
    p->elements[min_id] = p->elements[p->size-1];
    p->size -= 1;
    return min;
  }
}


//アドレスpの指す構造体setが表す集合からもっとも小さい要素を削除し、
//その要素を返す関数
int delete_min_int(struct set *p) {
  if(p->size == 0) return -1;
  else {
    int i, min = p->elements[0], min_id  = 0;
    for(i=0; i<p->size; i++) {
      if(min > p->elements[i]) {
	min = p->elements[i];
	min_id = i;
      }
    }
    p->elements[min_id] = p->elements[p->size-1];
    p->size -= 1;
    return min;
  }
}

void print_set(struct set *p) {
  int i;
  printf("{");
  for(i=0;i<p->size;++i) printf(" %d",p->elements[i]);
  printf(" }\n");
 }

int main() {
  int i, m;
  struct set s; 
  i = 0; 
  while(fgets(buf,sizeof(buf),stdin)!=NULL) {
    sscanf(buf, "%d ", &s.elements[i]);
    ++i; 
  }
  s.size = i; 
  while(1) {
    m = delete_min(&s);
    if(m<0) break; 
    printf("%d : ",m); print_set(&s);
  }
  return 0;
}
