class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstIdx = -1, prevIdx = -1, idx = 1;
        ListNode* prev = head;
        ListNode* cur = head->next;
        int minDist = INT_MAX;
        
        while (cur->next != nullptr) {
            idx++;
            bool isMax = cur->val > prev->val && cur->val > cur->next->val;
            bool isMin = cur->val < prev->val && cur->val < cur->next->val;
            
            if (isMax || isMin) {
                if (firstIdx == -1) {
                    firstIdx = idx;
                } else {
                    minDist = min(minDist, idx - prevIdx);
                }
                prevIdx = idx;
            }
            
            prev = cur;
            cur = cur->next;
        }
        
        if (firstIdx == -1 || firstIdx == prevIdx) {
            return {-1, -1};
        }
        
        int maxDist = prevIdx - firstIdx;
        return {minDist, maxDist};
    }
};