class Solution {
    vector<int> prefix(string pat , int n){
            vector<int> pi(n,0);
            int pre =0;
            int suf=1;
            while(suf<n){
                if(pat[pre]==pat[suf]){
                    pi[suf]=pre+1;
                    pre++;
                    suf++;
                }
                else{
                    if(pre==0){
                        pi[suf]=0;
                        suf++;
                    }
                    else{
                        pre = pi[pre-1];
                    }
                }
            }
            
            return pi;
        }
        vector <int> search(string pat, string txt)
        {
        vector<int> pi=prefix(pat,pat.size());
        vector<int> ans;
            int p1=0;
            int p2=0;
            while(p1<txt.size()){
                if(txt[p1]==pat[p2] and p2<pat.size() ){
                    p1++;
                    p2++;
                }
                else{
                    if(p2==0){
                        p1++;
                    }
                    else{
                        p2=pi[p2-1];
                    }
                    
                }
                if(p2==pat.size()){
                        ans.push_back(p1-pat.size());
                        p2=pi[p2-1];
                    }
            }
            
            return ans;
        }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> as=search(a,s);
        vector<int> bs=search(b,s);
        int l1=as.size();
        int l2=bs.size();
        int j=0;
        vector<int>ans;
        for(int i=0;i<l1;i++){
         while(j<l2 && (as[i]>bs[j]) && (as[i]-bs[j])>k ){j++;}
         if(j<l2 && abs(as[i]-bs[j])<=k){ans.push_back(as[i]);}
        }
        return ans;  
    }
};