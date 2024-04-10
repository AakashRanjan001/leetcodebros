class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        // init the size of the deck
        int n = deck.size();

        // sort the deck in the order we want
        sort(deck.begin() , deck.end());

        // make a q and populate it will all the indexes of the array
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i);
        }


        // make a current index j and init it with 0
        int j = 0;

        // making an array ans with size n storing the answer
        vector<int> ans(n);

        // till the queue is not empty just keep on doing the following process
        while(q.empty() == false){
            // get the front index of the queue and pop it
            int front = q.front();
            q.pop();

            // at this front index put the current element from deck
            ans[front] = deck[j++];

            // if there are any more elements left the pop the front
            // and push it at the end
            q.push(q.front());
            q.pop();
        }

        // return the final answer array
        return ans;
    }
};
