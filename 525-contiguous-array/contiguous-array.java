class Solution {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        int sum=0;
        int ans=0;
        Map<Integer, Integer> map= new HashMap<>();
        map.put(0,-1);
        for(int i =0;i<n; i++){
            sum+=(nums[i]==0 ? -1 : nums[i]);
            if(map.get(sum) !=null){
                ans=Math.max(ans, i-map.get(sum));
            } else {
                map.put(sum,i);
            }
            
        }
        return ans;
    }
}