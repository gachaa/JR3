#include<stdio.h>
#include<stdlib.h>
char buf[256];


//頂点数nのグラフを表すadjmatに対して、
//推移的閉包の隣接行列resultを作成する関数
void warshall(int n, int adjmat[n][n], int result[n][n]) {
  int reach[n+1][n][n];
  int k, i, j;
  
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      reach[0][i][j] = adjmat[i][j];
    }
  }

  for(k=1; k<=n; k++) {
    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
	reach[k][i][j]=reach[k-1][i][j] | reach[k-1][i][k-1] & reach[k-1][k-1][j];
      }
    }
  }

  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      result[i][j] = reach[n][i][j];
    }
  }
  
}


int main() {
  int ekisu, i, j, eki1, eki2, rosen;
  float kyori;
  scanf("%d ", &ekisu);
  int adjmat[ekisu][ekisu], result[ekisu][ekisu];

  for(i=0;i<ekisu;++i) {
    for(j=0; j<ekisu; ++j) {
      adjmat[i][j] = 0;
      if(i==j) adjmat[i][j] = 1;
    }
  }
  while(fgets(buf,sizeof(buf),stdin)!=NULL) {
    sscanf(buf, "%d:%d:%d:%f ", &eki1, &eki2, &rosen, &kyori);
    adjmat[eki1][eki2] = 1;
    adjmat[eki2][eki1] = 1;
  }

  warshall(ekisu, adjmat, result);

  for(i=0; i<ekisu; i++) {
    for(j=0; j<ekisu; j++) {
      printf("%d",result[i][j]);
    }
    printf("\n");
  }

  return 0;
}
