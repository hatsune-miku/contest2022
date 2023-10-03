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

char op[] = {'*','+','-','/'};
bool high[] = {true,false,false,true};

inline int calc(int x, int op_index, int y) {
    char o = op[op_index];
    if (o == '*') return x*y;
    if (o == '+') return x+y;
    if (o == '-') return x-y;
    if (o == '/') return x/y;
    return x+y;
}

void solve(int n) {
    if (n > 4*4*4*4) {
        printf("no solution\n");
        return; 
    }
    times(i,4) {
        times(j,4) {
            times(k,4) {
                int res=0;
                if (op[j] == '+') {
                    res = calc(calc(4,i,4),j,calc(4,k,4));
                }
                else if (op[j] == '-') {
                    if (high[i] && high[k]) // (4i4)j(4k4)
                        res = calc(calc(4,i,4),j,calc(4,k,4));
                    else if (high[i]) // (4i4)j4k4
                        res = calc(calc(calc(4,i,4),j,4),k,4);
                    else if (high[k]) // 4i4j(4k4)
                        res = calc(4,i,calc(4,j,calc(4,k,4)));
                    else // 4i4j4k4
                        res = calc(calc(calc(4,i,4),j,4),k,4);
                }
                else {
                    if (high[i] && high[k]) // 4i4j4k4
                        res = calc(calc(calc(4,i,4),j,4),k,4);
                    else if (high[i]) // 4i4j4k4
                        res = calc(calc(calc(4,i,4),j,4),k,4);
                    else if (high[k]) // 4i(4j4k4)
                        res = calc(4,i,calc(calc(4,j,4),k,4));
                    else // 4i(4j4)k4
                        res = calc(calc(4,i,calc(4,j,4)),k,4);
                }

                if (res == n) {
                    printf("4 %c 4 %c 4 %c 4 = %d\n", 
                        op[i], op[j], op[k], n);
                    return;
                }
            }
        }
    }
    printf("no solution\n");
}

int main() {
    int t,n;
    read(t);
    while (t--) {
        read(n);
        solve(n);
    }
    return 0;
}
