#include<stdio.h>
#include<stdlib.h>

typedef char elementtype;
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

void print_char_list(list l) {
  list cur = l->next;
  while(cur != NULL) {
    printf("%c", cur->element);
    cur = cur->next;
  }
  printf("\n");
}


int main() {
  int i;
  char c, buf[128];
  list l;
  l = (struct node*)malloc(sizeof(struct node));
  list head = l;
  fgets(buf, sizeof(buf), stdin);
  for(i=0; (c = buf[i]) != '\n'; ++i) {
    insert(l, c);
    l = l->next;
  }
  print_char_list(head);
  while(fgets(buf, sizeof(buf), stdin) != NULL) {
    sscanf(buf, "%d %c", &i, &c);
    int j;
    l = head;
    for(j=0; j<i; j++){
      l = l->next;
      if(l->next == NULL)break;
    }
    insert(l, c);
    l = head;
    print_char_list(l);
  }

  return 0;
}
