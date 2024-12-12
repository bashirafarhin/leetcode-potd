class SmallestInfiniteSet {
    set<int>st;
    int current;
public:
    SmallestInfiniteSet() {
        current=1;
    }
    
    int popSmallest() {
        int min;
        if(st.empty()){
            min=current;
            current++;
        } else{
            min=*st.begin();
            st.erase(st.begin());
        }
        return min;
    }
    
    void addBack(int num) {
        if(num<current){
            st.insert(num);
        }
    }
};