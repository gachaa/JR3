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

//tの二分木の全ての節点の数を返す
int size(struct node *t) {
  if(t == NULL) return 0;
  
  int count = 1;
  if(t->left != NULL) count += size(t->left);
  if(t->right != NULL) count += size(t->right);
  return count;
}

//tの二分木の高さを返す
int height(struct node *t) {
  int l = 0, r = 0;
  if(t == NULL) return 0;
  l = height(t->left);
  r = height(t->right);
  if(l > r) return l+1;
  else return r+1;
}

//tの二分木の全ての節点のデータの合計を返す
int sum(struct node *t) {
  if(t == NULL) return 0;
  int count = t->data;
  if(t->left != NULL) count += sum(t->left);
  if(t->right != NULL) count += sum(t->right);
  return count;
}

int main() {
  struct node *t = get_tree();
  printf("%d\n", size(t));
  printf("%d\n", height(t));
  printf("%d\n", sum(t));
  return 0;
}
