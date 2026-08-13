class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        int[] ans = new int[2];
        HashMap<Integer, Integer> mp = new HashMap<>();

        for(int i=0; i<n; i++) {
            int rem = target - nums[i];
            if(mp.containsKey(rem)) {
                ans[0] = mp.get(rem);
                ans[1] =i;
                break;
            }
            mp.put(nums[i], i);
        }
        return ans;

    }
}