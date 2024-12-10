// class node{
//      public:
//         char data;
//         int count;

//         node(char d,int c){
//             data = d;
//             count = c;
//         }
// };
// class compare{
//      public:
//      bool operator()(node* a,node*b){
//           return a->count < b->count;
//      }
// };

// class Solution {
// public:
//     string reorganizeString(string s) {
//       unordered_map<char,int>count_Char;
//       for(auto i:s){ // apon ko counting daalni hai har ek character ki
//         count_Char[i]++;
//       }
//      //creation of MaxHeap , jisme apon ko (char, count) , heap mei insert karna hai
//       priority_queue<node*,vector<node*>,compare>MaxHeap;

//       // abb mujehe heap mei insert karn ahia 
//       for(int i =0;i<26;i++){
//           if(count_Char[i]!=0){
//               node* temp = new node(i+'a',count_Char[i]);
//               MaxHeap.push(temp);
//           }
//       }

//       // abb hame 2 characters saatgh mei niklane hai taaki alag alag aa sake 
//       // abb 2 characters ko nikalne ke liye kam se kam 2 characters hone chahiye  heap mei

       
//        string ans ="";

//         while(MaxHeap.size()>1){
//           node* first = MaxHeap.top();
//           MaxHeap.pop();
//           node* second = MaxHeap.top();
//           MaxHeap.pop();

//           ans+=first->data;
//           ans+=second->data; // hamne ans mei insert kar diya strinhg ko 

//           first->count--; // count hamne kam kar diya 
//           second->count--;

//         if(first->count!=0){
//             MaxHeap.push(first);
//         }
//         if(second->count!=0){
//             MaxHeap.push(second);
//         }


//       }

//       // agar maanlo abb heap mei koi ek elementy last bacch gya kyunki upar ka loop toh do do ko dekh rha na
//       // check the first test case
      
//       if(MaxHeap.size() == 1){
//           node* temp = MaxHeap.top();
//           MaxHeap.pop();
//          if(temp->count ==1)ans+=temp->data;
//          else
//             return "";
         
//       }
//       return ans;
      
//     }
// };

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node {
public:
    char data;
    int count;

    node(char d, int c) {
        data = d;
        count = c;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->count < b->count;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        // Create mapping
        int freq[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch - 'a']++;
        }

        // Priority queue with pointers to nodes
        priority_queue<node*, vector<node*>, compare> maxHeap;

        // Create nodes dynamically and push into the maxHeap
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                node* temp = new node(i + 'a', freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";

        while (maxHeap.size() > 1) {
            // Extract the top two nodes
            node* first = maxHeap.top();
            maxHeap.pop();
            node* second = maxHeap.top();
            maxHeap.pop();

            // Add their characters to the result
            ans += first->data;
            ans += second->data;

            // Decrement their counts
            first->count--;
            second->count--;

            // Push back into the maxHeap if counts are not zero
            if (first->count > 0) {
                maxHeap.push(first);
            } 
            

            if (second->count > 0) {
                maxHeap.push(second);
            } 
            
        }

        // Handle the last remaining node
        if (maxHeap.size() == 1) {
            node* temp = maxHeap.top();
            maxHeap.pop();
            if (temp->count == 1) {
                ans += temp->data;
            } else {
         // Free memory
                return ""; // Cannot reorganize
            }
        }

        return ans;
    }
};
