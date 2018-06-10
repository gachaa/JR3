#include<stdio.h>
#include<stdlib.h>

typedef int elementtype;
typedef struct node* list;

struct node {
  elementtype element;
  struct node *next;
};

list cons(elementtype e, list l){
  struct node *n = (struct node*)malloc(sizeof(struct node));
  n->element = e;
  n->next = l;
  return n;
}

int length(list l){
  list cur = l->next;
  int count=0;
  while(cur != NULL){
    count++;
    cur = cur->next;
  }
  return count;
}

void print_int_list(list l) {
  list cur = l->next;
  while(cur != NULL) {
    printf("[%d]", cur->element);
    cur = cur->next;
  }
  printf("\n");
}


int main() {
  int i;
  char buf[128];
  list l, last;
  l = (struct node*)malloc(sizeof(struct node));
  last = l;
  while(fgets(buf, sizeof(buf), stdin) != NULL) {
    sscanf(buf, "%d", &i);
    last->next = cons(i, NULL);
    last = last->next;
  }
  printf("length=%d\n", length(l));
  print_int_list(l);
  
  return 0;
}
