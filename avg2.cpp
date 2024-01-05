#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> P;

int FirstNotUno(int index, int diff){
    for(int i=index; i<P.size(); i++) {
        if (P[i] - diff > 1) return i;
    }
    return 0;
}

int main() {


    int N;
    long long K;
    cin >> N >> K;

    long long int diff=0;

    int v;
    for (int i = 0; i < N; ++i) {
        cin >> v;
        P.push_back(v);
        diff+=P[i]-K;
    }

    //printf("diff --> %lld\n", diff);

    if(diff<0){
        int c=0;
        while(diff<0){
            diff+=N;
            c++;
        }
        cout << c << endl;
        return 0;
    }

    sort(P.begin(), P.end());

    int c=0;
    int index=0;

    while(diff>0){
        index=FirstNotUno(index, c);
        //printf(" index --> %d  ", index);
        diff-=(N-index);
        //printf("diff --> %lld\n", diff);
        c++;
    }

    cout << c << endl;


    return 0;
}

/*
2 5
13 3

7 4
3 6 5 6 6 3 9

*/