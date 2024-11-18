class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        while(st.find(n)==st.end()){
            st.insert(n);
            int sum=0;
            while(n){
                sum+=((n%10)*(n%10));
                n/=10;
            }
            n=sum;
        }
        return n==1;
    }
};