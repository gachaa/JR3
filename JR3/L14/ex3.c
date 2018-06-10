#include<stdio.h>
#include<stdlib.h>
char buf[256];

int main() {
  int ekisu, i, j, eki1, eki2, rosen;
  float kyori;
  scanf("%d ", &ekisu);
  int adjmat[ekisu][ekisu];

  for(i=0;i<ekisu;++i) {
    for(j=0; j<ekisu; ++j) {
      adjmat[i][j] = 0;
    }
  }
  
  while(fgets(buf,sizeof(buf),stdin)!=NULL) {
    sscanf(buf, "%d:%d:%d:%f ", &eki1, &eki2, &rosen, &kyori);
    adjmat[eki1][eki2] = 1;
    adjmat[eki2][eki1] = 1;
  }
  for(i=0; i<ekisu; ++i){
    for(j=0; j<ekisu; ++j){
      printf("%d", adjmat[i][j]);
    }
    printf("\n");
  }

  return 0;
}
