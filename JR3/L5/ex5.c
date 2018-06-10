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

/*
void delete(list l) {
  if(l->next != NULL){
    list del;
    del = l->next;
    l->next = l->next->next;
    free(del);
  }
}
*/

void search(list l) {
  list head = l, end, top;
  while(l->next != NULL){
    l = l->next;
  }
  end = l;
  l = head;
  
  while(l != NULL){
    l = l->next;
    if(l->next->element == '('){
      top = l->next->next;
      list n = l->next;
      while(n->next->element == ')') {
	n = n->next;
      }
      list hozon = n->next;
      n->next = head->next;
      head->next = top;
      free(l->next);
      l->next = hozon->next;
      free(hozon);
    }

    if(l->next->element == '['){
      top = l->next->next;
      list n = l->next;
      while(n->next->element == ']') {
	n = n->next;
      }
      list hozon = n->next;
      n->next = NULL;
      end->next = top;
      free(l->next);
      l->next = hozon->next;
      free(hozon);
      end = n;
    }
  }
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
  //  small = (struct node*)malloc(sizeof(struct node));
  //  big = (struct node*)malloc(sizeof(struct node));

  list head = l;

  //lに順番に入れる
  fgets(buf, sizeof(buf), stdin);
  for(i=0; (c = buf[i]) != '\n'; ++i) {
    insert(l, c);
    l = l->next;
  }
  
  l = head;
  
  search(l); 
  l = head;
  search(l);
  print_char_list(head);
  
  return 0;
}
