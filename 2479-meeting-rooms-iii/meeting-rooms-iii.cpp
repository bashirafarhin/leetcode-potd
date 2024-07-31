class Solution {
public:
// sort rooms
// find rooms for the current meeting
// it can be empty rooms or take the room which finishes earliest
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int>numMeetingOfRoom(n,0);
        vector<long long>endTimeOfRoom(n,0);
        int m=meetings.size();
        for(auto meeting : meetings){
            int start=meeting[0];
            int end=meeting[1];
            bool found=false;
            int roomFinishesEarliest=0;
            long long earliestTimeofFinish=LLONG_MAX;
            for(int room =0;room<n;room++){
                if(endTimeOfRoom[room]<=start){
                    numMeetingOfRoom[room]++;
                    endTimeOfRoom[room]=end;
                    found=true;
                    break;
                }
                if(endTimeOfRoom[room]<earliestTimeofFinish){
                    roomFinishesEarliest=room;
                    earliestTimeofFinish=endTimeOfRoom[room];
                }
            }
            if(!found){
                int duration=end-start;
                numMeetingOfRoom[roomFinishesEarliest]++;
                endTimeOfRoom[roomFinishesEarliest]+=duration;
            }
        }

        int mostUsedRoom=-1;
        int count=0;
        for(int room=0;room<n;room++){
            if(numMeetingOfRoom[room]>count){
                count=numMeetingOfRoom[room];
                mostUsedRoom=room;
            }
        }
        return mostUsedRoom;
    }
};