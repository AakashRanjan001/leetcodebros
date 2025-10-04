// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         int n = num.size();
//         stack<char>st;

//         for(int i=0;i<n;i++){
//              while(!st.empty() && k>0 && st.top()-'0' > num[i] - '0'){
//                  st.pop();
//                  k--;
//              }
//              st.push(num[i]);
//         }

//         //edge case 1 aftr traversing whole string , still k!=0
//         while(k>0 && !st.empty()){
//              st.pop();
//              k--;
//         }

//         //edge case 2 
//         if(st.empty())return "0";

//         string res = "";
//         while(!st.empty()){
//              res+=st.top();
//              st.pop();
//         }

//         //edge case 3 : leading zeroes 
//         while(res.size()!=0 && res.back() == '0'){
//              res.pop_back() ;// jab tak res ke peeche zeroes lage hue hai tab tak delete karte jao
//         }
//         reverse(res.begin(),res.end());
//         // agar saara hi string 0 hai tab toh sab delete karna hoga
//         if(st.empty())return "0";
//         return res;
        

//     }
// };

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;

        for(int i=0;i<n;i++){
             while(!st.empty() && k>0 && st.top()-'0' > num[i]-'0'){
                 st.pop();
                 k--;
             }
             st.push(num[i]);
        }

        // edge case 1: after traversing whole string, still k!=0
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        // edge case 2 
        if(st.empty()) return "0";

        string res = "";
        while(!st.empty()){
             res += st.top();
             st.pop();
        }

        reverse(res.begin(), res.end());

        // edge case 3: remove leading zeroes 
        int i = 0;
        while(i < res.size() && res[i] == '0'){
            i++;
        }
        res = res.substr(i);

        // agar saara hi string 0 hai tab toh sab delete karna hoga
        if(res.empty()) return "0";
        return res;
    }
};
