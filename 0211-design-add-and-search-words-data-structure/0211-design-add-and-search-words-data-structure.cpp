class WordDictionary {
public: 
    struct trieNode{
           trieNode* children[26];
           bool isEndOfWord;
    };

    trieNode* getNode(){
         trieNode* newNode = new trieNode();
         newNode -> isEndOfWord = false;

         for(int i=0;i<26;i++){
             newNode->children[i] = NULL;
         }
         return newNode;
    }

    trieNode* root;
    // Trie(){  // CONSTRUCTOR
    //      root = getNode();
    // }

    WordDictionary() {
         root = getNode();
    }
    
    void addWord(string word) {
         
         trieNode* crawler = root;
         for(int i=0;i<word.length();i++){
             int index = word[i] - 'a';
             if(!crawler->children[index]){
                 crawler->children[index] = getNode();
               
             } 
              crawler = crawler->children[index];     
         }
 
         crawler->isEndOfWord = true;
    }

    bool searchUtil(trieNode* root , string word){ 
            
            trieNode* crawler = root;
            for(int i=0;i<word.length();i++){
               char ch = word[i];

               if(ch == '.'){
                  for(int j=0;j<26;j++){
                      if(crawler->children[j]!=NULL){
                          if(searchUtil(crawler->children[j], word.substr(i+1)) == true){
                             return true;
                          }
                      }
                  }
                  return false;
               }
                else if(crawler->children[ch-'a'] == NULL )return false;
                crawler = crawler->children[ch-'a'];
            }
            return (crawler!=NULL && crawler->isEndOfWord == true);
    }
    
    bool search(string word) {

        //"b.ts" , hame dot ke jagah values daalni hai , toh  hame bass pata karna hai ki crawler kaha hai aage 
        //suppose '.' mei 'e' aa gya hence crawler abhi 'e' mei hai , phir recursive call maarnege in remaing "ts";
          return searchUtil(root,word);

          
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */