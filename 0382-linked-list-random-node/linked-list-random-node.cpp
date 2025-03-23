/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* headMain;
public:
    Solution(ListNode* head) {
        headMain = head;
    }
    
    int getRandom() {
        int i=0;
        int ans=0;
        ListNode* temp = headMain;
        while(temp!=nullptr){
            i++;
            int random = rand() % i;
            if(random == i-1){
                ans = temp->val;
            }
            temp = temp->next;
        }
        return ans;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */