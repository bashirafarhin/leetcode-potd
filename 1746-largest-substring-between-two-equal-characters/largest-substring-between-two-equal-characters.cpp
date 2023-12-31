class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
      int arr[26];
      memset(arr,-1,sizeof(arr));
      int n=s.length();
      int ans=-1;
      for(int i=0;i<n;i++){
          int index=s[i]-'a';
          if(arr[index]==-1){ //if char not seen before put in array its index
            arr[index]=i;
          } else {
            ans=max(ans,i-arr[index]-1); //if char is seen before find distance between its previous index and current index
          }
      }
      return ans;
    }
};