#include <iostream>
#include <vector>
#include <queue>
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};


class HeapBuilder {
private:
    Node* root;
    // maintain the property of heap
    void heapify(std::vector<int>& arr, int index, bool isMaxHeap);
    // transfer an array into a heap
    // could build either maxheap or minheap using parameter isMxHeap
    void buildHeap(std::vector<int>& arr, bool isMaxHeap);
    // build binary tree from an array
    Node* buildBinaryTree(std::vector<int>& arr, int index);

public:
    HeapBuilder() : root(nullptr) {}
    // build a maxheap from an array
    Node* buildMaxHeap(std::vector<int>& arr);
    // build a minheap from an array
    Node* buildMinHeap(std::vector<int>& arr);
    // print tree using level-order traverse
    void printTree(Node* node);
};

