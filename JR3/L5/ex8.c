#include<stdio.h>
#include<stdlib.h>

typedef int elementtype;
typedef struct node* list;

struct node {
  elementtype element;
  struct node *next;
};

void insert(list l, elementtype e) {
  struct node *n = (struct node*)malloc(sizeof(struct node));
  n->element = e;
  n->next = l->next;
  l->next = n;
  return;
}

void delete(list l) {
  if(l->next != NULL){
    list del;
    del = l->next;
    l->next = l->next->next;
    free(del);
  }
}

void print_all(list l) {
  while(l->next != NULL) {
    l = l->next;
    printf("%d\n", l->element);
  }
  return;
}

int abs(int i) {
  if(i < 0)return i * (-1);
  else return i;
}

int main() {
  int i;
  char buf[128];
  list l, head;
  l = (struct node*)malloc(sizeof(struct node));
  head = l;
  
  while(fgets(buf, sizeof(buf), stdin) != NULL) {
    sscanf(buf, "%d", &i);
    
    if(l->next != NULL){
      while(abs(l->next->element) > abs(i)) {
	l = l->next;
	if(l->next == NULL) break;
      }
    }
    if(l->next != NULL){
      if(i < 0 && l->next->element == -1*i){
	l = l->next;
      }
    }
    insert(l, i);
    
    if(l->next->next != NULL){
      if(l->next->element == l->next->next->element) delete(l);
    }
    l = head;
  }

  print_all(head);

  return 0;
}
