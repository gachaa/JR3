#include<stdio.h>
#include<stdlib.h>
char buf[128]; 

struct student { int id; char name[32]; int score; };
typedef struct student datatype; 
struct node { datatype data; struct node *left, *right; };

//行きがけ順で表現された文字列を二分木に変換
struct node* get_tree() {
  struct node *t;
  if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
    return NULL;
  else {
    t = (struct node*)malloc(sizeof(struct node));
    sscanf(buf,"%d,%[^,],%d",&t->data.id,t->data.name,&t->data.score);
    t->left = get_tree();
    t->right = get_tree();
    return t;
  }
}

//data = d の節点を追加して得られた二部探索木の根のアドレスを返す
struct node* bst_insert(struct node *t, struct student d) {
  if(t == NULL) {
    t = (struct node*)malloc(sizeof(struct node));
    t->data = d;
  }
  else if(d.id > t->data.id) t->right = bst_insert(t->right, d);
  else if(d.id < t->data.id) t->left = bst_insert(t->left, d);
  
  return t;
}

//番号,名前,得点　で出力する
void print_bst(struct node *t) {
   if(t != NULL){
     printf("%d,%s,%d\n", t->data.id, t->data.name, t->data.score);
     print_bst(t->left);
     print_bst(t->right);
   }
   else printf(".\n");
}

int main() {
  struct node *t = get_tree();
  struct student d;
  scanf("%d,%[^,],%d␣", &d.id, d.name, &d.score);
  t = bst_insert(t, d);
  print_bst(t);
  return 0;
}
