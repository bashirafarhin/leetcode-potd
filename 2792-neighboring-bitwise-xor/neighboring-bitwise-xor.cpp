class Solution {
public:
    bool checkIfCanGenerateOriginal(vector<int>& derived, int start) {
        // taking original[0]=start;
        int n = derived.size();
        vector<int> original(n, start);
        for (int i = 1; i < n; i++) {
            if (derived[i-1] == 1) {
                original[i] = (original[i - 1] == 0 ? 1 : 0);
            } else {
                original[i] = (original[i - 1] == 0 ? 0 : 1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i !=n-1 && derived[i] != original[i] ^ original[i + 1]) {
                return false;
            } else if(derived[n - 1] != original[n - 1] ^ original[0]){
                return false;
            }
        }
        return true;
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