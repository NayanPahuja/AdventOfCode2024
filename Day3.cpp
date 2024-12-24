#include <iostream>
#include <cctype>
using namespace std;

typedef long long ll;

int main() {
    string s;
    getline(cin, s, '\0');  // Read entire input until EOF
    int n = s.length();
    s += "################################";
    auto getNum = [&](int &i) {
        int ret = 0;
        while (ret < 1000 && i < n && isdigit(s[i])) {
            ret = 10 * ret + (s[i] - '0');
            i++;
        }
        if (ret >= 1000 || ret < 1) return -1;
        return ret;
    };
    bool canDo  = true;
    int ans = 0;
    for (int i = 0; i < n - 7; i++) { // Ensure at least 4 characters remain
        if(s.substr(i,4) == "do()") canDo = true;
        if(s.substr(i,7) == "don\'t()") canDo = false;
        if (s[i] == 'm' && s[i+1] == 'u' && s[i+2] == 'l' && s[i+3] == '(') {
            i += 4;
            int x = getNum(i);
            if (i < n && s[i] == ',' && (i += 1)) {  // Ensure within bounds
                int y = getNum(i);
                if (i < n && s[i] == ')') {  // Ensure within bounds
                    if (x != -1 && y != -1 && canDo) {
                        ans += x * y;
                    }
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
