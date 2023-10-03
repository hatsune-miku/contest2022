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

//Scissor Paper Rock
// 1:r>f   0:draw  -1:r<f
int won(char r, int f) {
    if (r == f) {
        return 0;
    }
    
    if (r == 'S') {
        if (f == 'P') return 1;
        if (f == 'R') return -1;
    }
    else if (r == 'P') {
        if (f == 'R') return 1;
        if (f == 'S') return -1;
    }
    else if (r == 'R') {
        if (f == 'S') return 1;
        if (f == 'P') return -1;
    }
    return 0;
}

int score_for(int me, int against) {
    int res = won(me, against);
    if (res == 1) {
        return 2;
    }
    else if (res == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int r, n;
    string rs, fs[51];
    cin >> r;
    cin.get();
    cin >> rs;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> fs[i];
    }

    int ans = 0;
    int ans2 = 0;
    for (int i = 0; i < r; ++i) {
        // Round r
        char curr = rs[i];
        for (int j = 0; j < n; ++j) {
            ans += score_for(curr, fs[j][i]);
        }
        
        // max possible.
        int cnt[127] = {0};
        for (int j = 0; j < n; ++j) {
            ++cnt[fs[j][i]];
        }

        // me = 'S'
        int tmp0 = 0;
        tmp0 += cnt['S'] * score_for('S', 'S');
        tmp0 += cnt['R'] * score_for('S', 'R');
        tmp0 += cnt['P'] * score_for('S', 'P');

        int tmp1 = 0;
        tmp1 += cnt['S'] * score_for('R', 'S');
        tmp1 += cnt['R'] * score_for('R', 'R');
        tmp1 += cnt['P'] * score_for('R', 'P');

        int tmp2 = 0;
        tmp2 += cnt['S'] * score_for('P', 'S');
        tmp2 += cnt['R'] * score_for('P', 'R');
        tmp2 += cnt['P'] * score_for('P', 'P');

        ans2 += max(tmp0, max(tmp1, tmp2));
    }
    cout << ans << endl;
    cout << ans2 << endl;


    return 0;
}
