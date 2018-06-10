#include<stdio.h>
#include<stdlib.h>
#define SIZE 101

int count = 0;

struct student {int id; char name[32]; int score; };

struct node {struct student data; struct node *next;};

int hash(char *s){
  int i = 0, ans;
  while(s[i] != '\0'){
    if(i==0) ans = s[0]%SIZE;
    else ans = (ans*128 + s[i]) % SIZE;
    i++;
  }
  return ans;
}

void set_data(struct node *table[], struct student st) {
  struct node *n = (struct node*) malloc(sizeof(struct node));
  n->data = st; 
  //n->next = NULL;
  int i = hash(st.name);
  /*
  while(table[i] != NULL) {
    printf("wairu\n");
    table[i] = table[i]->next;
  }
  */
  
  n->next = table[i];
  table[i] = n;
}

int main() {
  int i;
  char buf[128], c;
  struct student st;
  struct node *table[SIZE], *p;
  
  for(i=0; i<SIZE; i++) table[i] = NULL;
  while(fgets(buf, sizeof(buf), stdin) != NULL) {
    sscanf(buf, "%d,%[^,],%d", &st.id, st.name, &st.score);
    set_data(table, st);
  }
  
  for(i=0; i<SIZE; i++) {
    p = table[i];
    while(p != NULL) {
      st = p->data;
      printf("(%d)%d,%s,%d\n", i, st.id, st.name, st.score);
      p = p->next;
    }
  }
  return 0;
}
