// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    //ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, K;
    cin >> N >> K;
    
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    
    int ans = 0;
    // INSERT YOUR CODE HERE

    long int count=0;
    vector<int> sopramedia;


    //10 5 --> -5
    //10 13 --> +3

    for (int i = 0; i < N; ++i) {
        count+=(P[i]-K);
        if (P[i]>K) {
            sopramedia.push_back(P[i]);
        }
    }
    //printf("count --> %d\n", count);

    if (count==0){
        //cout << "eq" << endl;
        printf("0");
        return 0;
    }

    if (count<0){
        //cout << "basso" << endl;
        printf("1");
        return 0;
    }

    //cout << "alto" << endl;

    sort(sopramedia.begin(), sopramedia.end());
    /*
    for (int i = 0; i < sopramedia.size(); ++i) {
        printf("%d - ", sopramedia[i]);
    }
    */
    //cout << endl;
    int c=sopramedia.size()-1;
    while(count>0 && c>=0){
        count-=(sopramedia[c]-1);
        //printf("%d --> %d, %d\n", ans, count, sopramedia[c]);
        ans++;
        c--;
    }

    cout << ans << endl;

    return 0;
}
/*
2 3
10 6

3 9
2 10 1

4 1
2 2 2 2

3 5
15 15 15

4 7
1 20 10 11

4 7
1 20 10 10



*/