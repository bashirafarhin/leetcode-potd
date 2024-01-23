class Solution {
    int solve(int i,vector<int>&words,int word){
        if(i==words.size()){
            int len=word>>26;
            return len;}

        int take=0;
        int oldword=word & ((1<<26)-1); //taking only word by removing the length which is stored in last 6 bits
        int newword=words[i] & ((1<<26)-1);
        if(!(oldword & newword)){
            int newlen=words[i]>>26;
            int oldlen=word>>26;
            newword=oldword | newword | ((newlen + oldlen)<<26);
            take=solve(i+1,words,newword);
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
                if(mask & charsetbit){ //if these type of word present eg-aafgremoving that words
                    include=false;
                    break;}
                charsetbit=charsetbit | mask;
            }
            if(include){
                int size=arr[i].length();
                charsetbit=charsetbit | (size<<26); //storing length after 26 bits
                words.push_back(charsetbit);}
        }

        // implement  same recursion as done in method-1
        return solve(0,words,0);
        
    }
};