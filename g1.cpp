// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, Q;
    cin >> N >> Q;

    int count[N];
    vector<int> C(N);
    int risaliaposizinenellarrayprincipaledeellauato[N];

    for (int i = 0; i < N; i++) {
        cin >> C[i];              //5 2 3 4 1 7 6
        count[i]=0;
        risaliaposizinenellarrayprincipaledeellauato[C[i]-1]=i;          //4 1 2 3 0 6 5
    }


    int x, t, max=0, pos;

    for (int i = 0; i < Q; i++) {
        cin >> x;

        /*
        printf("C:");
        for(int j=0; j<N; j++){
            printf(" %d", C[j]);
        }
        cout << endl;

        printf("ris:");
        for(int j=0; j<N; j++){
            printf(" %d", risaliaposizinenellarrayprincipaledeellauato[j]);
        }
        cout << endl;

        printf("count:");
        for(int j=0; j<N; j++){
            printf(" %d", count[j]);
        }
        cout << endl;
        */

        pos=risaliaposizinenellarrayprincipaledeellauato[x-1];


        //printf("pos --> %d\n", pos);

        t=C[pos];
        C[pos]=C[pos-1];
        C[pos-1]=t;

        /*
        printf("C scambiato:");
        for(int j=0; j<N; j++){
            printf(" %d", C[j]);
        }
        cout << endl;
        */

        risaliaposizinenellarrayprincipaledeellauato[C[risaliaposizinenellarrayprincipaledeellauato[x-1]]-1]++;

        risaliaposizinenellarrayprincipaledeellauato[x-1]--;

        //printf("pos-->%d, max-->%d ", pos, max);

        count[C[pos]]++;

        //printf("count-->%d\n", count[pos]);
        //printf("count[max]-->%d, count[pos]-->%d\n", count[max], count[pos]);

        /*
        printf("-----------------------\n");

        printf("C:");
        for(int j=0; j<N; j++){
            printf(" %d", C[j]);
        }
        cout << endl;

        printf("ris:");
        for(int j=0; j<N; j++){
            printf(" %d", risaliaposizinenellarrayprincipaledeellauato[j]);
        }
        cout << endl;


        printf("count:");
        for(int j=0; j<N; j++){
            printf(" %d", count[j]);
        }
        cout << endl;
        */

        max=0;
        for(int k=1; k<N; k++){
            if(count[max]<count[k]) max=k;
        }

        cout << max << endl;
    }
    return 0;
}


/*


7 8
5 2 3 4 1 7 6
1
1
1
4
3
7
4
6


*/