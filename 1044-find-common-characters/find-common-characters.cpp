class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       vector<int>freq(26,0);
       int n=words.size();
       for(char c : words[0]){ freq[c-'a']++; }

       for(int i=1;i<n;i++){
        vector<int>temp(26,0);
        for(char ch : words[i]){ temp[ch-'a']++; }
        for(int i=0;i<26;i++){
            if(!freq[i] || !temp[i]){ freq[i]=0; }
            else if(freq[i]>temp[i]){ freq[i]=temp[i]; }
        }
       }

       vector<string> ans;
       for(int i=0;i<26;i++){
        char ch=i+'a';
        string st="";
        st+=ch;
        while(freq[i]){
            ans.push_back(st);
            freq[i]--;
        }
       }

       return ans;
    }
};