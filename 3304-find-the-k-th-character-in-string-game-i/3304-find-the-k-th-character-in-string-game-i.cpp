
class Solution {
public:
    char kthCharacter(int k) {
        char result = 'a';
        string word = "a";
        string text = "";
        int n =1;
        if(k == 1) return result;
        while(n<=k)
         {n = n*2;}
        while (word.length()<k) {
            text = "";
            for (int i = 0; i < word.length(); i++) {
                text += word[i]++;
            }
            word = text + word;
        }
        result = word[k-1];
        return result;
    }
};