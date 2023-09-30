#include <string>

struct AccountInfo{
    std::string name;    // Name 
    std::string address;  //  Address
    std::string social_security;   // Social Security
    double deposit;    // deposit amount. 
};

struct AccountListNode { // data structure of account listnode
    int account_id_;
    AccountInfo account_info_;
    AccountListNode *next;
};

class BOC{
    private:
        AccountListNode* dummy_head; // head pointer of account listnode

    public:
        BOC(){
            dummy_head = new AccountListNode();
            dummy_head->next = nullptr;
            // dummy_head->account_id_ = 0;
        };
        int addUser(AccountInfo account_info);
        bool deleteUser(int user_id);
        bool payUserToUser(int payer_id, int payee_id, double amount);
        int getMedianID();
        bool mergeAccounts(int id1, int id2);
        void printInfo();
        void mergeBanks(BOC bola);
};