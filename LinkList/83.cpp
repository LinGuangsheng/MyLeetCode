/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        return head;
    }
    struct ListNode *node = head->next;
    struct ListNode *pre = head;
    while(node){
        if(node->val==pre->val){
            node = node->next;
            pre->next = node;
        }
        else{
            node = node->next;
            pre = pre->next;
        }
    }
    return head;
}
