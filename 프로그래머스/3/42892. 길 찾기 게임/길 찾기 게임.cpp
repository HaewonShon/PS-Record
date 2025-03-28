#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node
{;
    Node* left, *right;
    int x, nodeNum;
};

void Insert(Node* node, int x, int nodeNum)
{
    if(x < node->x)
    {
        if(node->left) Insert(node->left, x, nodeNum);
        else node->left = new Node{nullptr, nullptr, x, nodeNum};
    }
    else
    {
        if(node->right) Insert(node->right, x, nodeNum);
        else node->right = new Node{nullptr, nullptr, x, nodeNum};
    }
}

void VisitPreOrder(Node* node, vector<int>& ans)
{
    if(!node) return;
    
    ans.push_back(node->nodeNum);
    VisitPreOrder(node->left, ans);
    VisitPreOrder(node->right, ans);
}

void VisitPostOrder(Node* node, vector<int>& ans)
{
    if(!node) return;
    
    VisitPostOrder(node->left, ans);
    VisitPostOrder(node->right, ans);
    ans.push_back(node->nodeNum);
}

void Delete(Node* node)
{
    if(node->left) Delete(node->left);
    if(node->right) Delete(node->right);
    delete node;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    for(int i = 0; i < nodeinfo.size(); ++i)
    {
        nodeinfo[i].push_back(i+1);
    }
    
    sort(nodeinfo.begin(), nodeinfo.end(), [](auto& p1, auto& p2){
        if(p1[1] == p2[1]) return p1[0] < p2[0];
        return p1[1] > p2[1];
    });
        
    Node* tree = new Node{nullptr, nullptr, nodeinfo[0][0], nodeinfo[0][2]};
    for(int i = 1; i < nodeinfo.size(); ++i)
    {
        Insert(tree, nodeinfo[i][0], nodeinfo[i][2]);
    }

    vector<vector<int>> answer(2);
    VisitPreOrder(tree, answer[0]);
    VisitPostOrder(tree, answer[1]);
    
    Delete(tree);
    return answer;
}