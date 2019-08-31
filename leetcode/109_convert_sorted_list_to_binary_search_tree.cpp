/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> element_list;
    
    TreeNode* convertListToBST(int left, int right){
        // recursive
        if(left > right){
            return NULL;
        }
        int middle = (left + right) / 2;
        ListNode *tmp = element_list[middle];
        TreeNode *node = new TreeNode(tmp->val);
        node->left = convertListToBST(left, middle-1);
        node->right = convertListToBST(middle+1, right);
        
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        // invalid case
        if(!head){
            return NULL;
        }
        // make the element_list
        TreeNode *root;
        ListNode *tmp;
        tmp = head;
        while(tmp){
            element_list.push_back(tmp);
            tmp = tmp->next;
        }
        // only one element left in the element_list
        if(element_list.size() == 1){
            root = new TreeNode(head->val);
            return root;
        }
        // form the root
        root = convertListToBST(0, element_list.size()-1); 
        return root;
    }
};
