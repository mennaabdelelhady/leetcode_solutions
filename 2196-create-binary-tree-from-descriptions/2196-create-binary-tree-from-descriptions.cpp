/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Map to store all nodes by their values
        unordered_map<int, TreeNode*> nodeMap;
      
        // Set to track all nodes that are children (have a parent)
        unordered_set<int> childNodes;
      
        // Process each parent-child relationship description
        for (const auto& description : descriptions) {
            int parentVal = description[0];
            int childVal = description[1];
            bool isLeftChild = description[2];
          
            // Create parent node if it doesn't exist
            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
          
            // Create child node if it doesn't exist
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }
          
            // Connect child to parent based on left/right position
            if (isLeftChild) {
                nodeMap[parentVal]->left = nodeMap[childVal];
            } else {
                nodeMap[parentVal]->right = nodeMap[childVal];
            }
          
            // Mark this node as a child
            childNodes.insert(childVal);
        }
      
        // Find and return the root node (node that is not a child of any other node)
        for (const auto& [nodeVal, nodePtr] : nodeMap) {
            if (childNodes.find(nodeVal) == childNodes.end()) {
                return nodePtr;
            }
        }
      
        // Return nullptr if no root found (shouldn't happen with valid input)
        return nullptr;
    }
};