class Solution {

    public void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        return;
    }

    public void reverse(int[] nums, int start, int end) {
        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
        return;
    }

    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int pivot = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (nums[i - 1] < nums[i]) {
                // find the least number which is just greater than i-1;
                int ind = i;
                for (int j = i; j < n; j++) {
                    if (nums[j] > nums[i - 1] && nums[ind] >= nums[j]) {
                        ind = j;
                    }
                }

                swap(nums, i - 1, ind);

                pivot = i;
                break;
            }
        }
        reverse(nums, pivot, n - 1);
    }
}