#include<stdio.h>
#include<stdlib.h>
#define N 11
char buf[N+2];
char canvas[N][N];

typedef struct zahyo elementtype;

struct zahyo {int x, y; };
struct stack { int top; elementtype contents[128]; };

void initstack(struct stack *p){
  p->top = -1;
  return;
}

int stackempty(struct stack *p) {
  return (p->top < 0);
}

elementtype pop(struct stack *p) {
  elementtype g;
  if(p->top < 0){
    printf("Underflow.\n");
    exit(1);
  } else {
    g = p->contents[p->top];
    p->top -= 1;
    return g;
  }
}

void push(struct stack *p, elementtype pos) {
  p->top += 1;
  p->contents[p->top] = pos;
  
  return;
}

int main() {
  int i, j;
  i=0;

  while(fgets(buf, sizeof(buf), stdin) != NULL){
    for(j=0; j<N; j++){
      canvas[i][j] = buf[j];
    }   
    i++;
  }

  struct stack s;
  struct zahyo position;
  position.x = N/2; position.y = N/2;

  initstack(&s);
  push(&s, position);

  if(canvas[N/2][N/2] == ' ')canvas[N/2][N/2] = '.';

  while(s.top >= 0){
    position = pop(&s);
    if(canvas[position.x][position.y -1] == ' ') {
      position.y -= 1;
      if(position.y >= 0)push(&s, position);
      position.y += 1;
      canvas[position.x][position.y -1] = '.';
    }
    if(canvas[position.x][position.y +1] == ' ') {
      position.y += 1;
      if(position.y < N)push(&s, position);
      position.y -= 1;
      canvas[position.x][position.y +1] = '.';
    }
    if(canvas[position.x -1][position.y] == ' '){
      position.x -= 1;
      if(position.x >= 0)push(&s, position);
      position.x += 1;
      canvas[position.x -1][position.y] = '.';
    }
    if(canvas[position.x +1][position.y] == ' ') {
      position.x += 1;
      if(position.x < N)push(&s, position);
      position.x -= 1;
      canvas[position.x +1][position.y] = '.';
    }
  }
  
  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      printf("%c", canvas[i][j]);
    }
    printf("\n");
  }
  return 0;

}
