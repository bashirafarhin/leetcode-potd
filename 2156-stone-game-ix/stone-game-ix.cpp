class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int>freq(3,0);
        for(int n : stones){
            freq[n%3]++;
        }
        bool flip=freq[0] & 1;
        return flip ? abs(freq[1] - freq[2]) > 2 : (freq[1] > 0 && freq[2] > 0);
    }
};