// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    int a[T], b[T];
    for (int test = 0; test < T; ++test) {
        cin >> a[test] >> b[test];
    }

    for (int i = 0; i < T; ++i) {
        int A=a[i], B=b[i];
        // INSERT YOUR CODE HERE
        if (A <= B || A < 33 || A > 53 || B>52) {
            printf("-1 -1\n");
            continue;
        }

        if (B < 11 && A == 33) {
            printf("11 %d\n", B);
            printf("11 0\n");
            printf("11 0\n");
            continue;
        }

        if (B >= 11 && B < 22 && A <= 43) {
            A -= 33;
            B -= 11;
            printf("%d 11\n", A);
            printf("11 %d\n", B);
            printf("11 0\n");
            printf("11 0\n");
            continue;
        }

        if (B >= 22) {
            A -= 33;
            B -= 22;
            if (A > 10) {
                printf("%d 11\n", 10);
                A -= 10;
            } else {
                printf("%d 11\n", A);
                A = 0;
            }
            printf("%d 11\n", A);
            for (int j = 0; j < 3; ++j) {
                if (B >= 10) {
                    printf("11 %d\n", 10);
                    B -= 10;
                } else {
                    printf("11 %d\n", B);
                    B = 0;
                }
            }
            continue;
        }


        /*
        if (A<=43 && B<=41){
            A-=33;
            printf("%d 11", A);
            for (int j = 0; j < 3; ++j) {
                if (B<=10) {
                    printf("11 %d", B);
                    B=0;
                }else{
                    printf("11 10");
                    B-=10;
                }
            }
            continue;
        }
        */
        /*
        if (A<=53 && B<=52){
            A-=33;
        }*/


        printf("-1 -1\n");
    }

    return 0;
}

/*100% con b le copriamo tutte
 * b<11 --> a==33
 * 11<=b<22 --> a<=43
 * b>22  --> a no limit
 * b>=53 --> mai
 *
 * a<33 --> mai
 * a==33 --> b<11
 * a<=43 --> 11<=b<22          FOR DENTRO FOR DA 0 A 55 E EASY
 * a<=53 --> b>22
 * a>=54 --> mai
 * */

/*

 <33 -   --> MAI

 =33 <33 --> 11- / 11- / 11-
 =33 >33 --> NO
  A=33 <30 --> 11- / 11- / 11-
     11<B<22 -->



 33<A<52 >22 --> -11 / -11 / 11- / 11- / 11-
 >33 11<B<22 --> -11 / 11- / 11- / 11-

 <44 <22 --> -11/ 11- / 11- / 11-


5
33 15
40 29
55 55
39 16
29 54

*/