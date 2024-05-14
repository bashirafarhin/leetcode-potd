class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
    //observation
    //we can swap any chracter from anywhere to anywhere that is from same word or different word
    vector<int>wordSize;
    vector<int>freq(26,0);
    for(string word : words){
        for(char c: word){
           freq[c-'a']++; 
        }
        wordSize.push_back(word.size());
    }
    sort(wordSize.begin(),wordSize.end());

    int even=0;
    int odd=0;
    for(int i=0;i<26;i++){
       even+=freq[i]/2;
       odd+=freq[i]%2;
    }

    int n=words.size();
    int ans=0;

    for(int i=0;i<n;i++){
        if(wordSize[i]%2){
          if(odd){ odd--; }
          else{
            even--;
            odd++;
          }
        }
        if(even<wordSize[i]/2) break;
        even-=wordSize[i]/2;
        ans++;
    }
    return ans;


    return true;
    }
};