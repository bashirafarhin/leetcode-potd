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
        int start=0;
        int end=n;
        while(start<=end){
            int myGuess=start+(end-start)/2;
            int check=guess(myGuess);
            if(!check){ return myGuess; }
            else if(check>0){ start=myGuess+1; }
            else{ end=myGuess-1; }
        }
        return -1;
    }
};