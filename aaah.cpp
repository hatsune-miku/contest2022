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
#define MODULO 1000000007
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int main() {
    char req[1001];
    int n = 0;
    readline(req);

    for (;;) {
        char c = getchar();
        if (c == 10 || c == 13) {
            break;
        }
        if (!req[n++]) {
            printf("no\n");
            return 0;
        }
    }

    printf("go\n");
    return 0;
}
