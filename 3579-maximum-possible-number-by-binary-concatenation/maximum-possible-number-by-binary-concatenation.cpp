class Solution {
public:
    // static bool custom(string& a, string& b) {
    //     int n=a.size();
    //     int m=b.size();
    //     cout<<a<<" "<<b<<" ";
    //     int i=0;
    //     int j=0;
    //     while(i<n && j<m){
    //         if(a[i]=='0' && b[j]=='1'){
    //             //make string b store before a
    //             cout<<"1"<<endl;
    //             return false;
    //         } else if(a[i]=='1' && b[j]=='0'){
    //             //make string a store before b
    //             cout<<"2"<<endl;
    //             return true;
    //         }
    //         i++;
    //         j++;
    //     }
    //     if(i==n && j<m){
    //         //make string a store before b
    //         cout<<"3"<<endl;
    //         return false;
    //     }
    //     if(i<n && j==m){
    //         //make string b store before a
    //         cout<<"4"<<endl;
    //         return true;
    //     }
    //     return false;
    // }
    static bool custom(const std::string& a, const std::string& b) {
        return a + b > b + a;
    }

    int maxGoodNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> arr(n);

        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = 31; j >= 0; j--) {
                int bit = (nums[i] >> j) & 1;
                if (bit == 1 && !flag) {
                    flag = true;
                }
                if (flag)
                    arr[i] += (bit + '0');
            }
        }

        cout << "before" << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        sort(arr.begin(), arr.end(), custom);

        cout << "after" << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        int ans = 0;
        int k = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = arr[i].size() - 1; j >= 0; j--) {
                int bit = arr[i][j] - '0';
                ans += (k * bit);
                k *= 2;
            }
        }

        return ans;
    }
};