class Solution {
public:
    int minOperations(int k) {
        int count=k;
        for(int i=1;i<=(k/2)+1;i++){
            int op=i-1;
            int sum=k;
            while(sum-i>=1){
                sum-=i;
                op++;
            }
            count=min(count,op);
        }
        return count;
    }
};