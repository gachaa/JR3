#include<stdio.h>
#include<stdlib.h>
char buf[256];

struct node { int eki, rosen; float kyori; struct node *next; };

//eki1からeki2へrosenとkyoriをもった辺を追加する関数
void add_edge(struct node *adjlist[], int eki1, int eki2, int rosen, float kyori) {
  struct node*  edge1 = (struct node*)malloc(sizeof(struct node));
  edge1->eki = eki2; edge1->rosen = rosen; edge1->kyori = kyori;
  struct node*  edge2 = (struct node*)malloc(sizeof(struct node));
  edge2->eki = eki1; edge2->rosen = rosen; edge2->kyori = kyori;
  if(adjlist[eki1] == NULL) edge1->next == NULL;
  else edge1->next = adjlist[eki1];
  if(adjlist[eki2] == NULL) edge2->next == NULL;
  else edge2->next = adjlist[eki2];
  
  adjlist[eki1] = edge1;
  adjlist[eki2] = edge2;
}

void print_adjlist(struct node *adjlist[], int n) {
  int i;
  struct node *p;
  for(i=0;i<n;++i) {
    printf("%d:", i);
    p = adjlist[i];
    while(p!=NULL) {
      printf(" (%d,%d,%.3f)", p->eki, p->rosen, p->kyori);
      p = p->next;
    }
    printf("\n");
  }
  return;
}

int main() {
  int eki1, eki2, rosen, ekisu, i;
  float kyori;
  scanf("%d ", &ekisu);
  struct node *adjlist[ekisu];
  for(i=0;i<ekisu;++i) adjlist[i] = NULL;
  while(fgets(buf,sizeof(buf),stdin)!=NULL) {
    sscanf(buf, "%d:%d:%d:%f ", &eki1, &eki2, &rosen, &kyori);
    add_edge(adjlist, eki1, eki2, rosen, kyori);
  }
  print_adjlist(adjlist, ekisu);
  return 0;
}
