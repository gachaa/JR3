#include<stdio.h>
#include<stdlib.h>
char buf[128];
struct student { int id; char name[32]; int score; };
typedef struct student datatype; 
struct rb_node { datatype data; struct rb_node *left, *right; int black; };

struct rb_node* get_rbtree() {
struct rb_node *t;
 char c;
 if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
   return NULL;
 else {
   t = (struct rb_node*)malloc(sizeof(struct rb_node));
   sscanf(buf,"[%c]%d,%[^,],%d",&c,&t->data.id,t->data.name,&t->data.score);
   t->black = (c=='b');
   // printf("%d", t->black);
   t->left = get_rbtree(); t->right = get_rbtree();
   return t;
 }
}

int condition2(struct rb_node *t) {
  if(t->black == 0){
    if((t->left != NULL && t->left->black == 0) || (t->right != NULL && t->right->black == 0)) return 0;
  }
  if(t->left != NULL) {
    if(condition2(t->left) == 0) return 0;
  }
  if(t->right != NULL) {
    if(condition2(t->right) == 0) return 0;
  }

  return 1;
}

int condition3(struct rb_node *t) {
  int countL = 0, countR = 0;
  if(t->left != NULL) {
    //printf("%d, %d ", t->left->black, t->left->data.id);
    countL += condition3(t->left) + t->left->black;
  }
  if(t->right != NULL) {
    //printf("%d ", t->right->black);
    countR += condition3(t->right) + t->right->black;
  }
  //printf("%d\n", countL);
  if(countL == -1 || countR == -1 || countL != countR) return -1;
  else return countL;
}


//赤黒木なら1を返す、そうじゃなければ0
int is_rbtree(struct rb_node *t) {
  //printf("2: %d, 3: %d\n", condition2(t), condition3(t));
  if(condition2(t) && condition3(t) != -1) return 1;
  else return 0;
}

int main() {
  struct rb_node *t = get_rbtree();
  if(is_rbtree(t)) printf("Yes.\n");
  else printf("No.\n");
  return 0;
}
