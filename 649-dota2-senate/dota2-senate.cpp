class Solution {
public:
    string predictPartyVictory(string senate) {
        int totalRSenators=0;
        int totalDSenators=0;
        int totalBanOnR=0;
        int totalBanOnD=0;
        int n=senate.size();
        for(char ch : senate){
            ch=='R' ? totalRSenators++ : totalDSenators++;
        }
        vector<bool>Banned(n,false);
        string win="";
        for(int ind=0;;ind++){
            int i=(n+ind)%n;
            if(Banned[i]){ continue; }
            if(senate[i]=='R'){
                if(totalBanOnR){
                    totalBanOnR--;
                    totalRSenators--;
                    Banned[i]=true;
                } else if(totalDSenators==0){
                    win="Radiant";
                    break;
                } else {
                    totalBanOnD++;
                }
            }

            else{
                if(totalBanOnD){
                    totalBanOnD--;
                    totalDSenators--;
                    Banned[i]=true;
                } else if(totalRSenators==0){
                    win="Dire";
                    break;
                } else {
                    totalBanOnR++;
                }
            }
        }
        return win;
    }
};