#include<stdio.h>
#define SETMAX 10600

struct set { int elements[SETMAX]; int size; };

//eを除く0からn-1までの整数を要素とする集合をpに格納する関数
void init_set(struct set *p, int n, int e) {
  int i;
  for(i=0; i<n; i++) {
    if(i < e) p->elements[i] = i;
    else p->elements[i] = i+1;
  }
  p->size = n-1;
}

 void print_set(struct set *p) {
   int i;
   printf("{");
   for(i=0;i<p->size;++i) printf(" %d",p->elements[i]);
   printf(" }\n");
 }

int main() {
  int n, e;
  struct set s; 
  scanf("%d %d ", &n, &e); 
  init_set(&s, n, e); 
  print_set(&s);
  return 0;
}
