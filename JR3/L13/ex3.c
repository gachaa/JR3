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
   t->left = get_rbtree(); t->right = get_rbtree();
   return t;
 }
}

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

int main() {
  struct rb_node *t = get_rbtree();
  t = resolve_red_pair(t);
  print_rbtree(t);
  return 0;
}
