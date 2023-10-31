
import java.util.Arrays;
//done
class Solution {
    public int[] findArray(int[] pref) {
        int n = pref.length;
        int[] ans = new int[n];
        ans[0] = pref[0];
        for (int i = 1; i < n; ++i){
            ans[i] = pref[i] ^ pref[i-1];
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] pref = {5,2,0,3,1};
        Solution a = new Solution();
        System.out.println((Arrays.toString(a.findArray(pref))));
    }
}