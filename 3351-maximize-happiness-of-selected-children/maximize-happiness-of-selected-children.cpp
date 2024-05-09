class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
       priority_queue<int> pq;
       int n=happiness.size();
       for(int i=0;i<n;i++){
        pq.push(happiness[i]);
       }
       long long sumOfHapp=0;
       int count=0; //num of children selected

       while(k){
        int curr=pq.top();
        pq.pop();

        if( curr-count<0 ){ break; }
        sumOfHapp+=(curr-count);
        count++;

        k--;

       }
       return sumOfHapp;
    }
};