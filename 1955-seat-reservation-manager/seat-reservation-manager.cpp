class SeatManager {
    int available=1;
public:
    priority_queue<int,vector<int>,greater<int>> pq;//store unreserved seats
    SeatManager(int n) {}
    
    int reserve() {
     if(pq.empty()){return available++;}
     int reserved_seat_num=pq.top();
     pq.pop();
     return reserved_seat_num;
     
    }
    
    void unreserve(int seatNumber) {
       pq.push(seatNumber); 
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */