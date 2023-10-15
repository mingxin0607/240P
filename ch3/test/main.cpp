#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <set>

void test1() {
    std::cout << "----------test1-----------" << std::endl;
    HashTable hash_table(20);
    hash_table.insert("abc");
    hash_table.insert("asbc");
    hash_table.insert("aabc");
    std::cout << hash_table.size() << std::endl;
    hash_table.insert("anbc");
    hash_table.insert("aabc");
    std::cout << hash_table.size() << std::endl;
}

void test2() {
    std::cout << "----------test2-----------" << std::endl;
    // std::ifstream file("test.txt");
    std::ifstream file("pride-and-prejudice.txt");
    // int cnt = 0;
    HashTable hash_table(2 ^ 16);
    std::set<std::string> st;
    if (!file.is_open()) {
        std::cerr << "Failed to open file.\n";
        return; 
    }
    std::string line;
    while (std::getline(file, line)) {

        std::string word;

        for (char c : line) {
            if (std::isalpha(c) || std::isdigit(c)) {
                word += std::tolower(c);
            }
            else if (!word.empty()) {
                std::sort(word.begin(), word.end());
                // cnt++;
                // st.insert(word);
                hash_table.insert(word);
                word.clear();
            }
        }

        if (!word.empty()) {
            std::sort(word.begin(), word.end());
            // cnt++;
            // st.insert(word);
            hash_table.insert(word);
        }
    }
    // std::cout << cnt << std::endl;
    // std::cout << st.size() << std::endl;
    std::cout << hash_table.size() << std::endl;

    // int count = 0;
    // for (const std::string& word : st) {
    //     if (count < 400) {
    //         std::cout << word << " ";
    //         count++;
    //     } else {
    //         break; // Exit the loop after printing 40 words
    //     }
    // }
}

int main() {
    test1();
    test2();
}