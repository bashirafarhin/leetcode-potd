class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> loser;
        unordered_set<int> winner;

        for(auto it : matches){
            int w=it[0];
            int l=it[1];
            if( winner.find(l) !=winner.end()){ winner.erase(l);}
            loser[l]++;
            if(loser.count(w)==0){
                winner.insert(w);
            }       
        }

        vector<int> v1;
        vector<int> v2;

        for(auto it : winner){
          v1.push_back(it);
        }

        for(auto it : loser){
            if(it.second==1){v2.push_back(it.first);}
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return {v1,v2};
    }
};