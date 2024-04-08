class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       queue<int>q;
       for(int i=0;i<students.size();i++){
        q.push(students[i]);
       }
       int si=0;
       int c=0;
       while(!q.empty()){
        if(q.front()==sandwiches[si]){
            q.pop();
            c=0;
            si++;
        } else {
            c++;
            if(c==q.size()){ return c; }
            q.push(q.front());
            q.pop();
        }
       }
       return 0;
    }
};