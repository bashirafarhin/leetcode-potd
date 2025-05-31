class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size() && n;i++){
            if(!flowerbed[i]){
                if(i-1>=0 && flowerbed[i-1]){ continue; }
                if(i+1<flowerbed.size() && flowerbed[i+1]){ continue; }
                flowerbed[i]=1;
                n--;
            }
        }
        return !n;
    }
};