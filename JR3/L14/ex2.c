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

//ekiから2駅離れた駅のうち、もっとも遠い駅までの距離を出力する関数
//2駅先が存在しなければ1駅で一番遠いの
float two_hop_kyori(struct node *adjlist[], int eki) {
  struct node *a = adjlist[eki], *b;
  float count = 0, max = 0, countMax = 0;
  // printf("%d\n", eki);
  
  while(a != NULL) {
    count = a->kyori;
    if(countMax < count) countMax = count;
    int eki2 = a->eki;
    b = adjlist[eki2];
    while(b != NULL) {
      //printf("eki: %d ", eki2);
      if(b->eki != eki && max < count + b->kyori){
	max = count + b->kyori;
      }
      b = b->next;
      //printf("max: %.3f ", max);
    }
    //printf("count: %.3f\n", count);
    a = a->next;
  }
  if(max == 0) return countMax;
  else return max;
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
  for(i=0; i<ekisu; ++i)
    printf("%d: %.3f\n", i, two_hop_kyori(adjlist, i));
  return 0;
}
