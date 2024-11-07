/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1;
        int h=n;
        int pick;
        while(l<=h){
            int m=l+(h-l)/2;
            int userGuess=guess(m);
            if(!userGuess){
                pick=m;
                break;
            } else if (userGuess==1){
                l=m+1;
            } else {
                h=m-1;
            }
        }
        return pick;
    }
};