class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;

        while(f != nullptr && f->next != nullptr)
        {
            s = s->next;
            f = f->next->next;
        }

        ListNode* curr = s;
        ListNode* prev = nullptr;

        while(curr != nullptr)
        {
            ListNode* nn = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nn;
        }

        int maxsum = 0;
        ListNode* fh = head;
        ListNode* sh = prev;

        while(sh != nullptr)
        {
                maxsum = max(maxsum, fh->val + sh->val);
                fh = fh->next;
                sh = sh->next;
        }
        return maxsum;
    }
};