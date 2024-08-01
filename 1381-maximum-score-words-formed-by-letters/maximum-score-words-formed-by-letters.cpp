class Solution {
public:
    int helper(int i,vector<string>& words, vector<int>& freq, vector<int>& score){
        if(i==words.size()){
            return 0;
        }

        int take=0;
        bool cantake=true;

        //check if word can be taken or not
        for(char ch : words[i]){
            if(freq[ch-'a']==0){
                cantake=false;
            } else {
                take+=score[ch-'a'];
            }
            freq[ch-'a']--;
        }

        //if we can take the word
        if(cantake){
            take=take+helper(i+1,words,freq,score);
        } else {
            take=0;
        }
        

        //restore freq
        for(char ch : words[i]){
            freq[ch-'a']++;
        }

        int nottake=helper(i+1,words,freq,score);
        return max(take,nottake);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);
        for(char c : letters){
            freq[c-'a']++;
        }
        return helper(0,words,freq,score);

    }
};