#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Node{
    long long value;
    Node* left;
    Node* right;

}nodes[(int) 1e7];

class Solution{
    std::vector<long long> ans = std::vector<long long>(8,0);
    int minSlope = 0;
    int maxSlope = 0;

public:


    std::vector<long long> getSkiingSlopes(Node* root){
        getBorders(root, 0);
        ans.resize(maxSlope - minSlope + 1, 0);
        getSlopes(root, abs(minSlope));
        return ans;
    }

private:
    void getSlopes(Node* root, int slope){
        if(root == nullptr){
            return;
        }
        ans[slope] += root->value;
        getSlopes(root->left, slope - 1);
        getSlopes(root->right, slope + 1);
    }

    void getBorders(Node* root, int slope){
        if(root == nullptr){
            return;
        }
        if(slope > maxSlope){
            maxSlope = slope;
        }
        if(slope < minSlope){
            minSlope = slope;
        }
        getBorders(root->left, slope - 1);
        getBorders(root->left, slope + 1);
    }

};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Solution sol;
    long long n;
    std::cin>>n;
    for (long long i = 0; i < n; ++i) {
        long long val, l, r;
        std::cin>>val>>l>>r;
        nodes[i].value = val;
        if(l != -1){
            nodes[i].left = &nodes[l];
        }
        if(r != -1){
            nodes[i].right = &nodes[r];
        }
    }
    std::vector<long long> slopes = sol.getSkiingSlopes(&nodes[0]);
    for (int i = 0; i < slopes.size(); ++i) {
        if(slopes[i] > 0)
        std::cout<<slopes[i]<<' ';
    }

    std::flush(std::cout);
    return 0;
}
