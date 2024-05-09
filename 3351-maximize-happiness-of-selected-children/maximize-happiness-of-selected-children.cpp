class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int t=0; //number of times a children is not selected;
        int ind=happiness.size()-1;
        long long sumOfHapp=0;

        while(k){
            if(happiness[ind]-t<0){ break; }
            sumOfHapp+=(happiness[ind]-t);
            t++;
            k--;
            ind--;
        }
        return sumOfHapp;
    }
};