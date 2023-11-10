#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Node{
    int value;
    Node* left;
    Node* right;

}nodes[(int) 1e7];

class Solution{
    std::vector<int> slopesPos;
    std::vector<int> slopesNeg;

public:

    std::vector<int> getSkiingSlopes(Node* root){
        getSlopes(root, 0);
        std::vector<int> ans;
        for(auto it = slopesNeg.rbegin(); it != slopesNeg.rend(); it++){
            ans.push_back(*it);
        }
        for(auto it = slopesPos.begin(); it != slopesPos.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }

private:
    void getSlopes(Node* root, int slope){
        if(root == nullptr){
            return;
        }
        if(slope >= 0){
            if(slope >= slopesPos.size()){
                slopesPos.push_back(root->value);
            }else{
                slopesPos[slope] += root->value;
            }
        }else{
            if(abs(slope) >= slopesNeg.size()){
                slopesNeg.push_back(root->value);
            }else{
                slopesNeg[abs(slope)] += root->value;
            }
        }
        getSlopes(root->left, slope - 1);
        getSlopes(root->right, slope + 1);

    }

};


int main() {
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
    std::vector<int> slopes = sol.getSkiingSlopes(&nodes[0]);

    for (int i: slopes) {
        std::cout<<i<<' ';
    }
    return 0;
}
