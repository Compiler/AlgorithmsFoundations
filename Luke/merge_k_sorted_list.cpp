
class Solution {
public:

    void collect(std::priority_queue<int, vector<int>, std::greater<int>>& collection, ListNode* root) {
        if(!root) return;
        collection.push(root->val);
        collect(collection, root->next);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<int, vector<int>, std::greater<int>> queue;

        for(auto& node : lists) {
            collect(queue, node);
        }

        if(queue.empty()) return nullptr;
        ListNode* root = new ListNode(queue.top());
        queue.pop();
        ListNode* rootCpy = root;
        while(!queue.empty()){
            rootCpy->next = new ListNode(queue.top());
            queue.pop();
            rootCpy = rootCpy->next;
        }
        return root;

        
    }
};

