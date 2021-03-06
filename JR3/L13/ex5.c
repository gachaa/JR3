#include<stdio.h>
#include<stdlib.h>
char buf[128];
struct student { int id; char name[32]; int score; };
typedef struct student datatype; 
struct rb_node { datatype data; struct rb_node *left, *right; int black; };

void print_rbtree(struct rb_node *t) {
  if(t==NULL) printf(".\n");
  else {
    printf("[%c]%d,%s,%d\n",t->black?'b':'r',t->data.id,t->data.name,t->data.score);
    print_rbtree(t->left); print_rbtree(t->right);
  }
}

struct rb_node* rotate_right(struct rb_node *t) {
  struct rb_node *preRoot = t;

  if(t->left == NULL) return t;

  t = t->left;
  preRoot->left = t->right;
  t->right = preRoot;

  return t;
}

struct rb_node* rotate_left(struct rb_node *t) {
  struct rb_node *preRoot = t;

  if(t->right == NULL) return t;

  t = t->right;
  preRoot->right = t->left;
  t->left = preRoot;

  return t;
}

struct rb_node* resolve_red_pair(struct rb_node *t) {
  if((t->left != NULL && t->left->black == 0) && (t->left->left != NULL && t->left->left->black == 0)){
    if(t->right != NULL && t->right->black == 0) {
      t->left->black = 1; t->right->black = 1; t->black = 0;
    } else {
      t = rotate_right(t);
      t->black = 1; t->right->black = 0;
    }
  }else if((t->left != NULL && t->left->black == 0) && (t->left->right != NULL && t->left->right->black == 0)){
    if(t->right != NULL && t->right->black == 0){
      t->left->black = 1; t->right->black = 1; t->black = 0;
    }else{
      t->left = rotate_left(t->left);
      t = rotate_right(t);
      t->black = 1; t->right->black = 0;
    }
  }else if((t->right != NULL && t->right->black == 0) && (t->right->left != NULL && t->right->left->black == 0)) {
     if(t->left != NULL && t->left->black == 0){
       t->left->black = 1; t->right->black = 1; t->black = 0;
    }else{
      t->right = rotate_right(t->right);
      t = rotate_left(t);
      t->black = 1; t->left->black = 0;
    }
  }else if((t->right != NULL && t->right->black == 0) && (t->right->right != NULL && t->right->right->black == 0)) {
    if(t->left != NULL && t->left->black == 0) {
      t->left->black = 1; t->right->black = 1; t->black = 0;
    } else {
      t = rotate_left(t);
      t->black = 1; t->left->black = 0;
    }
  }
  return t;
}

//dと同じ学籍番号がなければ挿入し、
//すでに存在すればその節点のデータにdの得点を加える
struct rb_node* rb_update(struct rb_node* t, struct student d) {
  if(t == NULL){
    t = (struct rb_node*)malloc(sizeof(struct rb_node));
    t->data = d;
    return t;
  }else if(t->data.id == d.id) {
    t->data.score += d.score;
  }else{
    if(t->data.id > d.id) t->left = rb_update(t->left, d);
    else t->right = rb_update(t->right, d);
    return t = resolve_red_pair(t);
  }
}

struct rb_node* rb_insert(struct rb_node *t, struct student d) {
  t = rb_update(t, d);
  t->black = 1;
  return t;
}

int main() {
  struct student d;
  struct rb_node *t = NULL;
  while(fgets(buf,sizeof(buf),stdin)!=NULL) {
    sscanf(buf,"%d,%[^,],%d",&d.id,d.name,&d.score);
    t = rb_insert(t, d);
  }
  print_rbtree(t);
  return 0;
}
