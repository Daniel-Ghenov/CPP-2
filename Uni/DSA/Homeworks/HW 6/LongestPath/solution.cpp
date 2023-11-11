#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

struct Node{
    int value;
    Node* left;
    Node* right;

}nodes[(int) 1e7];

class Solution{
private:
    int maxPath = INT_MIN;

public:
    int getMaxPath(Node* root){
        if(root == nullptr){
            return 0;
        }
        int max = getMax(root);
        return std::max(max, maxPath);
    }
private:

    int getMax(Node* root){
        if(root == nullptr){
            return 0;
        }
        int left = getMax(root->left);
        int right = getMax(root->right);

        int sum = root->value;
        if(left > 0){
            sum += left;
        }
        if(right > 0){
            sum += right;
        }

        if(sum > maxPath){
            maxPath = sum;
        }
        return std::max(std::max(left, right) + root->value, root->value);
    }

};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Solution sol;
    int n;
    std::cin>>n;
    for (int i = 0; i < n; ++i) {
        int val, l, r;
        std::cin>>val>>l>>r;
        nodes[i].value = val;
        if(l != -1){
            nodes[i].left = &nodes[l];
        }
        if(r != -1){
            nodes[i].right = &nodes[r];
        }
    }

    std::cout<<sol.getMaxPath(&nodes[0]);

    return 0;
}
