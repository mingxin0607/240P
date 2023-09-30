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
        // initiate dummy_head of linked list
        BOC(){
            dummy_head = new AccountListNode();
            dummy_head->next = nullptr;
            // dummy_head->account_id_ = 0;
        };

        // add a new user with account info
        int addUser(AccountInfo account_info);

        //delete user by the user id, return false if action failed
        bool deleteUser(int user_id);

        // transfer money from one account to another, return false if action failed
        bool payUserToUser(int payer_id, int payee_id, double amount);

        // get the median accound id at present
        int getMedianID();

        // merge two account with same name, address and ssn together
        // return false if action failed
        bool mergeAccounts(int id1, int id2);

        // print the current linked list
        void printInfo();

        // merge another bank's account list to the object's account list
        void mergeBanks(BOC bola);
};