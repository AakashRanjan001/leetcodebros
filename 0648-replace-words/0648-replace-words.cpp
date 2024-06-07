class Solution {
public:
    
    int check(vector<string>& dictionary, int i, string sentence)
    {
        for(int j = 0; j < dictionary.size(); j++)
        {
            int k = 0;
            int start = i;
            while(k < dictionary[j].length() && start < sentence.length() && sentence[start] == dictionary[j][k]) {
                start++; 
                k++;
            }
            if(k == dictionary[j].length()) return j;
        }
        return -1;
    }
    
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        string res = "";
        int n = sentence.length();
        int i = 0;
        sort(dictionary.begin(), dictionary.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });
        while(i < n)
        {
            while(i < n && sentence[i] == ' ') i++;
            if(i >= n) break;

            int temp = check(dictionary, i, sentence);
            if(temp != -1)
            {
                res += dictionary[temp] + " ";
                while(i < n && sentence[i] != ' ') i++; 
            } 
            else
            {
                int start = i;
                while(i < n && sentence[i] != ' ')
                {
                    res += sentence[i];
                    i++;
                }
                res += " ";
            }
        }

        if(!res.empty() && res.back() == ' ') res.pop_back();

        return res;
    }
};
