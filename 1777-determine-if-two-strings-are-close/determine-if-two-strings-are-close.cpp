class Solution {
public:
    bool closeStrings(string word1, string word2) {
    int l1=word1.length();
    int l2=word2.length();
    if(l1 !=l2){return false;}
    unordered_map<char,int>mp1;
    for(int i=0;i<l1;i++){
     mp1[word1[i]]++;
    }
    unordered_map<char,int>mp2;
    for(int i=0;i<l1;i++){
     mp2[word2[i]]++;
    }
    for(auto it : mp1){
        if(mp2.count(it.first)==0){return false;}
    }
    
    vector<int> arr1;
    vector<int> arr2;

    for(auto it : mp1){
        arr1.push_back(it.second);
        }
    for(auto it : mp2){
        arr2.push_back(it.second);
        }
    
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    
    for(int i=0;i<arr1.size();i++){
        if(arr1[i] !=arr2[i]){return false;}
    }

   
    return true;
    }
};