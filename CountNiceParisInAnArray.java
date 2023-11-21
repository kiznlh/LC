//https://leetcode.com/problems/count-nice-pairs-in-an-array/solutions/1140639/java-c-python-straight-forward/?envType=daily-question&envId=2023-11-21

import java.util.HashMap;
import java.util.Map;

//has the right idea, if you have x elements linked with it other, the total of pair is 
// pair(x) = x - 1 + pair(x-1);
public class CountNiceParisInAnArray {
    public int countNicePairs(int[] A) {
        int res = 0, mod = (int)1e9 + 7;
        Map<Integer, Integer> count = new HashMap<>();;
        for (int a : A) {
            int b = rev(a), v = count.getOrDefault(a - b, 0);
            count.put(a - b, v + 1);
            res = (res + v) % mod;
        }
        return res;
    }

    public int rev(int a) {
        int b = 0;
        while (a > 0) {
            b = b * 10 + (a % 10);
            a /= 10;
        }
        return b;
    }
}
