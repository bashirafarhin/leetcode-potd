class Solution {
public:
    int maximumLength(string s) {
        /*
        if a string has all same character,then the maximum length of substring having frequency 3 is (n-2)
        eg string-----maximum length of substring having frequency 3
            aaa          a
            aaaa         aa
            aaaaa        aaa
        which is very easy to observe
        problem occur in these type of cases
        case-1
         aaaabcaaa---here the maximum length of special substring having frequency 3 is--->3
        case-2
        eg
         aaaa b aa c aaaaa d aaaa e a---here the maximum length of special substring having frequency 3 is--->4
          --->max length of special substring is obtained by checking the 3 largest substring
        case-3
         aaaaaa b aa c aaa d aa
         here the maximum length of special substring having frequency 3 is--->4
        */
        unordered_map<char,vector<int>> mp;
        int count=0;
        char lastChar=s[0];
        for(char c : s){
            if(lastChar==c){
                count++;
            } else {
                mp[lastChar].push_back(count);
                count=1;
                lastChar=c;
            }
        }
        mp[lastChar].push_back(count);
        
        int ans=-1;
        for(auto it : mp){
         vector<int> arr=it.second;
         sort(arr.begin(),arr.end(),greater<int>());
         int l1=0,l2=0,l3=0;

         if(arr.size()>=1){ l1=arr[0] ;}
         if (arr.size()>=2){ l2=arr[1] ;}
         if(arr.size()>=3){  l3=arr[2] ;}

         if(l1==l2 && l3<l1) l2--;
         if(l1+l2+l3>=3) ans=max({ans,l1-2,l2});

        }
        return (ans==0)? -1 : ans;
    }
};