class Solution {
public:
    int flowersBloom(int time, vector<int>&timesArr){
        int l=0;
        int h=timesArr.size()-1;
        int ans=0;
        while(l<=h){
            int m=(l+h)/2;
            if(timesArr[m]<=time){
                ans=m+1;
                l=m+1;
            } else {
                h=m-1;
            }
        }
        return ans;
    }

    int flowersDead(int time, vector<int>&timesArr){
        int l=0;
        int h=timesArr.size()-1;
        int ans=0;
        while(l<=h){
            int m=(l+h)/2;
            if(timesArr[m]<time){
                ans=m+1;
                l=m+1;
            } else {
                h=m-1;
            }
        }
        return ans;
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=people.size();
        int m=flowers.size();
        vector<int>startTime(m);
        vector<int>endTime(m);
        for(int i=0;i<m;i++){
            startTime[i]=flowers[i][0];
            endTime[i]=flowers[i][1];
        }

        sort(startTime.begin(),startTime.end());
        sort(endTime.begin(),endTime.end());

        vector<int>ans;
        for(int i=0;i<n;i++){
            int b=flowersBloom(people[i],startTime);
            int d=flowersDead(people[i],endTime);
            ans.push_back(b-d);
        }
        return ans;
    }
};