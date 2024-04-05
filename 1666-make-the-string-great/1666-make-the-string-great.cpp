class Solution {
public:
    string makeGood(string s) {
        
        string temp = "";

        for(int i = 0; i < s.length(); i++)
        {
            if(temp == "")
            {
                temp.push_back(s[i]);
            }

            else if(abs(temp.back() - s[i]) == 32)
            {
                temp.pop_back();
            }

            else
            {
                temp.push_back(s[i]);
            }
        }

        return temp;
    }
};
