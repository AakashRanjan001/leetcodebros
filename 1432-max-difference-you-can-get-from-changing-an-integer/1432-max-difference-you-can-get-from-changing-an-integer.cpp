// class Solution {
// public:
//     int maxDiff(int num) {
//          string s = to_string(num);
//          string str1 = s; // a
          
//          char c;
//          for(int i=0;i<s.size();i++){ 
//               if(str1[i]!='9'){
//                   c= str1[i];
//                   break;
//               }
            
//          }
//         for(int i=0;i<s.size();i++){
//              if(str1[i] == c){
//                  str1[i] = '9';
//              }
//         }

//         string str2 = s; // b
      
//        for(int i=0;i<str2.size();i++){
//            char ch = str2[i];


//            if(i == 0){
//                if(ch != '1'){
//                    str2[i] = '1';
//                    break;
//                }
//            }
//            else if(ch != '0' && ch!=str2[0]){
//                 str2[i] = '0';
//                 break;
//            }
//        }
        
//      return stoi(str1) - stoi(str2);

//     }
// };


class Solution {
public:
    int maxDiff(int num) {
        string t = to_string(num);

        // Create max number by replacing first non-'9' digit with '9'
        string maxNum = t;
        char toReplaceMax = ' ';
        for (char ch : maxNum) {
            if (ch != '9') {
                toReplaceMax = ch;
                break;
            }
        }
        if (toReplaceMax != ' ') {
            for (char &ch : maxNum) {
                if (ch == toReplaceMax) ch = '9';
            }
        }

        // Create min number by replacing first digit with '1' (if not already '1')
        string minNum = t;
        char toReplaceMin = ' ';
        if (minNum[0] != '1') {
            toReplaceMin = minNum[0];
            for (char &ch : minNum) {
                if (ch == toReplaceMin) ch = '1';
            }
        } else {
            for (int i = 1; i < minNum.size(); ++i) {
                if (minNum[i] != '0' && minNum[i] != '1') {
                    toReplaceMin = minNum[i];
                    break;
                }
            }
            if (toReplaceMin != ' ') {
                for (char &ch : minNum) {
                    if (ch == toReplaceMin) ch = '0';
                }
            }
        }

        return stoi(maxNum) - stoi(minNum);
    }
};
