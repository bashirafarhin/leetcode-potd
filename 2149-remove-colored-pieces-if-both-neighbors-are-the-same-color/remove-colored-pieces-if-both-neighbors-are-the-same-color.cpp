class Solution {
public:
    bool winnerOfGame(string colors) {
     int n=colors.length();
     int a=0;//num of A which Alice can remove
     int b=0;//num of B which Bob can remove
     for(int i=0;i<n;i++){
       char s=colors[i];
       int j=i+1;
       while(j<n && s==colors[j]){
         j++;}
       j--;
       if(s=='A'){a+=max(0,j-i+1-2);}
       else{b+=max(0,j-i+1-2);}
       i=j;
     }
     return a>b;
    }
};