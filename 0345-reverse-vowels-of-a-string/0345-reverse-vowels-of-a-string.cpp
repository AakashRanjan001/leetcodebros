class Solution {
public:
    string reverseVowels(string s) {
        int i=0, j=s.length();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while(i<j){
            while(i<j && vowels.find(s[i]) == vowels.end())
                i++;
            while(i<j && vowels.find(s[j]) == vowels.end())
                j--;

            char t = s[i];
            s[i] = s[j];
            s[j] = t;

            i++;
            j--; 
        }

        return s;
    }
};
