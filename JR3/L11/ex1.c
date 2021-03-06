#include<stdio.h>
#include<stdlib.h>

char buf[128];

typedef int datatype;
struct node { datatype data; struct node *left, *right; };

struct node* get_tree() {
  struct node *t;
  //先頭が.ならNULLを返す
  if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
    return NULL;
  else {
    //先頭が.以外ならメモリ確保して、数値をdataに保存
    t = (struct node*)malloc(sizeof(struct node));
    sscanf(buf,"%d␣",&t->data);
    t->left = get_tree();
    t->right = get_tree();
    return t;
  }  
}

//nodeのアドレスtの指す節点を根とする二分木を出力
void print_tree(struct node *t) {
  if(t != NULL){
    printf("%d", t->data);
    printf("(");
    if(t->left == NULL)printf("-");
    else print_tree(t->left);
    printf(",");
    if(t->right == NULL)printf("-");
    else print_tree(t->right);
    printf(")");
  }
  else printf("-");
}

int main() {
  struct node *t = get_tree();
  print_tree(t);
  printf("\n");
  return 0;
}
