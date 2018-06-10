#include<stdio.h>
#include<stdlib.h>
#define MAXSTACK 512

typedef char elementtype;
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

/*
void stackprint(struct stack *p) {
  int i;
  for(i=0; i<=p->top; i++){
    printf("[%d]", p->contents[i]);
  }
  printf("\n");
}
*/

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
  char c, input[MAXSTACK];
  
  scanf("%[^\n]", input);
  initstack(&s);

  for(i=0; i<MAXSTACK; i++) {
    c=input[i];
    if(c=='\0'){
      break;
    }else if(c=='(' || c=='{'|| c=='['|| c=='<'){
      push(&s, c);
    }else if(c==')'){
      if(stackempty(&s) || pop(&s) != '('){
	printf("Bad.\n");
	exit(1);
      }
    }else if(c=='}'){
      if(stackempty(&s) || pop(&s) != '{'){
	printf("Bad.\n");
	exit(1);
      }
    }else if(c==']'){
      if(stackempty(&s) || pop(&s) != '['){
	printf("Bad.\n");
	exit(1);
      }
    }else if(c=='>'){
      if(stackempty(&s) || pop(&s) != '<'){
	printf("Bad.\n");
	exit(1);
      }
    }
  }

  if(stackempty(&s)){
    printf("Good.\n");
  }else{
    printf("Bad.\n");
    exit(1);
  }

  /*
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
  */

  return 0;
}
