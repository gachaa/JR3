#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 128

char buf[128];

typedef int elementtype;

struct queue {
  int front, rear;
  elementtype contents[QUEUESIZE];
};

void initqueue(struct queue *q) {
  q->rear = 0;
  q->front = 0;
  return;
}

int queueempty(struct queue *q) {
  return (q->front == q->rear);
}

void putq(struct queue *q, elementtype x){
  q->contents[q->rear] = x;
  q->rear += 1;
  if(q->rear > QUEUESIZE) {
    printf("Sorry.\n");
    exit(1);
  }
  return;
}

elementtype getq(struct queue *q) {
  elementtype x;
  if(q->rear == q->front) {
    printf("Underflow.\n");
    exit(1);
  } else {
    x = q->contents[q->front];
    q->front += 1;
    return x;
  }
}

void printqueue(struct queue *q) {
  int i;
  for(i=q->front; i<q->rear; i++){
    printf("[%d]", q->contents[i]);
  }
  printf("\n");
}

int main() {
  struct queue q;
  int i;
  initqueue(&q);
  while(fgets(buf, sizeof(buf), stdin) != NULL) {
    if(buf[0] == 'g') {                                                                
      getq(&q);
    } else {
      sscanf(buf, "%d", &i);                                                                 putq(&q, i);
    }                                                                           
    printqueue(&q);
  }
  return 0;
}
