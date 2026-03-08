class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // for n possible values are pow(2,n)
        // so we are checking whats missing starting from 0 and returning that
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int missingNumber = 0;
        for (int i = 0; i < n; i++) {
            int curr = 0;
            int power = 1;
            for (int j = nums[i].size() - 1; j >= 0; j--) {
                int bit = nums[i][j] - '0';
                curr += (bit * power);
                power *= 2;
            }
            if (curr != missingNumber) {
                break;
            }
            missingNumber++;
        }
        cout << missingNumber;

        // convert number into binary string
        string binaryans = "";
        if (missingNumber != 0) {
            int divisor = 2;
            int dividend = missingNumber;
            int remainder;
            while (dividend != 1) {
                int quotient = dividend / divisor;
                remainder = dividend % divisor;
                binaryans = (remainder == 0 ? '0' : '1') + binaryans;
                dividend = quotient;
            }
            binaryans = '1' + binaryans;
        }

        // append 0 at left
        int lengthToFill = n - binaryans.size();
        while (lengthToFill--) {
            binaryans = '0' + binaryans;
        }

        return binaryans;
    }
};