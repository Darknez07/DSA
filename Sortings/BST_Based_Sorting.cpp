#include <iostream>
#include <vector>
#include <time.h>
// My personal favourite sorting algorithm
// Best case, Worst Case, Average case are all
// O(nlogn)
// Space complexity is just for the
// Tree which is rooted
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int d){val = d;}
};
// Inorder traversal which always give
// sorted result in a "Binary search Tree"
void Inorder(vector<int> &v, TreeNode* root){
    if(!root) return;
    // Pass through left
    Inorder(v,root->left);
    // Print from left most
    // Then consequently parent
    v.push_back(root->val);
    // Then right
    Inorder(v,root->right);
}
// Below function makes a Binary Tree
// Which can make a "Binary Search Tree"
void MakeTree(TreeNode **root,int val){
    // Check if root is null
    // Add to root;
    if((*root) == nullptr){
        (*root) = new TreeNode(val);
        return;
    }else{
        // Now if not null
        // Then start logically find the place
        // If < root->val go to left node
        // But only if left node is present
        // Else just insert into the current left node
        //Exit
        if((*root)->val > val){
            if((*root)->left)
                MakeTree(&((*root)->left),val);
            else{
                (*root)->left = new TreeNode(val);
                return;
            }
        }else{
            // Simliarly if the present val is greater than or equal to
            // current root->val
            // Then move to right node
            // But only if it is present
            // Else just insert here and return;
            if((*root)->right)
                MakeTree(&((*root)->right),val);
            else{
                (*root)->right = new TreeNode(val);
                return;
            }
        }
    }
}
int main(){
    int n = 20;
    srand(time(NULL));
    TreeNode *r = nullptr;
    for(int i=0;i<n;i++){
        MakeTree(&r,rand() % (n + 20));
    }
    vector<int> v;
    Inorder(v, r);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}