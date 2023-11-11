#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


struct Node{
    long long value = 0;
    Node* left = nullptr;
    Node* right = nullptr;

}nodes[(int) 1e6];

int sizes[(int) 1e6];


class Solution{
private:
    long long maxSize = 0;
public:

    long long getMaxPainting(Node* root){
        if(root == nullptr){
            return 0;
        }

        getSizes(root);
        getMaxPaintingRecurs(root);
        return maxSize;
    }


private:

    long long getSizes(Node* root){
        if(root == nullptr){
            return 0;
        }

        long long left = getSizes(root->left);
        long long right = getSizes(root->right);

        sizes[root->value] = right + left + 1;
        return left + right + 1;
    }

    void getMaxPaintingRecurs(Node* root){
        if(root == nullptr){
            return;
        }
        long long left = 1, right = 1;
        if(root->left){
            left = std::max(1 , sizes[root->left->value]);
        }

        if(root->right){
            right = std::max(1 , sizes[root->right->value]);

        }
        long long parent = std::max(1, sizes[0] - sizes[root->value]);


        if(left * right * parent > maxSize){
            maxSize = left * right * parent;
        }
        getMaxPaintingRecurs(root->left);
        getMaxPaintingRecurs(root->right);
    }

};



int main() {
    Solution sol;
    long long n;
    std::cin >> n;
    for (long long i = 0; i < n; ++i) {
        nodes[i].value = i;
        long long left, right;
        std::cin >> left >> right;

        if(left != -1){
            nodes[i].left = &nodes[left];
        }

        if(right != -1) {
            nodes[i].right = &nodes[right];
        }

    }

    std::cout<<sol.getMaxPainting(&nodes[0]);

    return 0;
}