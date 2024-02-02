class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        int num=1;
        int inc=1;
        for(int i=2;i<=9;i++){
            inc=inc+pow(10,i-1);
            num=num+inc;
            int n=num;
            int j=9-i+1;
            while(n<=high && j ){
               if(low<= n ) { ans.push_back(n); }
                n+=inc;
                j--;
            }
        }
        return ans;
    }
};

