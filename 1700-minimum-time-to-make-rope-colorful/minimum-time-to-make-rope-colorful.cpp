class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0;
        int prev=0;
        int i=1;
        int n=colors.size();
        while (i !=n){
           if(colors[prev]==colors[i]){
              if(neededTime[prev]>neededTime[i]){time+=neededTime[i];}
              else {
                time+=neededTime[prev];
                prev=i;}}
           else{prev=i;}
           i++;
        }
        return time;
    }
};