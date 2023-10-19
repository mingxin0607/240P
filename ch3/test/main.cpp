#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <set>
// test the functions in class  HashTable
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
// read from txt file, then use HashTable to count numbers of unique anagram-root words
void test2() {
    std::cout << "----------test2-----------" << std::endl;
    // std::ifstream file("test.txt");
    std::ifstream file("pride-and-prejudice.txt");

    HashTable hash_table(2 ^ 16);
    // std::set<std::string> st;
    if (!file.is_open()) {
        std::cerr << "Failed to open file.\n";
        return; 
    }
    std::string line;
    // read by line
    while (std::getline(file, line)) {

        std::string word;

        for (char c : line) {
            // letters and digits are counted as part of a word
            if (std::isalpha(c) || std::isdigit(c)) { 
                word += std::tolower(c);
            }
            else if (!word.empty()) { // end of a word
                std::sort(word.begin(), word.end());
                // st.insert(word);
                hash_table.insert(word);
                word.clear();
            }
        }
        // process the last word in line
        if (!word.empty()) {
            std::sort(word.begin(), word.end());
            // st.insert(word);
            hash_table.insert(word);
        }
    }

    // output numbers of unique anagram-root words
    std::cout << hash_table.size() << std::endl;
}

int main() {
    test1();
    test2();
}