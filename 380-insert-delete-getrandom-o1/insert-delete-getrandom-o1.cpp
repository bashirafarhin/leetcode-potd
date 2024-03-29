class RandomizedSet {
    vector<int> arr;
    unordered_map<int,int> mp; //storing {values , index}
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(mp.find(val) !=mp.end()){return false;}
        arr.push_back(val);
        mp[val]=arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) ==mp.end()){return false;}
        int ind=mp[val];
        arr[ind]=arr[arr.size()-1];
        mp[ arr[arr.size()-1] ]=ind;
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */