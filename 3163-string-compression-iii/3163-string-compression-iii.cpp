class Solution {
public:
    string compressedString(string word) {
        string comp ="";
        int n = word.length();
        for(int i =0;i<n;i++){
            int cnt = 1;
            while(i<n && word[i]==word[i+1]){
                  cnt++;
                  i++;

                     if(cnt == 9){break;
                     }
            }
           comp+=char(cnt + '0');  // to_string bhi use kar skate hai 
         comp.push_back(word[i]);
        }
       return comp;

    }
};