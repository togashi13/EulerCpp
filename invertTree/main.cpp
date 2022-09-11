#include <iostream>
#include "BinarySearchTree.h"
#include <vector>
using namespace std;


int main()
{
//    TreeNode r(4,TreeNode* a(2,TreeNode* b(1),TreeNode* c(3)),TreeNode* d(7,TreeNode* e(6), TreeNode* f(9)));
//    TreeNode m(4);
//    TreeNode n(2);
//    TreeNode l(1);
//    m.left = &n;
//    m.right = &l;
    BinarySearchTree<int> bst;
    vector<int> xd{4,2,7,1,3,6,9};
    for ( int i = 0; i < xd.size(); i++)
    {
        bst.insert(xd[i]);
    }
    bst.printTree();
    cout << endl;
    bst.invertTree();
//    swap(bst.root->left,bst.root->right);
    auto temp = bst.root->right;
    bst.root->right = bst.root->left;
    bst.root->left = temp;
    bst.printTree();
    return 0;
}
