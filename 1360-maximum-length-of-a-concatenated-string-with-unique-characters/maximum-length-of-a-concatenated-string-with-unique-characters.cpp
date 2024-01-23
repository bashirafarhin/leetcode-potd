class Solution {
    int solve(int i,vector<int>&words,int word){
        if(i==words.size()){
            int len=0;
            for(int i=0;i<26;i++){
                if(word & (1<<i)){len++;}
            }
            return len;}

        int take=0;
        if(!(words[i] & word)){
            take=solve(i+1,words,words[i] | word);
        }
        int nottake=solve(i+1,words,word);
        return max(take,nottake);

    }
public:
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        //make a array in which every word is converted into bitset
        vector<int>words;
        for(int i=0;i<n;i++){
            bool include=true;
            int charsetbit=0;
            for(char c : arr[i]){
                int mask=1<<(c-'a');
                if(mask & charsetbit){include=false; break;}
                charsetbit=charsetbit | mask;
            }

            if(include){words.push_back(charsetbit);}
        }
        // implement  same recursion as done in method-1
        return solve(0,words,0);
        
    }
};