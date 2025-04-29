//Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only.
//Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;
        
        // Dummy nodes for 0s, 1s, and 2s
        Node* zeroD = new Node(0);
        Node* oneD = new Node(0);
        Node* twoD = new Node(0);
        
        // Current tails of the lists
        Node* zero = zeroD, *one = oneD, *two = twoD;
        
        // Traverse original list and attach nodes to corresponding lists
        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }
        
        // Connect the three lists
        zero->next = oneD->next ? oneD->next : twoD->next;
        one->next = twoD->next;
        two->next = nullptr; // End the list

        Node* newHead = zeroD->next;

        // Free dummy nodes
        delete zeroD;
        delete oneD;
        delete twoD;

        return newHead;
    }
};
