class Solution {
public:
    bool checkIfCanGenerateOriginal(vector<int>& derived, int start) {
        // taking original[0]=start;
        int n = derived.size();
        vector<int> original(n, start);
        for (int i = 1; i < n; i++) {
                original[i] = original[i - 1] ^ derived[i-1];
        }
        return derived[n - 1] == original[n - 1] ^ original[0];
    }
    bool doesValidArrayExist(vector<int>& derived) {
        // can't solved the problem because haven't studied the problem
        // statement well, missed that the original array is a binary array so
        // starting from 0th index you should assume that the 0th index can be
        // either 0 or 1 and then you could have done this problem learning if
        // a=b^c then b=a^c and c=a^b

        // taking 0th index as 0
        return checkIfCanGenerateOriginal(derived, 0) ||
               checkIfCanGenerateOriginal(derived, 1);
    }
};