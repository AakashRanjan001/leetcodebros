class Solution {
public:
bool pallindrome(string temp){
    int start =0;
    int end = temp.size()-1;
    while(start<end){
        if(temp[start]!=temp[end]){
            return false;
        }
        start++;
        end--;
        

    }
    return true;
}




    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string temp = words[i];
            if(pallindrome(temp)){
                return temp;
            }
        }
        return "";
    }
};