/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {

        // code here
        Node* temp=head;
        while(temp){
            if(temp->data==x){
                if(temp==head){
                    head=head->next;
                }
                Node* nextNode=temp->next;
                Node* prevNode=temp->prev;
                
                if(nextNode) nextNode->prev=prevNode;
                if(prevNode) prevNode->next=nextNode;
                free(temp);
                temp=nextNode;
            }
            else{
                temp=temp->next;
                
            }
            
        }
        return head;
    }
};