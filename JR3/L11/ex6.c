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

//番号,名前,得点　で出力する
void print_bst(struct node *t) {
   if(t != NULL){
     printf("%d,%s,%d\n", t->data.id, t->data.name, t->data.score);
     print_bst(t->left);
     print_bst(t->right);
   }
   else printf(".\n");
}
//学籍番号がidと一致する節点を削除し、得られた木の根の節点のアドレスを返す
struct node* bst_delete(struct node *t, int id) {
  struct node *pre = t, *cur, *now;
  //curが左なら0, 右なら1
  int lr = 0;
  
  if(t->data.id == id) {
    cur = t;
    if(cur->right == NULL) {
      t = t->left;
    }else if(t->right->left == NULL) {
      t = t->right;
      t->left = cur->left;
    }else{
      t = t->right;
      while(t->left->left != NULL) {
	t = t->left;
      }
      now = t;
      t = t->left;
      now->left = t->right;
      t->left = cur->left; t->right = cur->right;
      //      printf("[%d]\n",t->data.id);
    }
  //↓根が探すidじゃない
  }else if(t->left->data.id == id || t->right->data.id == id) {
    if(t->left->data.id == id) cur = t->left; //preのleftが探すid
    else { //preのrightが探すid
      cur = t->right;
      lr = 1;
    }

    if(cur->right == NULL) {
      //右の子が葉
      if(lr == 0) pre->left = cur->left;
      else pre->right = cur->left;
    } else if(cur->right->left == NULL) {
      //条件2つめ
      if(lr == 0) {
	pre->left = cur->right;
	pre->left->left = cur->left;	
      } else {
	pre->right = cur->right;
	pre->right->left = cur->left;
      }
    } else {
      //条件3つめ
      now = t;
      if(lr == 0) now = now->left->right;
      else now = now->right->right;
      
      while(now->left->left != NULL) {
	now = now->left;
      }
      if(lr == 0) {
	pre->left = now->left;
	pre->left->left = cur->left; pre->left->right = cur->right;
      } else {
	pre->right = now->left;
        pre->right->left = cur->left; pre->left->right = cur->right;
      }
      now->left = now->left->right;
    }
  //if(t->data.id == id) {
  } else if(t->left != NULL && id > t->left->data.id || id > t->right->data.id) {
    t->right = bst_delete(t->right, id);
  } else if(t->right != NULL && id < t->left->data.id ||id < t->right->data.id) {
    t->left = bst_delete(t->left, id);
  }
  free(cur);
  return t;
}

int main() {
  struct node *t = get_tree();
  int id;
  scanf("%d ", &id);
  t = bst_delete(t, id);
  print_bst(t);
  return 0;
}
