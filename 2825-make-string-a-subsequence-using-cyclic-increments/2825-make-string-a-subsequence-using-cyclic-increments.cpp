class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // int i=0;
        // int j=0;

        // while(i<str1.size() && j<str2.size()){
           
        //     char nextChar = (str1[i] == 'z') ? 'a' : (str1[i] + 1);

        //     if((nextChar == str2[j]) || str1[i] == str2[j]){
        //         i++;
        //         j++;
        //     }
        //     else if( str1.size()>str2.size() && nextChar!= str2[j]){
        //         i++;
        //     }

        // }
        // if( i== str1.size() && j == str2.size()){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        



        int i = 0;
        int j = 0;

        while (i < str1.size() && j < str2.size()) {
        
            char nextChar = (str1[i] == 'z') ? 'a' : (str1[i] + 1);

            // Check if current character or its next character matches str2[j]
            if (str1[i] == str2[j] || nextChar == str2[j]) {
                i++;  // Move in both strings
                j++;
            } else {
                i++;  // Move only in str1 if no match
            }
        }
        
        // The subsequence is valid if we've traversed all of str2
        return j == str2.size();
    }
};

    }
};