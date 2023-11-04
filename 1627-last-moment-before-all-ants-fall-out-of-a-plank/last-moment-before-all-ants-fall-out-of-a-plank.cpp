class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {   
     sort(left.begin(),left.end(),greater<int>());
     sort(right.begin(),right.end());
     if(left.size()==0){return n-right[0];}
     if(right.size()==0){return left[0];}
     if(n-right[0]>left[0]){return n-right[0];}
     return left[0];


    }
};