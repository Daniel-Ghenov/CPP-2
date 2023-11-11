#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


struct Node{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;

}nodes[(int) 1e7];

class Solution{
private:
    std::vector<int> sizes;
    int maxSize = 0;
public:

    int getMaxPainting(Node* root){
        if(root == nullptr){
            return 0;
        }

        getSizes(root, 0);
        getMaxPainting(root, 0);
        return maxSize;
    }

private:

    int getSizes(Node* root, int idx){
        if(root == nullptr){
            return 0;
        }
        if(idx > sizes.size()){
            sizes.resize(idx * 2);
        }
        int left = getSizes(root->left, idx * 2 + 1);
        int right = getSizes(root->right, idx * 2 + 2);

        sizes[idx] = right + left + 1;
        return left + right + 1;
    }

    void getMaxPainting(Node* root, int idx){
        if(root == nullptr){
            return;
        }

        int left = idx * 2 + 1 > sizes.size() ? 1 : sizes[idx * 2 + 1];
        int right = idx * 2 + 2 > sizes.size() ? 1 : sizes[idx * 2 + 2];

        int parent = 1;
        if(idx % 2 && parent != 0){
            parent = sizes[idx / 2] - sizes[idx];
        }else{
            parent = sizes[idx / 2 - 1] - sizes[idx];
        }
        if(left * right * parent > maxSize){
            maxSize = left * right * parent;
        }
        getMaxPainting(root->left, idx * 2 + 1);
        getMaxPainting(root->left, idx * 2 + 2);
    }

};



int main() {
    Solution sol;
    size_t n;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        nodes[i].value = i;
        size_t left, right;
        std::cin >> left >> right;

        if(left == -1){
            nodes[i].left = nullptr;
        }else{
            nodes[i].left = &nodes[left];
        }
        if(right == -1){
            nodes[i].right = nullptr;
        }else{
            nodes[i].right = &nodes[right];
        }

    }

    std::cout<<sol.getMaxPainting(&nodes[0]);

    return 0;
}