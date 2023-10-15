#include <iostream>
#include <vector>
#include <list>
#include <string>

class HashTable{
    private:
        int table_size_;
        std::vector<std::list<std::string>> table;

    public:
        HashTable(int size) {
            table.resize(size);
            table_size_ = size;
        }

        int hash(const std::string& key);

        void insert(const std::string& key);

        int size();
};