
class Solution {
public:
    string countOfAtoms(string s) {
        stack<pair<string, int>> st;
        int n = s.length();
        int i = 0; 

        while (i < n) {
            if (isupper(s[i])) {
                int j = i + 1;
                string str;
                str.push_back(s[i]);
                while (j < n && islower(s[j])) {
                    str.push_back(s[j]);
                    j++;
                }
                st.push({str, 1});
                i = j;
            } else if (s[i] == '(') {
                st.push({"(", 0});
                i++;
            } else if (isdigit(s[i])) {  
                int j = i;
                int val = 0;
                while (j < n && isdigit(s[j])) {
                    val = val * 10 + (s[j] - '0');
                    j++;
                }
                auto it = st.top();
                st.pop();
                it.second *= val;
                st.push(it);
                i = j;
            } else if (s[i] == ')') {
                int j = i + 1;
                int val = 0;
                while (j < n && isdigit(s[j])) { 
                    val = val * 10 + (s[j] - '0');
                    j++;
                }
                if (val == 0) val = 1; 
                queue<pair<string, int>> q;
                while (!st.empty()) {
                    auto it = st.top();
                    st.pop();
                    if (it.first == "(" && it.second == 0) {
                        break;
                    }
                    it.second *= val;
                    q.push(it);
                }
                while (!q.empty()) {
                    st.push(q.front());
                    q.pop();
                }
                i = j;
            }
        }

        map<string, int> atomCount;
        while (!st.empty()) {
            auto it = st.top();
            st.pop();
            atomCount[it.first] += it.second;
        }

        string ans;
        for (const auto& it : atomCount) {
            ans += it.first;
            if (it.second > 1) {
                ans += to_string(it.second);
            }
        }
        return ans;
    }
};