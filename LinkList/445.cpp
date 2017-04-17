/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int l1Length = 0;
    struct ListNode *tem1 = l1;
    while(tem1!=NULL){
        tem1=tem1->next;
        l1Length++;
    }
    
    int l2Length = 0;
    struct ListNode *tem2 = l2;
    while(tem2!=NULL){
        tem2=tem2->next;
        l2Length++;
    }
    
    int length = 0;
    struct ListNode *lenNode;
    struct ListNode *anotherNode;
    if(l1Length>l2Length){
        length=l1Length;
        lenNode = l1;
        anotherNode = l2;
    }
    else{
        length=l2Length;
        lenNode = l2;
        anotherNode = l1;
    }
    
    struct ListNode *resultListNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    resultListNode->val = 0;
    struct ListNode *resultTem = resultListNode;
    for(int i=0;i<length;i++){
        struct ListNode *resultTem2 = (struct ListNode*)malloc(sizeof(struct ListNode));
        resultTem2->val = 0;
        resultTem->next = resultTem2;
        resultTem = resultTem2;
        resultTem->next=NULL;
        
    }
    struct ListNode *now = (struct ListNode*)malloc(sizeof(struct ListNode));
    now = resultListNode->next;
    struct ListNode *before = (struct ListNode*)malloc(sizeof(struct ListNode));
    before = resultListNode;
    int flag = 0;
    for(int i=0;i<length;i++){
        if(i<abs(l1Length-l2Length)){
            now->val = lenNode->val;
            now = now->next;
            before = before->next;
            lenNode = lenNode->next;
        }
        else{
            now->val = lenNode->val + anotherNode->val;
            if(now->val>=10){
                before->val = before->val+1;
                if(before->val>=10){
                    flag = 1;
                }
                now->val = now->val-10;
            }
            now = now->next;
            before = before->next;
            lenNode = lenNode->next;
            anotherNode = anotherNode->next;
        }
    }
    while(flag){
        flag = 0;
        now = resultListNode->next;
        before = resultListNode;
        while(now!=NULL){
            if(now->val>=10){
                before->val = before->val+1;
                now->val = now->val - 10;
                if(before->val>=10){
                    flag = 1;
                }
            }
            now = now->next;
            before=before->next;
        }
    }
    while(resultListNode->val==0&&resultListNode->next!=NULL){
        resultListNode = resultListNode->next;
    }
    return resultListNode;
}
