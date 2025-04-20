//Given an array arr[] of size n, filled with numbers from 1 to n-1 in random order. 
//The array has only one repetitive element. Your task is to find the repetitive element.

//Note: It is guaranteed that there is a repeating element present in the array.

//Examples:

//Input: arr[] = [1, 3, 2, 3, 4]
//Output: 3 
//Explanation: The number 3 is the only repeating element.


class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0];
        int fast = arr[0];
        
        // Phase 1: Find intersection point in the cycle
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);
        
        // Phase 2: Find entrance to the cycle (duplicate element)
        slow = arr[0];
        while (slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }
        
        return slow;
    }
};


