class Solution {
public:
    bool helper(vector<int>& bloomDay, int m, int k, int day){
        int n=bloomDay.size();
        int adj=k;
        for(int i=0;i<n;i++){
            if(bloomDay[i]-day<=0){
                adj--;
                if(adj==0){
                    m--;
                    if(m==0){
                        return true;
                    }
                    adj=k;
                }
            } else {
                adj=k;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
      int n=bloomDay.size();
      int low=*min_element(bloomDay.begin(),bloomDay.end());
      int high=*max_element(bloomDay.begin(),bloomDay.end());
      int ans=INT_MAX;
      while(low<=high){
        int mid=(low+high)/2;
        if(helper(bloomDay,m,k,mid)){
            ans=min(ans,mid);
            high=mid-1;
        } else {
            low=mid+1;
        }
      }
      return ans==INT_MAX ? -1 : ans;
    }
};