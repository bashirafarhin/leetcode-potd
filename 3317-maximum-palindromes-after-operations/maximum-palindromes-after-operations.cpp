class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int even = 0;
        vector<int> freq(26, 0);
        vector<int> lengths;
        for (string word : words) {
            lengths.push_back(word.size());
            for (char ch : word) {
                freq[ch - 'a']++;
                if (freq[ch - 'a'] == 2) {
                    even += 2;
                    freq[ch - 'a'] = 0;
                }
            }
        }

        for(int n : freq){ cout<<n<<" "; }
        cout<<endl;


        int odd = accumulate(freq.begin(), freq.end(), 0);
        sort(lengths.begin(), lengths.end());
        int ans = 0;
        for (int len : lengths) {

            if(len & 1){
             int numOfEvenCharRequired = len - 1;
             if (even < len - 1) { return ans; }
             even -= numOfEvenCharRequired;
             len -= numOfEvenCharRequired;
             if (len == 1) {
                if (odd != 0){
                 odd -= 1;}
                else { even--; }
                 len--;}
            } else {
                if(even<len){ return ans; }
                even-=len;
                len=0;
            }
            ans++;
        }
        return ans;
    }
};