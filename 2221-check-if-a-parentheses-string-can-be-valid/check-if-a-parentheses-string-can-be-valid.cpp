class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() & 1){ return false; }
        // move left to right
        // for every closing bracket there should be unlocked index or locked (
        stack<int>unlocked;
        stack<int>open;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0'){ unlocked.push(i); }
            else if(s[i]=='('){ open.push(i); }
            else{
                if(!open.empty()){ open.pop(); }
                else if(!unlocked.empty()){ unlocked.pop(); }
                else { return false; }
            }
        }
        //all locked closed should have exhausted till now
        while(!open.empty()){
            if(unlocked.empty() || unlocked.top()<open.top()){ return false; }
            open.pop();
            unlocked.pop();
        }
        return true; 
    }
};