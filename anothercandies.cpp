//
// Created by EGGTARTc on 2022/2/14.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#define read(i) cin>>(i);cin.get()
#define readline(s) cin.getline((s),sizeof(s)/sizeof(char))
#define readn(s,n) cin.getline((s),(n)*sizeof(char)+1)
#define times(_i,_n) for(int _i=0;_i<_n;++_i)
#define MODULO 1000000007
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int main() {
    ull t,n,m;
    read(t);

    while (t--) {
        ull ans = 0;
        read(n);
        times(i,n) {
            read(m);
            ans = (ans + (m % n)) % n;
        }
        if (ans) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }
    
    return 0;
}
