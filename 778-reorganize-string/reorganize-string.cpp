class Solution {
public:
    string reorganizeString(string s) {
      unordered_map<char,int> map;
      int n=s.length();
      int max_freq=0;
      char max_freq_char;
      for(int i=0;i<n;i++){
        map[s[i]]++;
        if(max_freq<map[s[i]]){
          max_freq=map[s[i]];
          max_freq_char=s[i];
        }
      }

      if(max_freq>((n+1)/2)){
        return "";
      }
      
      int even=0;
      int odd=1;
      for(even=0;even<n;even+=2){
        if(max_freq>0)
         {s[even]=max_freq_char;
         max_freq-=1;}
        else
         {break;}
      }

      unordered_map<char,int> :: iterator it=map.begin();
      while (it != map.end()){
       if(it->first !=max_freq_char){
        while(it ->second !=0){
         if(even<n){
           s[even]=it->first;
           even+=2;}
         else{
           s[odd]=it->first;
           odd+=2;}
         it->second--;}}
        it++;
      }
      return s;
    }
};