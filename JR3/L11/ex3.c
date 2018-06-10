#include<stdio.h>
#include<stdlib.h>

char buf[128];

typedef char datatype;
struct node { datatype data; struct node *left, *right; };

struct node* get_tree() {
  struct node *t;
  //先頭が.ならNULLを返す
  if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
    return NULL;
  else {
    //先頭が.以外ならメモリ確保して、数値をdataに保存
    t = (struct node*)malloc(sizeof(struct node));
    sscanf(buf,"%c␣",&t->data);
    t->left = get_tree();
    t->right = get_tree();
    return t;
  }  
}

//データを行きがけ順に出力
void print_preorder(struct node *t) {
  printf("%c", t->data);
  if(t->left != NULL) print_preorder(t->left);
  if(t->right != NULL) print_preorder(t->right);
}

//データを通りがけ順に出力
void print_inorder(struct node *t) {
  if(t->left != NULL) print_inorder(t->left);
  printf("%c", t->data);
  if(t->right != NULL) print_inorder(t->right);
}

//データを帰りがけ順に出力
void print_postorder(struct node *t) {
  if(t->left != NULL) print_postorder(t->left);
  if(t->right != NULL) print_postorder(t->right);
  printf("%c", t->data);
}

/*
//nodeのアドレスtの指す節点を根とする二分木を出力
void print_tree(struct node *t) {
  printf("%d", t->data);
  printf("(");
  if(t->left == NULL)printf("-");
  else print_tree(t->left);
  printf(",");
  if(t->right == NULL)printf("-");
  else print_tree(t->right);
  printf(")");
}
*/

int main() {
  struct node *t = get_tree();
  print_preorder(t); printf("\n");
  print_inorder(t); printf("\n");
  print_postorder(t); printf("\n");
  
  return 0;
}
