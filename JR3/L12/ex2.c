#include<stdio.h>
#include<stdlib.h>
char buf[128]; 
struct student { int id; char name[32]; int score; };
typedef struct student datatype; 
struct avl_node { datatype data; struct avl_node *left, *right; int height; };

//与えられた文字列から二分木をつくる
struct avl_node* get_avl() {
  struct avl_node *t;
  if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
    return NULL;
  else {
    t = (struct avl_node*)malloc(sizeof(struct avl_node));
    sscanf(buf,"[%d]%d,%[^,],%d",&t->height,&t->data.id,t->data.name,&t->data.score);
    t->left = get_avl();
    t->right = get_avl();
    return t;
  }
}

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

//tの指す節点を根とする木について、左右の部分木がAVL木で高さの差が↓2
//全体としてAVLになるように変形し根を返す
struct avl_node* balance(struct avl_node *t) {
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
  struct avl_node *t = get_avl();
  t = balance(t);
  print_avl(t);
  return 0;
}
