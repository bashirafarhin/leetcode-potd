class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n=possible.size();
        int bob=0;
        int Danielchandg=0;
        
        for(int i=0;i<n;i++){
            bob+= possible[i]==1 ? 1 : -1 ;
        }
        
   
            
        for(int i=0;i<n-1;i++){ //going to n-1 as bob also have to play at least one level
            
          Danielchandg+= possible[i]==1 ? 1 : -1 ;
          bob+= possible[i]==1 ? -1 : 1;
            
          if(Danielchandg>bob){ return i+1; }
            
        }
        
        return -1;
        
    }
};