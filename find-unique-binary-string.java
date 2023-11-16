class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int n = nums[0].length();
        StringBuilder ans = new StringBuilder(n);
        int i = 0;
        for (String num: nums){
            ans.append(num.charAt(i) == '1' ? '0' : '1');
            i++;
        } 
        while(i < n - 1){
            ans.append('0');
            i++;
        }
        return ans.toString();
    }
    
}