class Solution {
public:
    bool validUtf8(vector<int>& data) {
     int n=data.size();
     for(int i=0;i<n;i++){
         int num=data[i];
         int l=7;
         while(l !=2){
          if( (num & (1<<l) )==0){break;}
          l--;
         }
         if(l==6 || l==2){return false;}
         if(l !=7){
             if(l==5){l=1;}
             else if(l==4){l=2;}
             if(i+l>n){return false;}
             int check1=1<<7;
             int check2=1<<6;
             int jump=l;
             while(l !=0){
                 if( (data[i+l] & check1)==0 || (data[i+l] & check2) !=0){return false;}
                 l--;}
          i=jump+i;
         } 
     }
     return true;
    }
};