
class TrieNode{
   public:
    char data; // node mei data daal rhe hai
                 // is node ke bahut saaare bacche hosakte hai for char suppose take 26 char
                    //we can create an array
     TrieNode* children[26];
     bool isTerminal;  //mujhe pata hona chahiye ki ye node current  terminal hai ki nhi
     int children_cnt;


     TrieNode(char d ){
         this->data = d; 
         for(int i=0;i<26;i++){
          children[i] =  NULL;  
         }
        this->isTerminal = false ; // starting mei false maana hai 
        this->children_cnt =0;
     }
};
class Solution {
public:
void insertword(TrieNode* root , string word){
    //base case  
    // jab mera word ka lngth 0 ho jayega tab matlab ye temrinal node hai 
    if(word.length() == 0){
        root->isTerminal = true; 
        return;
    }
    char ch = word[0]; // pehla char 
    int index = ch-'a'; // apon uppercase letters mei game khel rhe hai 
    // ye index kaunsa hai woh check karna hai in the trienode mei 
    TrieNode* child;
    // present hai ki nhi 
    // abb check karna hai ki jo bhi cahr ye woh pehele se preseny hai ki nhi
    if(root->children[index]!=NULL){
          // pehele se present hai 
          child = root->children[index];
    }
    else{
      // naya char hai , soe we need new insertion and then
       child = new TrieNode(ch);
       root->children[index] = child;
        root->children_cnt++;
    }
    // recursive call for teh remaining caharacter s excpet the first one
    insertword(child , word.substr(1));
    //abb root bhi neeche ho jaayega kyunki abb saara kaam childs ka baaki hai 

}
  void findLCP(string first , string &ans,TrieNode* root)
  {

    if(root->isTerminal){
        return ;
    }
      for(int i=0;i<first.size();i++){
          char ch = first[i];

          if(root->children_cnt ==1){
             // sahi hai phir
             ans+=ch;
             int index = ch-'a'; // uss children ke character ka index nikalnege phir root ko update kar denge
             root = root->children[index]; 
          }
          else{
              // asgar cnt ==2 ho gya toh matlab apon break karenge 
              break;
          }

          if(root->isTerminal){
             break; // agar woh terminal hai toh phit break;
          }
      }



  }
    string longestCommonPrefix(vector<string>& strs) {
    
      TrieNode* root = new TrieNode('-');
      for(int i=0;i<strs.size();i++){
          insertword(root,strs[i]);
      }
        string ans ="";
        string first = strs[0];
        findLCP(first,ans,root);
        return ans;

    }
};