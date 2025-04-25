//Given an array arr[]. Find the majority element in the array. If no majority element exists, return -1.

//Note: A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.


class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int count = 0;
        int candidate = -1;
        
        // Step 1: Find candidate
        for (int num : arr) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        // Step 2: Verify candidate
        count = 0;
        for (int num : arr) {
            if (num == candidate) count++;
        }
        
        return (count > arr.size() / 2) ? candidate : -1;
    }
};
