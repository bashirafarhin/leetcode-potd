class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int pos=0;
        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){ j++; }
            int count=j-i;
            chars[pos++]=chars[i];
            if(count>1){
                string num=to_string(count);
                for(int k=0;k<num.size();k++){
                    chars[pos++]=num[k];
                }
            }
            i=j;
        }
        return pos;
    }
};