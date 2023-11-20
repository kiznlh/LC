
/**
 * MinimumAmountOfTimeToCollectGarbage
 */
//https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/?envType=daily-question&envId=2023-11-20

/*
Explanation
    Firstly sum up the amount of gabages in total.
    Second find up the last position for each type.
    Calculate the prefix sum array of the travel distance.
    Sum up the distance for each type of garbage.
    Complexity

Time O(garbage + travel)
Space O(1)
 */
public class MinimumAmountOfTimeToCollectGarbage {
    public int garbageCollection(String[] garbage, int[] travel) {
        int last[] = new int[128], res = 0;
        for (int i = 0; i < garbage.length; ++i) {
            res += garbage[i].length();
            for (int j = 0; j < garbage[i].length(); ++j)
                last[garbage[i].charAt(j)] = i;
        }
        for (int j = 1; j < travel.length; ++j)
            travel[j] += travel[j - 1];
        for (int c : "PGM".toCharArray())
            if (last[c] > 0)
                res += travel[last[c] - 1];
        return res;
    }
    public static void main(String[] args) {
        String[] garbage = {"G","P","GP","GG"};
        int[] travel = {2,4,3};
        MinimumAmountOfTimeToCollectGarbage obj = new MinimumAmountOfTimeToCollectGarbage();
        System.out.println("answer = " + obj.garbageCollection(garbage, travel));

        
    }
}