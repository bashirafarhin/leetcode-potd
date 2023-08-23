class Solution {
public:
    string reorganizeString(string s) {
      int max_freq=0;
      char max_freq_char;
      int n=s.length();
      unordered_map<char,int> map;
      for(int i=0;i<n;i++){
       map[s[i]]++;
       if (map[s[i]]>max_freq){
        max_freq=map[s[i]];
        max_freq_char=s[i];
       }}

      if (max_freq>((n+1)/2)){return "";}
      
      int even_index=0,odd_index=1;
      for(even_index=0;even_index<n;even_index+=2){
       if(max_freq >0){
          s[even_index]=max_freq_char;
          max_freq-=1;}
      else{break;}
      }
      
      //put at even position if left else put at odd position
     unordered_map<char,int> ::iterator it=map.begin();
     while(it !=map.end()){
      if(it->first !=max_freq_char){
        while(it->second !=0){
           if(even_index<n){
             s[even_index]=it->first;
             even_index+=2;}
           else{
             s[odd_index]=it->first;
             odd_index+=2;}
           it->second--;}
      }
      it++;}
      
     return s;   
    }
};