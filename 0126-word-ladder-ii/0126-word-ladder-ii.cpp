// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         vector<vector<string>>ans;
//         queue<pair<vector<string>,int>>q;
//         unordered_set<string>st(wordList.begin(),wordList.end());

//         q.push({{beginWord},1}); // current begin word and level pushed
//         int prevlevel = -1;
//         vector<string>toBeremoved; // jab ek level ho jayega process uske baad 
//         // set se apon woh string remove kar dmege 

//         while(!q.empty()){
//             auto  fnode = q.front();
//             q.pop();

//             auto currSeq = fnode.first;
//             auto currString = currSeq[currSeq.size()-1]; // jo bhi seq mei last word hoga usko process karenge 
//             auto currlevel = fnode.second;

//             if(currlevel != prevlevel){  // YAHA MERA GALTI HO SKATA HAI
//                 for(auto s:toBeremoved)st.erase(s);
//                 toBeremoved.clear();
//                 prevlevel = currlevel;
                 
//             }

//             for(int index =0;index<currString.size();index++){
//                 char originalcharacter = currString[index];
//                 for(char ch = 'a';ch<='z';ch++){
//                      currString[index] = ch;
//                      //abb check karo word lsit mei 
//                      if(st.find(currString)!=st.end()){
//                          auto temp = currSeq;
//                          temp.push_back(currString);
//                          q.push({{temp},currlevel +1});
//                          //abhi remove karna hai jo process hua 
//                          toBeremoved.push_back(currString);
//                      }
//                 }
//                 //YAHA PHIRSE GALTI 
//                 currString[index] = originalcharacter;
//             }
//             if(currString == endWord){
//                  ans.push_back(currSeq);
//             }

//         }
//         return ans;

//     }
// };
class Solution {
public:
    
    vector<string> findNextStrings(string word, unordered_set<string> dict) {
        vector<string> ans;
        
        for(int i=0; i<word.length(); i++) {
            char currChar = word[i]; 
            
            for(char ch = 'a'; ch<= 'z'; ch++) {
                //replace
                word[i] = ch;
                
                // old char is same as new char
                //new string should be present in the dictionary
                if(ch == currChar || !dict.count(word))
                    continue;
                
                ans.push_back(word);
            }
            word[i] = currChar;
        }
        return ans;
    }
    
    void bfs(string src, string dest, unordered_set<string>& dict,unordered_map<string, vector<string> >& adjList  ) {
        queue<string> q;
        q.push(src);
        
        //if node is present in dict, erase it
        if(dict.find(src) != dict.end()) {
            dict.erase(dict.find(src));
        }
        
        
        map<string, bool> inserted;
        inserted[src] = 1;
        
        while(!q.empty()) {
            
            vector<string> visited;
            
            //particular layer process
            for(int i = q.size(); i>0; i--) {
                string currWord = q.front();
                q.pop();
                
                vector<string> neigh = findNextStrings(currWord, dict);
                
                //adjList fill
                for(auto w: neigh) {
                    
                    //add in adj List
                    adjList[w].push_back(currWord);
                    
                    visited.push_back(w);
                    
                    //check if its not in queue, then insert and mark it
                    if(inserted.find(w) == inserted.end()) {
                        q.push(w);
                        inserted[w] = 1; 
                    }  
                }  
            }
            
            //remove the strings from previous layer
            for(int i=0; i<visited.size(); i++) {
                if(dict.find(visited[i]) != dict.end()) {
                    dict.erase(dict.find(visited[i]));
                }
            }   
        } 
    }
    
    
    void solve(string src, string dest,unordered_map<string, vector<string> >& adjList, vector<string>& path, vector<vector<string>>& output ) {
        cout << "src is " << src << endl;
        //base case
        if(src == dest) {
            output.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }
        
        for(int i=0; i<adjList[src].size(); i++) {
            path.push_back(adjList[src][i]);
            
            solve(adjList[src][i], dest, adjList, path, output);
            
            path.pop_back();
        }
    }
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, vector<string> > adjList;
        vector<string> path;
        vector<vector<string>> output;
        
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        //graph creation
        bfs(beginWord, endWord, dict, adjList);
        
        cout << "Printing graph " << endl;
        for(auto i: adjList) {
            cout << i.first << " -> " ;
            for(auto j: i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
        
        //include src in path
        path.push_back(endWord);
        
        //call backtrack solve function
        solve(endWord, beginWord, adjList, path, output);
        
        return output;
        
   
    }
};



