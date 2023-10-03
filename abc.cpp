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
    int a[3];
    char order[4];
    read(a[0]);
    read(a[1]);
    read(a[2]);
    readline(order);

    sort(a,a+3);
    printf("%d ", a[order[0]-'A']);
    printf("%d ", a[order[1]-'A']);
    printf("%d\n", a[order[2]-'A']);

    return 0;
}
