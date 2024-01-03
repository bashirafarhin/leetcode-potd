class Solution {
/*
observations
1-we are applying any method in an alternate manner
2-take varoius examples of numbers having only 1 set-bit

   number                          steps to make MSB zero
eg-1000--->0100                      8
   100--->010                        4
   10--->01                          2
   1--->0                            1
 from above examples we can generate the FORMULAE
 numbers of operations required to make last setbit (MSB) equal to 0,
  F(ith bit)=2*F(ith-1 bit)+1

3-take examples of numbers having more than 1 set-bit
 eg-1111
 ⭐ when reducing 1000->0 we observe that 1111 came in between as shown below
    1000--->1001--->1011--->1010--->1110--->1111--->1101--->1100--->0100--->101--->111--->110--->110--->010--->11--->01--->0

  1) func(1000->0)=func(1000->1111)+func(1111->0)
     rearrange above equation
  2) func(1111->0)=func(1000->0)-func(1000->1111)
     In func(1000->1111) here we are not changing last bit as both is 1 so removing that bit 
     func(1000->1111)==func(000->111)===func(0->111)
  3) func(1111->0)=func(1000->0)-func(0->111)
     no. of steps required to convert 0->111 is same as no. of operations required to convert 111->0
  4) func(1111->0)=func(1000->0)-func(111->0)
  ⭐similarly we can write
   func(111->0)=func(100->0)-func(11->0)
   func(11->0)=func(10->0)-func(1->0)
   func(1->0)    Base case
  thus we can write
  5) func(1111->0)=func(1000->0)-func(100->0)+func(10->0)-func(1->0)

 eg-1010
    func(1010->0)=func(1000->0)-func(10->0)+func(1->0);

  ⭐here in both example observe a recursive fucntion which is implemented in the code

  in dp we are storing how many steps are required to reduce numbers having 1 set bit to 0 using the formulae above

*/
public:
    int minimumOneBitOperations(int n) {
        if(n==0){return 0;}
        vector<long long> dp(31,0);
        dp[0]=1; //base case   1-->0
        for(int i=1;i<31;i++){
            dp[i]=dp[i-1]*2 +1;
        }
        int steps=0;
        int sign=1;
        for(int i=30;i>=0;i--){
            if(n & (1<<i)){
                steps+=dp[i]*sign;
                sign=0-sign;
            }
            
        }
        return steps;
    }
};