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

#define nrow 4
#define ncol 4
int m[nrow][ncol];

void move_zero(int* arr, int n, int dir) {
    if (dir == 0 || dir == 1) {
        // L / U, move zero right
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] == 0) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
    if (dir == 2 || dir == 3) {
        // R / D, move zero left
        for (int i = 0; i < n; ++i) {
            for (int j = n-i-1; j > 0; --j) {
                if (arr[j] == 0) {
                    swap(arr[j], arr[j-1]);
                }
            }
        }
    }
}

void process_numbers(int* arr, int n, int dir) {
    auto try_merge = [] (int& x, int& y) -> bool {
        if (x == y) {
            x += y;
            y = 0;
            return true;
        }
        return false;
    };

    if (dir == 0 || dir == 1) {
        // L / U
        move_zero(arr, n, dir);
        for (int i = 0; i < n-1; ++i) {
            if (try_merge(arr[i], arr[i+1])) continue;
        }
        move_zero(arr, n, dir);
    }
    else if (dir == 2 || dir == 3) {
        // R / D
        move_zero(arr, n, dir);
        for (int i = n-1; i > 0; --i) {
            if (try_merge(arr[i], arr[i-1])) continue;
        }
        move_zero(arr, n, dir);
    }
}

int main() {
    int d;
    for (int i = 0; i < nrow; ++i) {
        for (int j = 0; j < ncol; ++j) {
            read(m[i][j]);
        }
    }
    read(d);

    if (d == 0 || d == 2) {
        for (int i = 0; i < nrow; ++i) {
            process_numbers(m[i], ncol, d);
        }
    }
    else if (d == 1 || d == 3) {
        for (int i = 0; i < ncol; ++i) {
            int arr[nrow];
            for (int j = 0; j < nrow; ++j) {
                arr[j] = m[j][i];
            }
            process_numbers(arr, nrow, d);
            for (int j = 0; j < nrow; ++j) {
                m[j][i] = arr[j];
            }
        }
    }

    for (int i = 0; i < nrow; ++i) {
        for (int j = 0; j < ncol; ++j) {
            printf("%d ", m[i][j]);
        }
        putchar(10);
    }
    return 0;
}
