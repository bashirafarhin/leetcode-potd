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
    
    int solve(int s,int e){
        int num=s + (e-s)/2;

        int ans=guess(num);
        if(ans==1){
           return solve(num+1,e);
        }else if(ans==-1){
          return solve(s,num-1);
        }
      return num;
    }


    int guessNumber(int n) {
        return solve(1,n);     
    }
};