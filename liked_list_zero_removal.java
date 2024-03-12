import java.util.HashMap;

/**
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
 */


class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        // Create a dummy node to simplify edge cases
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        // Use a HashMap to store running sums and their corresponding nodes
        HashMap<Integer, ListNode> map = new HashMap<>();
        int sum = 0;

        ListNode current = dummy;

        while (current != null) {
            sum += current.val;

            // If the sum is already in the map, skip the subarray by updating the next pointer
            if (map.containsKey(sum)) {
                current = map.get(sum).next;
                int tempSum = sum + current.val;

                // Remove entries in the map with sum values between the original sum and the new sum
                while (tempSum != sum) {
                    map.remove(tempSum);
                    current = current.next;
                    tempSum += current.val;
                }

                // Update the next pointer of the previous node
                map.get(sum).next = current.next;
            } else {
                // If the sum is not in the map, add it with the current node
                map.put(sum, current);
            }

            current = current.next;
        }

        return dummy.next;
    }
}
