#include <string>
#include <stack>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> v;

        int n = s.size();
        stack<pair<char, int>> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == ')' || s[i] == '(') {
                if (st.size() == 0 && (s[i] == ')' || s[i] == '(')) {
                    cout << s[i] << endl;
                    st.push({s[i], i});
                } else {
                    char x = s[i];
                    char y = st.top().first;
                    cout << y << " " << x << endl;
                    if (x == ')' && y == '(') {
                        st.pop();
                    } else {
                        st.push({s[i], i});
                    }
                }
            }
        }

        set<int> sk;

        while (st.size() != 0) {
            cout << st.top().second << endl;
            sk.insert(st.top().second);
            st.pop();
        }

        for (auto i : sk) {
            cout << i << endl;
        }

        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (sk.find(i) == sk.end()) {
                cout << s[i] << "ncn" << endl;
                ans += s[i];
            }
        }

        return ans;
    }
};
