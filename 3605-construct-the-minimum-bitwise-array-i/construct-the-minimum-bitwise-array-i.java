class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int[] ans = new int[nums.size()];
        int i=0; 
        while(i<nums.size()){
            ans[i]=-1;
            for(int j=0; j<nums.get(i); j++){
                if((j | j+1)==nums.get(i)){
                    System.out.println(j|j+1);
                    ans[i]=j;
                    break;
                }
            }
            i++;
        }
        return ans;
    }
}