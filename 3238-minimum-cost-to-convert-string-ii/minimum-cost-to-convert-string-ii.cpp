struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* getNode() { return new TrieNode(); }

    void insert(TrieNode* root, const string& key) {
        TrieNode* curr = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = getNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
};



class Solution {
    vector<vector<long>> floydwarshall(vector<vector<long>>& graph){
      int n=graph.size();
	  for(int src=0;src<n;src++){
	    for(int row=0;row<n;row++){
            if(graph[row][src]==LONG_MAX){continue;}
	        for(int col=0;col<n;col++){
             if(graph[src][col]==LONG_MAX){continue;}
	          if(graph[row][col]>graph[row][src]+graph[src][col]){
	                    graph[row][col]=graph[row][src]+graph[src][col];
	                }
	    
	        }
	    }
	  }
	return graph;
    }


    long long recur(int i, string& s,string& t,TrieNode* root,vector<vector<long>>& graph,unordered_map<string,int>& mp, vector<long long>&dp){
     if(i>=s.length()){return 0;}
     if(dp[i] !=-1LL){
        return dp[i];
     }
     long long ans=LLONG_MAX;
     if(s[i]==t[i]){
         ans=min(ans,recur(i+1,s,t,root,graph,mp,dp));
     }
     string f1="";
     string f2="";
     TrieNode* src=root;
     TrieNode* tar=root;
     for(int k=i;k<s.length();k++){
         f1+=s[k];
         f2+=t[k];
         if(src->children[s[k]-'a'] && tar->children[t[k]-'a']){
          src=src->children[s[k]-'a'];
          tar=tar->children[t[k]-'a'];
          if(src->isEndOfWord && tar->isEndOfWord && graph[mp[f1]][mp[f2]]<LONG_MAX){
            long long val=recur(k+1,s,t,root,graph,mp,dp);
            if(val !=LLONG_MAX){ans=min(ans, graph[mp[f1]][mp[f2]] + val  );}
          }
         } else {
            break;
         }
     }
     return dp[i]=ans;
    }





public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
    unordered_map<string,int> mp; //mapping string into nodes
    for(auto str : original){
      if(!mp.count(str)){mp[str]=mp.size();}}
    for(auto str : changed){
      if(!mp.count(str)){mp[str]=mp.size();}}
    int n=mp.size(); //total nodes in the graph

    //make trie
    Trie trie;
    TrieNode* root = trie.getNode();
    for (auto it : mp) {
        trie.insert(root, it.first);
    }
    //making graph
    vector<vector<long>> graph(n,vector<long>(n,LONG_MAX));
    
    for(int i=0;i<cost.size();i++){
     graph[mp[original[i]]][mp[changed[i]]]=min( (long)cost[i], graph[mp[original[i]]][mp[changed[i]]]) ;}
  
    //obtain shortest distance from all nodes to all nodes using floyd warshall algo
    graph=floydwarshall(graph);
    //obtain cost
    int m=source.length();
    vector<long long>dp(m,-1LL);
    long long ans=recur(0,source,target,root,graph,mp,dp);
    if(ans==LLONG_MAX){return -1;}
    return ans;
    }
};