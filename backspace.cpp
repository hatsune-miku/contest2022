// zguan@mun.ca

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::vector;
using std::string;

#define max(x,y) (((x)>(y))?(x):(y))


int main() {
    char c;
    char s[1000001];
    int n = 0;
    while (
        (c = getchar()) == '<' || ('a' <= c && c <= 'z')
    ) {
        if (c != '<') {
            s[n++] = c;
        }
        else {
            --n;
            if (n < 0) {
                n = 0;
            }
        }
    }
    s[n] = 0;
    printf("%s\n", s);
    return 0;
}
