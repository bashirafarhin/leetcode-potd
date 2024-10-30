class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
       int emptyB=0;
       int count=0;
       while(numBottles+emptyB>=numExchange){
        count+=numBottles;
        emptyB+=numBottles;
        numBottles=0;
        while(numExchange<=emptyB){
            emptyB-=numExchange;
            numExchange+=1;
            numBottles+=1;
        }
       }
       return count+numBottles;
    }
};