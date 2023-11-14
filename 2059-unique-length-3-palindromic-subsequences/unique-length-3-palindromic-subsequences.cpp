class Solution {
private:
    int first_occ_Ind(int ind, int n, string& s){
        for(int i = 0; i < n; i++){
            if(s[i] - 'a' == ind) return i;
        }
        return -1;
    }
    int last_occ_Ind(int ind, int n, string& s){
        for(int i = n - 1; i >= 0; i--){
            if(s[i] - 'a' == ind) return i;
        }
        return -1;
    }
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        for(int i = 0;i < n; i++){
            freq[s[i] - 'a']++;
        }

        int ans = 0;

        for(int i = 0; i < 26; i++){
            if(freq[i] >= 2){
                int first_occurance = first_occ_Ind(i, n, s);
                int last_occurance = last_occ_Ind(i, n, s);

                if(first_occurance == -1 || last_occurance == -1) continue;

                set<int> st;
                for(int j = first_occurance + 1; j < last_occurance; j++){
                    st.insert(s[j]);
                } 

                ans += st.size();
            }
        }
        return ans;
    }
};