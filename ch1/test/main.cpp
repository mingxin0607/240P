#include "iostream"
#include "BOC.h"
void test1(){
    std::cout << "--------test1--------" << std::endl;
    BOC boc;
    AccountInfo account1 = {"u1", "address1", "ssn1", 500};
    AccountInfo account2 = {"u2", "address2", "ssn2", 100};
    AccountInfo account3 = {"u3", "address3", "ssn3", 3000};
    boc.addUser(account1);
    boc.addUser(account2);
    boc.addUser(account3);
    boc.printInfo();

}

void test2(){
    std::cout << "--------test2--------" << std::endl;
    BOC boc;
    AccountInfo account1 = {"u1", "address1", "ssn1", 500};
    AccountInfo account2 = {"u2", "address2", "ssn2", 100};
    AccountInfo account3 = {"u3", "address3", "ssn3", 3000};
    AccountInfo account4 = {"u4", "address4", "ssn4", 200};
    AccountInfo account5 = {"u5", "address5", "ssn5", 2000};
    AccountInfo account6 = {"u6", "address6", "ssn6", 400};
    AccountInfo account7 = {"u7", "address7", "ssn7", 800};
    int id1 = boc.addUser(account1);
    int id2 = boc.addUser(account2);
    int id3 = boc.addUser(account3);
    int id4 = boc.addUser(account4);
    boc.deleteUser(id2);
    boc.printInfo();

    boc.addUser(account5);
    int id6 = boc.addUser(account6);
    boc.deleteUser(id1);
    boc.printInfo();

    boc.addUser(account7);
    boc.printInfo();

    boc.deleteUser(id6);
    boc.printInfo();
}

void test3(){
    std::cout << "--------test3--------" << std::endl;
    BOC boc;
    AccountInfo account1 = {"u1", "address1", "ssn1", 500};
    AccountInfo account2 = {"u2", "address2", "ssn2", 100};
    AccountInfo account3 = {"u3", "address3", "ssn3", 3000};
    int id1 = boc.addUser(account1);
    int id2 = boc.addUser(account2);
    int id3 = boc.addUser(account3);
    boc.printInfo();

    boc.payUserToUser(id3, id1, 2000);
    boc.printInfo();

    boc.payUserToUser(id2, id1, 2000);
    boc.printInfo();

    boc.deleteUser(id2);
    boc.payUserToUser(id1, id2, 2000);
    boc.printInfo();
}

void test4(){
    std::cout << "--------test4--------" << std::endl;
    BOC boc;
    AccountInfo account1 = {"u1", "address1", "ssn1", 500};
    AccountInfo account2 = {"u2", "address2", "ssn2", 100};
    AccountInfo account3 = {"u3", "address3", "ssn3", 3000};
    AccountInfo account4 = {"u4", "address4", "ssn4", 200};
    AccountInfo account5 = {"u5", "address5", "ssn5", 2000};
    AccountInfo account6 = {"u6", "address6", "ssn6", 400};
    AccountInfo account7 = {"u7", "address7", "ssn7", 800};
    int id1 = boc.addUser(account1);
    int id2 = boc.addUser(account2);
    int id3 = boc.addUser(account3);
    int id4 = boc.addUser(account4);
    boc.deleteUser(id2);
    std::cout << "median id: " << boc.getMedianID() << std::endl;
    boc.printInfo();

    boc.addUser(account5);
    int id6 = boc.addUser(account6);
    boc.deleteUser(id1);
    std::cout << "median id: " << boc.getMedianID() << std::endl;
    boc.printInfo();

    boc.addUser(account7);
    std::cout << "median id: " << boc.getMedianID() << std::endl;
    boc.printInfo();

    boc.deleteUser(id6);
    std::cout << "median id: " << boc.getMedianID() << std::endl;
    boc.printInfo();
}

void test5(){
    std::cout << "--------test5--------" << std::endl;
    BOC boc;
    AccountInfo account1 = {"u1", "address1", "ssn1", 500};
    AccountInfo account2 = {"u2", "address2", "ssn2", 100};
    AccountInfo account3 = {"u1", "address1", "ssn1", 3000};
    AccountInfo account4 = {"u2", "address2", "ssn2", 400};
    AccountInfo account5 = {"u2", "address2", "ssn5", 500};
    int id1 = boc.addUser(account1);
    int id2 = boc.addUser(account2);
    int id3 = boc.addUser(account3);
    int id4 = boc.addUser(account4);
    int id5 = boc.addUser(account5);
    boc.printInfo();

    boc.mergeAccounts(id1, id3);
    boc.printInfo();

    boc.mergeAccounts(id4, id2);
    boc.printInfo();

    boc.mergeAccounts(id2, id5);
    boc.printInfo();

}

void test6(){
    std::cout << "--------test6--------" << std::endl;
    BOC boc;
    BOC bola;
    AccountInfo account1 = {"u1", "address1", "ssn1", 1000};
    AccountInfo account2 = {"u2", "address2", "ssn2", 200};
    AccountInfo account3 = {"u3", "address3", "ssn3", 3000};
    AccountInfo account4 = {"u4", "address4", "ssn4", 400};
    AccountInfo account5 = {"u5", "address5", "ssn5", 500};
    boc.addUser(account1);
    int id1 = boc.addUser(account2);
    boc.addUser(account3);
    int id2 = boc.addUser(account4);
    boc.addUser(account5);
    boc.deleteUser(id1);
    boc.deleteUser(id2);
    boc.printInfo();

    int id4 = bola.addUser(account1);
    bola.addUser(account2);
    bola.addUser(account3);
    int id3 = bola.addUser(account4);
    bola.addUser(account5);
    bola.deleteUser(id3);
    bola.deleteUser(id4);
    bola.printInfo();

    boc.mergeBanks(bola);
    boc.printInfo();
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}