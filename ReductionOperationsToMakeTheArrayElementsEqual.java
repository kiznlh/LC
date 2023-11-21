
import java.util.Arrays;


/**
 * ReductionOperationsToMakeTheArrayElementsEqual
 */
//https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/?envType=daily-question&envId=2023-11-19

//! this problem by just simplifed to:
//! number of different value += number of next lower value (excluding lowest number)
//! 
public class ReductionOperationsToMakeTheArrayElementsEqual{
    public int reductionOperations(int[] nums) {
        int count = 0;
        int ans = 0;
        Arrays.sort(nums);
        for (int i = nums.length - 1; i > 0; i--){
            count++;
            if (nums[i-1] != nums[i]){
                ans += count;
            }
        }
        return ans;
    }
}

//The code below implement a data structure TreeMap, which is very slow but use for logic
// public class ReductionOperationsToMakeTheArrayElementsEqual{
//     TreeMap<Integer, Integer> occurrenceMap;
//     ReductionOperationsToMakeTheArrayElementsEqual(int[] array) {
//         this.occurrenceMap = new TreeMap<>(Comparator.reverseOrder());
//         for (int i = 0; i < array.length; i++) {
//             occurrenceMap.put(array[i], occurrenceMap.getOrDefault(array[i], 0) + 1);
           
//         }
//         occurrenceMap.pollLastEntry();
//     }
//     int answer(){
//         int ans = 0;
//         int prevValue = 0;
//         for (Map.Entry<Integer,Integer> entry: occurrenceMap.entrySet()){
//             int value = entry.getValue() + prevValue;
//             ans += value;
//             prevValue += entry.getValue();
//             System.out.println("ans:" + ans);
//             System.out.println(entry.getKey() + "/" + entry.getValue());
//         }
//         return ans;
//     }
  
//     public int reductionOperations(int[] nums) {
//         ReductionOperationsToMakeTheArrayElementsEqual upq = new ReductionOperationsToMakeTheArrayElementsEqual(nums);
//         return upq.answer(); 
//     }
//     public static void main(String[] args) {
//         int[] array = {1,2,2,2,3,3,4,4};
         
//         ReductionOperationsToMakeTheArrayElementsEqual upq = new ReductionOperationsToMakeTheArrayElementsEqual(array);
//         System.out.println(upq.answer());
//     }
// }