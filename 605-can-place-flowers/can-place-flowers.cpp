class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        int canPlant = 0;
        for (int i = 0; i < bed.size(); i++) {
            if (bed[i] == 0 && !(i>0 && bed[i-1]==1) && !(i !=bed.size()-1 && bed[i+1]==1)) {
                bed[i] = 1;
                canPlant++;
            }
        }
        cout << canPlant;
        return canPlant >= n;
    }
};