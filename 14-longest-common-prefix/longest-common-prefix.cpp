class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        string prefix="";
        int n=arr.size();

        for(int i=0;i<arr[0].length();i++){
            
            char curr_prefix_char=arr[0][i];

            int j=1;
            for(j=1;j<n;j++){
               if( i==arr[j].length() || arr[j][i] !=curr_prefix_char ){break;}
            }

            if(j==n){ prefix+=curr_prefix_char; }
            else {break;}
        }

        return prefix;
    }
};