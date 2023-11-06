import java.util.PriorityQueue;

public class SeatManager {
    private int last;
    private PriorityQueue<Integer> pq;

    public SeatManager(int n) {
        this.last = 0;
        this.pq = new PriorityQueue<>();
    }

    public int reserve() {
        if (pq.isEmpty()) {
            return ++last;
        } else {
            return pq.poll();
        }
    }

    public void unreserve(int seatNumber) {
        if (seatNumber == last) {
            --last;
        } else {
            pq.add(seatNumber);
        }
    }
}
// Time complexity:

// reserve: Average O(1) (when using the counter), but O(log⁡n) (when using the min-heap).
// unreserve: O(log⁡n) (due to the min-heap operation).
// Space complexity: O(n). This is the worst-case scenario where all seats have been reserved and then unreserved, filling up the min-heap.
//seat-reservation-manager.java

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.reserve();
 * obj.unreserve(seatNumber);
 */