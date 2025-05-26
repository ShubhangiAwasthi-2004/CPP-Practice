// Given a sorted circular linked list, the task is to insert a new node 
// in this circular linked list so that it remains a sorted circular linked list.

// Input: head = 1->4->7->9, data = 5
// Output: 1->4->5->7->9
// Explanation: We can add 5 after the second node.

// Constraints:
// 2 <= number of nodes <= 106
// 0 <= node->data <= 106
// 0 <= data <= 106


class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);

        // Case 1: List is empty (though by constraints this may not happen)
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }

        Node* current = head;

        while (true) {
            // Case 2: Insert between two nodes
            if (current->data <= data && data <= current->next->data) {
                break;
            }

            // Case 3: Current is the largest and wraps around to the smallest
            if (current->data > current->next->data) {
                if (data >= current->data || data <= current->next->data) {
                    break;
                }
            }

            current = current->next;

            // If we've completed a full circle
            if (current == head) {
                break;
            }
        }

        // Insert newNode between current and current->next
        newNode->next = current->next;
        current->next = newNode;

        // If inserted before the head (new minimum), update head
        if (data < head->data) {
            return newNode;
        }

        return head;
    }
};

