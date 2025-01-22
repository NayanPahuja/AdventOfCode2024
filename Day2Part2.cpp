#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isOk(vector<int>& a) {
    bool valid = true;
    bool inc = true, dec = true;

    for (int k = 0; k < a.size() - 1; k++) {
        int diff = a[k + 1] - a[k];
        if (diff > 0) dec = false;
        if (diff < 0) inc = false;
        if (!(1 <= abs(diff) && abs(diff) <= 3)) {
            valid = false;
            break;
        }
    }
    return (valid && (inc || dec));
}

int main() {
    int T = 1000;
    int ans = 0;

    while (T--) {
        vector<int> temp;

        while (true) {
            int a;
            scanf("%d", &a);
            temp.push_back(a);

            char c;
            scanf("%c", &c);
            if (c == '\n') break;
        }

        bool anyOk = false;

        auto consider = [&](int i) {
            vector<int> b = temp;
            b.erase(b.begin() + i);
            if (isOk(b)) {
                anyOk = true;
            }
        };

        size_t sz = temp.size();
        consider(0);

        for (int i = 0; i < sz - 1; i++) {
            int diff = temp[i + 1] - temp[i];
            if (abs(diff) < 1 || abs(diff) > 3) {
                consider(i);
                consider(i + 1);
                break;
            }

            if (i + 2 < sz) {
                int diff2 = temp[i + 2] - temp[i + 1];
                if ((diff > 0) != (diff2 > 0)) {
                    consider(i);
                    consider(i + 1);
                    consider(i + 2);
                    break;
                }
            }
        }

        if (anyOk) ans++;
    }

    printf("%d\n", ans);
    return 0;
}

