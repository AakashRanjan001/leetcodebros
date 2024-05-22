class Solution {
public:

    bool isPalindrome(string str, int s, int e)
    {
        while(s <= e)
        {
            if(str[s] != str[e])
                return false;
            s++;
            e--;
        }
        return true;
    }

    void backtrack(string &s, int idx, vector<string> &temp, vector<vector<string>> &result)
    {
        if(idx == s.length())
        {
            result.push_back(temp);
            return;
        }

        for(int i = idx; i < s.length(); i++)
        {
            if(isPalindrome(s, idx, i))
            {
                temp.push_back(s.substr(idx, i - idx + 1));
                backtrack(s, i+1, temp, result);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        backtrack(s, 0, temp, ans);
        return ans;
    }
};
