class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> hm = new HashMap<>();
        for(int i =0; i<nums1.length;i++){
            hm.put(nums1[i], hm.getOrDefault(nums1[i],0)+1);
        }
        ArrayList<Integer> arr = new ArrayList<>();
        for(int num : nums2) {
            if(hm.containsKey(num) && hm.get(num) >0) {
                arr.add(num);
                hm.put(num,hm.get(num)-1);
            }
        }

        int[] ans = new int[arr.size()];
        for(int i=0; i<arr.size(); i++) {
            ans[i] = arr.get(i);
        }
        return ans;

    }
}