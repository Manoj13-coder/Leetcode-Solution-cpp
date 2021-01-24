class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> res;
        if (lists.empty())
            return nullptr;
        bool value = false;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i]) {
                ListNode* temp = lists[i];
                value = true;
                while (temp)
                {
                    res.push_back(temp->val);
                    temp = temp->next;
                }
            }
        }
        if (value) {
            sort(res.begin(), res.end());
            ListNode *head = new ListNode(res[0]);
            ListNode* temp = head;
            for (int i = 1; i < res.size(); i++)
            {
                ListNode *temp1 = new ListNode(res[i]);
                temp->next = temp1;
                temp = temp1;
            }
            return head;
        }
        return nullptr;
    }
};