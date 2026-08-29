/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertNodeInBetween(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* nextElement = temp->next;
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = nextElement;
        }
    }

    void connectRandomPointers(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copyNode = temp->next;

            if(temp->random){
                copyNode->random = temp->random->next;
            }else{
                copyNode->random = nullptr;
            }

            temp = temp->next->next;
        }
    }

    Node* getDeepCopy(Node* head){
        Node* temp = head;
        Node* dNode = new Node(-1);
        Node* res = dNode;
        while(temp!=NULL){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dNode->next;
    }
    
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }

        insertNodeInBetween(head);
        connectRandomPointers(head);
        return getDeepCopy(head);
    }
};