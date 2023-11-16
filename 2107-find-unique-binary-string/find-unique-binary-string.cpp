class Solution {
public:
    string getbinary(int n,int size){
        string bin="";
        while(size--){
            if(n&1){
                 bin+="1";
            }
            else{
                bin+="0";    
            }
            n=n>>1;
        }
        cout<<bin<<" ";
        return bin;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        set<string>check(nums.begin(),nums.end());
        string temp;
        for(int i=0;i<pow(2,n);i++){
                temp=(getbinary(i,nums.size()));
                if(check.find(temp)==check.end()){
                      break;
                }
        }
        return temp;
    }
};