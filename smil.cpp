//
// Created by EGGTARTc😈 on 2022-02-13.
//

#define readline(s) cin.getline(s,sizeof(s)/sizeof(char))

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    char s[2049];
    readline(s);
    int ans = 0;

    for (char* p = s; *p && *(p+1); ++p) {
        if (*p == ':' || *p == ';') {
            if (*(p+1) == ')') {
                printf("%d\n", (int)(p-s));
                ++ans;
                ++p;
            }
            else if (*(p+1) == '-' && *(p+2) == ')') {
                printf("%d\n", (int)(p-s));
                ++ans;
                p+=2;
            }
        }
    }

    return 0;
}
