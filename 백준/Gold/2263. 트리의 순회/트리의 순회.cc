#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int val;
};

Node* BuildTree(const vector<int>& inorder, int inorderIndex, const vector<int>& postorder, int postorderIndex, int n)
{
    if(n == 0) return nullptr;

    int mid = postorder[postorderIndex + n - 1];
    int inorderMidIndex = find(inorder.begin(), inorder.end(), mid) - inorder.begin();

    Node* node = new Node{nullptr, nullptr, mid};
    int leftLength = inorderMidIndex - inorderIndex;
    node->left = BuildTree(inorder, inorderIndex, postorder, postorderIndex, leftLength);
    node->right = BuildTree(inorder, inorderMidIndex + 1, postorder, postorderIndex + leftLength, n - (leftLength + 1));

    return node;
}

void PrintTreePreorder(Node* node)
{
    if(node == nullptr) return;
    cout<<node->val<<" ";
    PrintTreePreorder(node->left);
    PrintTreePreorder(node->right);
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> inorder(n);
    vector<int> postorder(n);

    for(int i = 0; i < n; ++i)
    {
        cin>>inorder[i];
    }

    for(int i = 0; i < n; ++i)
    {
        cin>>postorder[i];
    }

    Node* tree = BuildTree(inorder, 0, postorder, 0, n);
    PrintTreePreorder(tree);
}