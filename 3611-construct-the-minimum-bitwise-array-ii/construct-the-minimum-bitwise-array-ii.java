class Solution {

    public static int calculate(int x) {
        int shiftBy=0;
        while((x & (1<<shiftBy))!=0 && shiftBy<32){
            shiftBy++;
        }
       return x ^ (1<<(shiftBy-1));
    }

    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] ans = new int[n];
        Arrays.fill(ans, Integer.MAX_VALUE);
        for (int i = 0; i < n; i++) {
            if ((nums.get(i) & 1) == 1) {
                // making last bit 0
                Integer poss1 = nums.get(i) & (~1);

                // second solution
                Integer poss2 = calculate(nums.get(i));

                System.out.println(nums.get(i)+" "+ poss1+ " "+poss2);

                if ((poss1 | (poss1 + 1)) == nums.get(i)) {
                    ans[i] = Math.min(ans[i], poss1);
                }

                if ((poss2 | (poss2 + 1)) == nums.get(i)) {
                    ans[i] = Math.min(ans[i], poss2);
                }

            } else {
                ans[i] = -1;
            }
        }
        return ans;
    }

}