class Solution {
public:
    vector<int> grayCode(int n) {
     /*
     n=1 {0,1} //base case
     n=2 attach zeroes to all elements of above array then reverse the above array then attach 1 to elements
         {00,01,11,10}
     n=3 {000,001,011,010,110,011,101,100}
     */
     if(n==1)return {0,1};
     vector<int> arr=grayCode(n-1);
     int len=arr.size();
     for(int i=0;i<len;i++){
         arr.push_back(arr[len-1-i] | (1<<(n-1)));
     }
     return arr;
    }
};