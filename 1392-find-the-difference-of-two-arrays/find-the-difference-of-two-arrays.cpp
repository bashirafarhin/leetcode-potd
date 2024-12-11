class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1;
        for (int num : nums1) {
            st1.insert(num);
        }

        unordered_set<int> st2;
        for (int num : nums2) {
            st2.insert(num);
        }

        vector<int> ans1;
        for (int num : st1) {
            if (st2.find(num)==st2.end()) {
                ans1.push_back(num);
            }
        }

        vector<int> ans2;
        for (int num : st2) {
            if (st1.find(num)==st1.end()) {
                ans2.push_back(num);
            }
        }

        return { ans1, ans2 };
    }
};