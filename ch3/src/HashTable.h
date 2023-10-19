#include <iostream>
#include <vector>
#include <list>
#include <string>

class HashTable{
    private:
        // size of the vector
        int table_size_;
        // 2 dimensional vector
        std::vector<std::list<std::string>> table;

    public:
        HashTable(int size) {
            table.resize(size);
            table_size_ = size;
        }
        // hash function that converts a string x to index in the hashtable
        int hash(const std::string& key);
        // Insert string x to the HashTable in the index returned by hash(x).
        void insert(const std::string& key);
        // Returns the number of keys.
        int size();
};