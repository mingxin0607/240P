#include <string>
#include <iostream>

struct StuInfo{
    std::string number;
    std::string last_name;
    std::string home_department;
    std::string program;
    std::string year;
};

struct Node{
    StuInfo stu_info;
    Node *right;
    Node *left;
    Node(StuInfo stu_info_):stu_info(stu_info_), right(nullptr), left(nullptr){};
};

class BST{
    private:
    Node *root;
    Node* backtrack_insert(Node *root, Node *new_node);
    void backtrack_traverse(Node *root, std::ofstream&);
    public:
    BST():root(nullptr){};
    void insert(StuInfo stu_info);
    void in_order_traverse();
    void level_traverse();
};