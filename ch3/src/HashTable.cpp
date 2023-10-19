#include "HashTable.h"
// add up ascii of each character, then mode table size
int HashTable::hash(const std::string& key){
    int hash_value = 0;
    for (char c : key) {
        hash_value += c;
    }
    return hash_value % table_size_;
}
// put the key into the list of the index returned by hash function
void HashTable::insert(const std::string& key) {
    int index = hash(key);
    for (const std::string& item : table[index]) {
        if (item == key) {
            return;
        }
    }
    table[index].emplace_back(key);
}
// count the number of items by iterating the table
int HashTable::size() {
    int cnt = 0;
    for (const std::list<std::string>& item : table) {
        cnt += item.size();
    }
    return cnt;
}