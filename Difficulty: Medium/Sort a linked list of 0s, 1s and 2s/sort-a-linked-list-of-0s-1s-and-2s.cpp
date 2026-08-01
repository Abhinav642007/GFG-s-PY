/*
class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
*/

class Solution {
public:
    Node* segregate(Node* head) {

        // Dummy nodes for 0, 1 and 2 lists
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);

        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;

        Node* curr = head;

        // Divide nodes into three lists
        while (curr != NULL) {

            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            }
            else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            }
            else {
                two->next = curr;
                two = two->next;
            }

            curr = curr->next;
        }

        // Connect the three lists
        zero->next = (oneHead->next != NULL) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;

        // New head
        Node* newHead = zeroHead->next;

        // Delete dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};