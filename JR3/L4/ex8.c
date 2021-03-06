#include<stdio.h>
#include<stdlib.h>
#define N 10

char heya[N][N];
char buf[N+2];

struct zahyo {int x, y; };

typedef struct zahyo elementtype;

struct queue {
  int front, rear;
  elementtype contents[N*N];
};


void initqueue(struct queue *q) {
  q->rear = 0;
  q->front = 0;
  return;
}

int queueempty(struct queue *q) {
  return (q->front != q->rear);
}

void putq(struct queue *q, elementtype x){
  q->contents[q->rear] = x;
  q->rear += 1;
  if(q->rear > N*N) {
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
  int i, j;
  struct zahyo start, goal, pos;
  int kyori[N][N];

  //kyoriの初期化(全て-1)
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      kyori[i][j] = -1;
    }
  }

  initqueue(&q);
  

  i = 0;
  while(fgets(buf, sizeof(buf), stdin) != NULL) {
    for(j=0; j<N; j++) {
      if(buf[j] == 'S') {
	start.x = i; start.y = j;
	kyori[i][j] = 0;
      } else if(buf[j] == 'G') {
	goal.x = i; goal.y = j;
      }
      heya[i][j] = buf[j];
    }
    i++;
  }

  putq(&q, start);

  while(queueempty(&q)) {
    pos = getq(&q);
    if(kyori[pos.x][pos.y-1] == -1 && heya[pos.x][pos.y-1] != '*'){
      kyori[pos.x][pos.y-1] = kyori[pos.x][pos.y] + 1;
      pos.y -= 1;
      putq(&q, pos);
      pos.y += 1;
    }
    if(kyori[pos.x][pos.y+1] == -1 && heya[pos.x][pos.y+1] != '*'){
      kyori[pos.x][pos.y+1] = kyori[pos.x][pos.y] + 1;
      pos.y += 1;
      putq(&q, pos);
      pos.y -= 1;
    }
    if(kyori[pos.x-1][pos.y] == -1 && heya[pos.x-1][pos.y] != '*'){
      kyori[pos.x-1][pos.y] = kyori[pos.x][pos.y] + 1;
      pos.x -= 1;
      putq(&q, pos);
      pos.x += 1;
    }
    if(kyori[pos.x+1][pos.y] == -1 && heya[pos.x+1][pos.y] != '*'){
      kyori[pos.x+1][pos.y] = kyori[pos.x][pos.y] + 1;
      pos.x += 1;
      putq(&q, pos);
      pos.x -= 1;
    }
  }
  
  printf("%d\n", kyori[goal.x][goal.y]);
  
  return 0;
}
