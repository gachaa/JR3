#include<stdio.h>
#include<stdlib.h>
char buf[128]; 
struct student { int id; char name[32]; int score; };
typedef struct student datatype; 
struct avl_node { datatype data; struct avl_node *left, *right; int height; };

//高さを返す
int height(struct avl_node *t) {
  if(t == NULL) return 0;
  else return t->height;
}

//右の子と左の子から、tの高さを設定
void put_height(struct avl_node *t) {
  if(height(t->left) > height(t->right)) {
    t->height = height(t->left) + 1;
  } else {
    t->height = height(t->right) + 1;
  }
}

//tの指す節点を根とする二分探索木に対して
//右回転を行いその根の節点のアドレスを返す
struct avl_node* rotate_right(struct avl_node *t) {
  struct avl_node *preRoot = t;

  if(t->left == NULL) return t;

  t = t->left;
  preRoot->left = t->right;
  t->right = preRoot;

  put_height(preRoot);
  put_height(t);
  
  return t;
}

struct avl_node* rotate_left(struct avl_node *t) {
  struct avl_node *preRoot = t;

  if(t->right == NULL) return t;

  t = t->right;
  preRoot->right = t->left;
  t->left = preRoot;

  put_height(preRoot);
  put_height(t);

  return t;
}

//tのAVL木にdを挿入してAVLを満たすように調整。
struct avl_node* avl_insert(struct avl_node *t, struct student d) {
  //1. tがNULLかどうか
  if(t == NULL) {
    t = (struct avl_node*)malloc(sizeof(struct avl_node));
    t->left = NULL; t->right = NULL;
    t->data = d;
    return t;
  }else{
    if(t->data.id > d.id){
      t->left = avl_insert(t->left, d);
      put_height(t->left);
    } else {
      t->right = avl_insert(t->right, d);
      put_height(t->right);
    }
  }

  //2. tのheight
  put_height(t);

  //3. AVL木にする
  if(height(t->left) - height(t->right) == 2) {
    if(height(t->left->left) < height(t->left->right)) t->left = rotate_left(t->left);
    t = rotate_right(t);
  }else if(height(t->left) - height(t->right) == -2){
    if(height(t->right->left) > height(t->right->right)) t->right = rotate_right(t->right);
    t = rotate_left(t);
  }
  return t;
}

void print_avl(struct avl_node *t) {
  if(t==NULL)
    printf(".\n");
  else {
    
    printf("[%d]%d,%s,%d\n",t->height,t->data.id,t->data.name,t->data.score);
    print_avl(t->left);
    print_avl(t->right);
  }
}

int main() {
  struct student st;
  struct avl_node *t = NULL;
  while(fgets(buf, sizeof(buf), stdin) != NULL) {
    sscanf(buf,"%d,%[^,],%d",&st.id,st.name,&st.score);
    t = avl_insert(t, st);
  }
  print_avl(t);
  return 0;
}
