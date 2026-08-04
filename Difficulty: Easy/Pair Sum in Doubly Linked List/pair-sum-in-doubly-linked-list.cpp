class Solution {
public:
    // Function to find the last node (tail) of DLL
    Node* findTail(Node* head) {
        Node* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
        }

        return tail;
    }

    vector<vector<int>> givenSumPairs(Node* head, int target) {

        vector<vector<int>> ans;

        if (head == NULL) return ans;

        Node* left = head;
        Node* right = findTail(head);

        // Continue until pointers meet or cross
        while (left != right && left->prev != right) {

            int sum = left->data + right->data;

            if (sum == target) {
                ans.push_back({left->data, right->data});

                // Move both pointers
                left = left->next;
                right = right->prev;
            }
            else if (sum < target) {
                // Need a bigger sum
                left = left->next;
            }
            else {
                // Need a smaller sum
                right = right->prev;
            }
        }

        return ans;
    }
};