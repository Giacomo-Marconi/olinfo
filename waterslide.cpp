#include <stdio.h>
#include <assert.h>

#include <queue>
#include <vector>
#define MAXM 200000

using namespace std;

int find_pool(int N, int M, int P, int A[], int B[]) {
    vector<int> graph[N];
    queue<int> q;

    int c[N];
    double f[N];
    for (int i = 0; i < N; ++i) {
        f[i]=0;
        c[i]=0;
    }
    f[0]=100;

    for (int i = 0; i < M; ++i) {
        graph[A[i]].push_back(B[i]);
    }

    q.push(0);
    while (!q.empty()){
        int p=q.front();
        q.pop();
        f[graph[p][]]
        
    }

    for (int i = 0; i < N; ++i) {
        double d=f[i];
        for (int j = 0; j < c[i]; ++j) {
            f[graph[i][j]]+=d/c[i];
            f[i]-=d/c[i];
        }
    }
    int pmax=0;
    for (int i = 0; i < N; ++i) {
        if (f[pmax]<f[i]) pmax=i;
    }
    return pmax;
}


int A[MAXM];
int B[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, P, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &N, &M, &P));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d %d", &A[i], &B[i]));

    fprintf(fw, "%d\n", find_pool(N, M, P, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
