class Solution {
    bool backtrack(vector<int>&arr,vector<int>&sides,int ind,int side){
        if(ind==arr.size()){return true;}
        for(int i=0;i<4;i++){
            if(sides[i]+arr[ind]<=side){
             sides[i]+=arr[ind];
             if(backtrack(arr,sides,ind+1,side)){return true;}
             sides[i]-=arr[ind];
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
    int n=matchsticks.size();
    int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
    if(sum%4 !=0 || n<4){return false;}
    sort(matchsticks.begin(),matchsticks.end(),greater<int>());
    vector<int> sides(4,0);
    return backtrack(matchsticks,sides,0,sum/4);
    }
};