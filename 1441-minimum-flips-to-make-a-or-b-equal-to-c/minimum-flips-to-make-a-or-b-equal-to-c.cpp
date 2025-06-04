class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a || c || b){
            int a_last_bit=a & 1;
            int b_last_bit=b & 1;
            int c_last_bit=c & 1;
            if(c_last_bit){
                if(!a_last_bit && !b_last_bit){ ans++; }
            } else {
                if(a_last_bit){ ans++; }
                if(b_last_bit){ ans++; }
            }
            cout<<ans<<endl;
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return ans;
    }
};