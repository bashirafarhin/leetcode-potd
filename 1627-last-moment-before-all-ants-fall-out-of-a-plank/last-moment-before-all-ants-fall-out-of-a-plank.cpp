class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
     int min_right=1e9,max_left=-1;
     for(auto it : right){
        min_right=min(min_right,it);
     }
     for(auto it : left){
        max_left=max(max_left,it);
     }
     if(left.size()==0){return n-min_right;}
     if(right.size()==0){return max_left;}
     if(n-min_right>max_left){return n-min_right;}
     return max_left;


    }
};