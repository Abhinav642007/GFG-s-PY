/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        // if(head==NULL || head->next==NULL) return NULL;
        
        Node* temp = head;
        
        while(temp != NULL && temp->next !=NULL){
            Node* nextNode=temp->next;
            while(nextNode!=NULL && nextNode->data==temp->data){
                nextNode=nextNode->next;
            }
            temp->next=nextNode;
            if(nextNode) nextNode->prev=temp;
            temp=temp->next;
        }
        return head;
    }
};