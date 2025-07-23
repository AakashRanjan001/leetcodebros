class Solution {
public:
    string RemoveSubstr(string &s, string &matchStr){
          
    //       stack<char>st;
    //       for(char &ch :s){
    //        if (!st.empty() && st.top() == matchStr[0] && ch == matchStr[1]){
    //          st.pop();
    //        }

    //          else{
    //              st.push(ch);
    //          }
    //       }
    //     string res ="";
    //     while(!st.empty()){
    //          res.push_back(st.top());
    //          st.pop();
    //     }
    //     reverse(res.begin(),res.end());
    //     return res;
    // }
    // int maximumGain(string s, int x, int y) {
         
    //      int n = s.size();
    //      string maxstr = x>y ? "ab" : "ba";
    //      string minstr = x<y ? "ab" : "ba";
    //      int score = 0;

    //    //first pass mei saare "ab" ko nikal do if x>y  
    //      string temp_first = RemoveSubstr(s,maxstr);
    //      int L = temp_first.size();
    //      int charremoved = n - L;
    //      score+=(charremoved/2) * max(x,y);


    //      //second pass
    //      string temp_sec = RemoveSubstr(temp_first , minstr);
    //      charremoved = L - temp_sec.size();
    //      score+= (charremoved/2) * min(x,y);

    //      return score;

 class Solution {
public:
    string RemoveSubstr(string s, string &matchStr, int &pairsRemoved) {
        stack<char> st;
        pairsRemoved = 0;
        for (char &ch : s) {
            if (!st.empty() && st.top() == matchStr[0] && ch == matchStr[1]) {
                st.pop();
                pairsRemoved++;
            } else {
                st.push(ch);
            }
        }
        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int maximumGain(string s, int x, int y) {
        string str1 = "ab", str2 = "ba";

        // Try removing "ab" first, then "ba"
        int score1 = 0, abCount = 0, baCount = 0;
        string rem1 = RemoveSubstr(s, str1, abCount);
        RemoveSubstr(rem1, str2, baCount);
        score1 = abCount * x + baCount * y;

        // Try removing "ba" first, then "ab"
        int score2 = 0, baCount2 = 0, abCount2 = 0;
        string rem2 = RemoveSubstr(s, str2, baCount2);
        RemoveSubstr(rem2, str1, abCount2);
        score2 = baCount2 * y + abCount2 * x;

        return max(score1, score2);
    }
};

