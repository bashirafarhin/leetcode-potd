class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();

        if (n<= k) {
            return "0";}
        if(k == 0){
            return num;}

        vector<char> st;
        for(int i=0;i<n;i++){
            while ( k>0 && !st.empty() && st.back()>num[i] ){
            st.pop_back();             //storing number in stack in increasing order
            k--;
            }
            st.push_back(num[i]);
        }
        
        while(k){
         k--;
         st.pop_back();
        }

       string ans="";
       for(int i=0;i<st.size();i++){
          if(ans.empty() && st[i]=='0'){
              continue; //do not add leading zeroes
          }
          ans.push_back(st[i]);
       }

        if(ans.empty()){return "0";}

        return ans;

    }
};