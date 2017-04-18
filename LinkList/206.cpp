/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL){
        return head;
    }
    struct ListNode *pre = head;
    struct ListNode *node = head->next;
    pre->next = NULL;
    while(node!=NULL){
        struct ListNode *preTem = node;
        struct ListNode *nodeTem = node->next;
        node->next = pre;
        pre = preTem;
        node = nodeTem;
    }
    return pre;
}
