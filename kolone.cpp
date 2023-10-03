//
// Created by EGGTARTc on 2022/2/13.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#define read(i) cin>>(i);cin.get()
#define readline(s) cin.getline((s),sizeof(s)/sizeof(char))
#define readn(s,n) cin.getline((s),(n)*sizeof(char)+1)
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int main() {
    char r1[27], r2[27];
    int n1, n2, t;
    read(n1);
    read(n2);
    readn(r1,n1);
    readn(r2,n2);
    read(t);

    reverse(r1,r1+n1);
    t = min(t, n1+n2);
    for (int i = 0; i < t-n1; ++i) {
        putchar(r2[i]);
    }

    int serial_len = max(max(n1,n2), n1+n2-t);
    for (int i = 0; i < serial_len; ++i) {
        int i1 = i;
        int i2 = i-n1+t;
        if (i2 >= 0 && i2 < n2) {
            putchar(r2[i2]);
        }
        if (i1 >= 0 && i1 < n1) {
            putchar(r1[i1]);
        }
    }
    putchar(10);

    return 0;
}
