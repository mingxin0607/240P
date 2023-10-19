#include <string>
#include <iostream>

struct TreeNode{
    int data;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int val):data(val), right(nullptr), left(nullptr){};
};

class BST{
    private:
    TreeNode* backtrack_insert(TreeNode *root, TreeNode *new_node);
    // void backtrack_traverse(Node *root, std::ofstream&);
    public:
    TreeNode *root;
    BST():root(nullptr){};
    void insert(int data);
    // void in_order_traverse();
    void level_traverse();
};