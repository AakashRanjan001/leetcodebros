// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         // we will use BFS 
//         queue<pair<string,int>>q;
//         q.push({beginWord,1});
//         // wordList ko maine copy kar liya taaki same words ko erase karne mei easy ho 
//         unordered_set<string>st(wordList.begin(),wordList.end());

//         //jo bhi pair queue mei insert karunga usko set se delete karunga 
//         st.erase(beginWord);

//         while(!q.empty()){
//              pair<string,int>fnode = q.front();

//              string currString = fnode.first;
//              int currCount = fnode.second;

//              //abb hame check karna hai ki currSr=tring hamara destination tak toh pahuch gya
//              if(currString == endWord)return currCount;

//              //agar nhi mila yeh strring toh aage kareneg
//              for(int index =0;index<currString.size();index++){
//                   //harr ek index ko mere ko 'a' to 'z' mei change karna hai aur check karna hai wordList mei
//                   char originalCharacter = currString[index]; // YAHA MAI GALTI KARUNGA!!!
//                    for(char ch = 'a';ch<='z';ch++){
//                         currString[index] = ch;
//                          // check in wordList 
//                          if(st.find(currString)!=st.end()){
//                              //maan le mil gya set mei toh queue mei insert kar dunga 
//                              q.push({currString,currCount+1});
//                              //aur set se usko delete bhi karna hoga 
//                              st.erase(currString);
//                          }
//                    }
//                    //bringing back the current string to original state 
//                    currString[index] = originalCharacter;//YAHA MAI GALTI KARUNGA !!! 
//              }
//         }
//         return 0;

//     }
// };

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // We will use BFS 
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        // Convert wordList to unordered_set for quick lookups
        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord is not in the wordList, return 0 immediately
        if (st.find(endWord) == st.end()) return 0;

        // Remove beginWord from the set to avoid revisiting
        st.erase(beginWord);

        while (!q.empty()) {
            pair<string, int> fnode = q.front();
            q.pop();

            string currString = fnode.first;
            int currCount = fnode.second;

            // Check if the current string is the destination
            if (currString == endWord) return currCount;

            // Process all possible single-character transformations
            for (int index = 0; index < currString.size(); index++) {
                char originalCharacter = currString[index]; // Save the original character
                
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == originalCharacter) continue; // Skip the same character

                    // Change the current index to the new character
                    currString[index] = ch;

                    // Check if the transformed string is in the set
                    if (st.find(currString) != st.end()) {
                        q.push({currString, currCount + 1}); // Push the new word into the queue
                        st.erase(currString); // Remove from the set to mark as visited
                    }
                }

                // Restore the original character
                currString[index] = originalCharacter;
            }
        }
        
        return 0; // If BFS completes without finding the endWord
    }
};
