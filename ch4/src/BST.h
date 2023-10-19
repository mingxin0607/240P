#include <string>
#include <iostream>
// data structure of information of students
struct StuInfo{
    std::string number;
    std::string last_name;
    std::string home_department;
    std::string program;
    std::string year;
};

// data structure of tree node
struct Node{
    StuInfo stu_info;
    Node *right;
    Node *left;
    Node(StuInfo stu_info_):stu_info(stu_info_), right(nullptr), left(nullptr){};
};

class BST{
    private:
    Node *root;
    // insert a new node to BST
    Node* backtrack_insert(Node *root, Node *new_node);
    // traverse from node root, output to a file
    void backtrack_traverse(Node *root, std::ofstream&);
    public:
    BST():root(nullptr){};
    // insert a new record
    void insert(StuInfo stu_info);
    // traverse and output to a certain file
    void in_order_traverse();
    // traverse and output to a certain file
    void level_traverse();
};