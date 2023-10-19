#include "Heap.h"
#include "BSTToHeap.h"
#include <cstdlib>



void test2() {
    std::cout << "------test2------" << std::endl;
    BST bst;
    int data_len = 30;
    std::vector<int> data(data_len);
    for (int i = 0; i < data_len; i++) {
        data[i] = std::rand() % 100;
        bst.insert(data[i]);
    }
    
    BSTToHeapTransformer transformer(bst.root);

    TreeNode* minHeapRoot = transformer.convertToMinHeap();
    TreeNode* maxHeapRoot = transformer.convertToMaxHeap();

    std::cout << "Original BST:" << std::endl;
    bst.level_traverse();

    std::cout << "Min-Heap:" << std::endl;
    transformer.printTree(minHeapRoot);
    std::cout << std::endl;

    std::cout << "Max-Heap:" << std::endl;
    transformer.printTree(maxHeapRoot);
    std::cout << std::endl;

}

void test1(){
    std::cout << "------test1------" << std::endl;
    int data_len = 30;
    std::vector<int> data(data_len);
    for (int i = 0; i < data_len; i++) {
        data[i] = std::rand() % 100;
    }

    HeapBuilder maxHeapBuilder;
    Node* maxHeapRoot = maxHeapBuilder.buildMaxHeap(data);

    std::cout << "MaxHeap Binary Tree:" << std::endl;
    maxHeapBuilder.printTree(maxHeapRoot);
    std::cout << std::endl;

    HeapBuilder minHeapBuilder;
    Node* minHeapRoot = minHeapBuilder.buildMinHeap(data);

    std::cout << "MinHeap Binary Tree:" << std::endl;
    minHeapBuilder.printTree(minHeapRoot);
    std::cout << std::endl;

}

int main() {
    test1();
    test2();
    return 0;
}