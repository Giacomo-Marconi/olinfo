#include <stdio.h>
#include <assert.h>
using namespace std;

long long int somma(FILE *f) {
    long long int S=0;
    int N, A;
    assert(1 == fscanf(f, "%d", &N));
    //printf("%d", N);
    for(int i=0; i<N; i++){
        assert(1 == fscanf(f, "%d", &A));
        //printf("%d", A);
        S+=A;
    }

    fclose(f);

    return S;
}

int main() {
    printf("%lld\n", somma(stdin));
    return 0;
}

/*
5
5 2 3 6 1
 */