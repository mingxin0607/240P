#include "Heap.h"

void HeapBuilder::heapify(std::vector<int>& arr, int index, bool isMaxHeap) {
    int size = arr.size();
    int most = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (isMaxHeap) {
        if (left < size && arr[left] > arr[most]) {
            most = left;
        }
        if (right < size && arr[right] > arr[most]) {
            most = right;
        }
    } else {
        if (left < size && arr[left] < arr[most]) {
            most = left;
        }
        if (right < size && arr[right] < arr[most]) {
            most = right;
        }
    }

    if (most != index) {
        std::swap(arr[index], arr[most]);
        heapify(arr, most, isMaxHeap);
    }
}

void HeapBuilder::buildHeap(std::vector<int>& arr, bool isMaxHeap) {
    int size = arr.size();

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, i, isMaxHeap);
    }
}

Node* HeapBuilder::buildBinaryTree(std::vector<int>& arr, int index) {
    if (index < arr.size()) {
        Node* newNode = new Node(arr[index]);
        newNode->left = buildBinaryTree(arr, 2 * index + 1);
        newNode->right = buildBinaryTree(arr, 2 * index + 2);
        return newNode;
    } else {
        return nullptr;
    }
}

Node* HeapBuilder::buildMaxHeap(std::vector<int>& arr) {
    buildHeap(arr, true);
    root = buildBinaryTree(arr, 0);
    return root;
}

Node* HeapBuilder::buildMinHeap(std::vector<int>& arr) {
    buildHeap(arr, false);
    root = buildBinaryTree(arr, 0);
    return root;
}

void HeapBuilder::printTree(Node* node) {
    if (node == nullptr){
        return;
    }
    std::queue<Node*> que;
    que.push(root);
    while(que.size()) {
        int sz = que.size();
        while(sz--){
            Node * tmp = que.front();
            que.pop();
            std::cout << tmp->data << " ";
            if (tmp->left) {
                que.push(tmp->left);
            }
            if(tmp->right) {
                que.push(tmp->right);
            }

        }
        std::cout << std::endl;
    }
}