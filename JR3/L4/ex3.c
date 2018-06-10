#include<stdio.h>
#include<stdlib.h>
#define MAXSTACK 128

char buf[128];

typedef int elementtype;
struct stack {
  int top;
  elementtype contents[MAXSTACK];
};

void initstack(struct stack *p){
  p->top = -1;
  return;
}

int stackempty(struct stack *p) {
  return (p->top < 0);
}

elementtype pop(struct stack *p) {
  elementtype x;
  if(p->top < 0){
    printf("Underflow.\n");
    exit(1);
  } else {
    x = p->contents[p->top];
    p->top -= 1;
    return x;
  }
}

void stackprint(struct stack *p) {
  int i;
  for(i=0; i<=p->top; i++){
    printf("[%d]", p->contents[i]);
  }
  printf("\n");
}

void push(struct stack *p, elementtype e) {
  p->top += 1;
  if(p->top >= MAXSTACK){
    printf("Overflow.\n");
    exit(1);
  } else {
    p->contents[p->top] = e;
  }
  return;
}

int main() {
  struct stack s;
  int i;
  initstack(&s);
  while(fgets(buf, sizeof(buf), stdin) != NULL) {
    if(buf[0] == 'p') {
      //pop
      pop(&s);
    } else {
      sscanf(buf, "%d", &i);
      //push
      push(&s, i);
    }
    //出力
    stackprint(&s);
  }

}
