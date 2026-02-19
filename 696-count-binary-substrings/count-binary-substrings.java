class Solution {
    public int countBinarySubstrings(String s) {
        int n=s.length();
        ArrayList<Integer> consecutiveLength = new ArrayList<>();
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s.charAt(i-1)==s.charAt(i)){ cnt++; }
            else { 
                consecutiveLength.add(cnt);
                cnt=1; }
        }
        consecutiveLength.add(cnt);
        int ans=0;
        for(int i=1;i<consecutiveLength.size();i++){
            ans+=Math.min(consecutiveLength.get(i-1),consecutiveLength.get(i));
        }
        return ans;
    }
}