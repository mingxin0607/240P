#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"

int main() {
    BST bst;
    std::string filename = "tree-input.txt"; 

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(file, line)) {
        // std::cout << line << std::endl;
        StuInfo stu_info = {line.substr(1,7), line.substr(8,25), line.substr(33,4), line.substr(37,4), line.substr(41,1)};
        // std::cout << stu_info.number << " " << stu_info.home_department << " " << stu_info.last_name << std::endl;
        bst.insert(stu_info);
    }
    file.close();

    std::cout << "in order traverse" << std::endl;
    // bst.in_order_traverse();

    std::cout << "level traverse" << std::endl;
    // bst.level_traverse();

    return 0;
}
