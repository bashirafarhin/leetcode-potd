using namespace std;
class Solution {
public:
    bool isPathCrossing(string path) {
     unordered_map<char,pair<int,int>>mp;
     mp['N']={0,1};
     mp['S']={0,-1};
     mp['E']={1,0};
     mp['W']={-1,0};
     int x=0;
     int y=0;
     int n=path.length();
     set<pair<int, int>> st;
     st.insert({x,y});
     for(int i=0;i<n;i++){
         x=x+mp[path[i]].first;
         y=y+mp[path[i]].second;
         if(st.find({x,y}) !=st.end()){return true;}
         st.insert({x,y});
     }
     return false;
    }
};