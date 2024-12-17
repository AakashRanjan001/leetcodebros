// class Solution {
// public:
//     string repeatLimitedString(string s, int repeatLimit) {
//         vector<char>freq(26,0);
//         for(int i=0;i<s.size();i++){
//              freq[s[i] - 'a']++;
//         }

//         priority_queue<pair<char,int>>maxheap;
//          // ASCII values ke hisaab se maxheap mei push hoga for printing in lexicographically order
//         for(int i=0;i<26;i++){
//              if(freq[i]>0){
//                   maxheap.push({i+'a' , freq[i]});
//              }
//         }
//            string ans =""; 
//         while(!maxheap.empty()){
//              auto& [ch1 ,frequency] = maxheap.top();
//              maxheap.pop();

//             int use = min(frequency , repeatLimit);
//             ans.append(use,ch1); // append karna uss char ko
//             frequency-= use;

//            if(frequency==0)maxheap.pop();

//            else{ // frequency abhi bhi hai top ch1 ki 
//                 if(!maxheap.empty()){

//                 auto[ch2,frequency2] = maxheap.top();
//                 maxheap.pop();
//                 ans+=ch2; // ek hi baar woh ch2 daalunga phir waapas ch1 daalna hai
//                 frequency2--;

//                 if(frequency2 == 0)maxheap.pop();
//                 if(frequency2>0)maxheap.push({ch2,frequency2});
//                 maxheap.push({ch1,frequency});
//                 }
              
//            }
                 
//         }

//         return ans;
//     }
// };


// class Solution {
// public:
//     string repeatLimitedString(string s, int repeatLimit) {
//         vector<int> freq(26, 0);
//         for (char ch : s) {
//             freq[ch - 'a']++;
//         }

//         priority_queue<pair<char, int>> maxheap;
//         // Push characters with their frequency into the max-heap
//         for (int i = 0; i < 26; i++) {
//             if (freq[i] > 0) {
//                 maxheap.push({i + 'a', freq[i]});
//             }
//         }

//         string ans = "";
//         while (!maxheap.empty()) {
//             auto [ch1, frequency1] = maxheap.top();
//             maxheap.pop();

//             // Append up to `repeatLimit` characters of `ch1`
//             int use = min(frequency1, repeatLimit);
//             ans.append(use, ch1);
//             frequency1 -= use;

//             if (frequency1 > 0) {
//                 // If more `ch1` remains but cannot be used due to the repeat limit
//                 if (!maxheap.empty()) {
//                     auto [ch2, frequency2] = maxheap.top();
//                     maxheap.pop();

//                     // Append one character of `ch2` and reinsert it if it still has frequency left
//                     ans += ch2;
//                     frequency2--;
//                     if (frequency2 > 0) {
//                         maxheap.push({ch2, frequency2});
//                     }

//                     // Reinsert `ch1` back into the heap
//                     maxheap.push({ch1, frequency1});
//                 } else {
//                     // If no other character is available, break the loop (cannot satisfy repeatLimit)
//                     break;
//                 }
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
    
    map<char,int,greater<char>>freqMap;
    for(auto it:s){
         freqMap[it]++;
    }
    string result = "";
    while(!freqMap.empty()){

        auto it = freqMap.begin();
        char currch = it->first;
        int use = min(repeatLimit , it->second);
        result.append(use, currch);
        it->second = it->second - use;

        if(it->second == 0)freqMap.erase(it);

        else{
            //move to next char 
            if(freqMap.size()>1){// it has next char
               auto nextch = next(freqMap.begin());
               result+=nextch->first; // ek char daale phir wapas upar jayenge 
               nextch->second--;

               if(nextch->second ==0)freqMap.erase(nextch);
            }
            else{
                  break;
            }
        }
        
    }
return result;
   }
};