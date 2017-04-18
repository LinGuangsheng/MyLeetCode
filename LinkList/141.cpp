/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL){
        return false;
    }
    struct ListNode *fastNode = head->next;
    struct ListNode *slowNode = head->next;
    int flag = 0;
    while(slowNode){
        if(fastNode){
            fastNode = fastNode->next;
            if(fastNode){
                fastNode = fastNode->next;
                flag = 1;
            }
        }
        if(slowNode){
            slowNode = slowNode->next;
        }
        if(slowNode==fastNode&&flag){
            return true;
        }
        if(slowNode==NULL||fastNode==NULL){
            return false;
        }
    }
    return false;
}
