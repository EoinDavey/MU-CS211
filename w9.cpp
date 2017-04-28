#include<cstdio>

int N;
int adjMat[111][111];

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d",&adjMat[i][j]),adjMat[i][j] = (i!=j && adjMat[i][j]==0) ? 100000 : adjMat[i][j];
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                adjMat[i][j] = (adjMat[i][j] < adjMat[i][k] + adjMat[k][j]) ? adjMat[i][j] : adjMat[i][k] + adjMat[k][j];
    int mx = 0;
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                mx = (adjMat[i][j] > mx) ? adjMat[i][j] : mx;
    printf("%d\n",mx);
    return 0;
}
