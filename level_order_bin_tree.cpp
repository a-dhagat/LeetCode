#include<iostream>
#include<vector>

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node* newNode(int data);
};

Node* newNode(int val)
{
    Node* node = new Node();
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void LevelOrder(std::vector<Node*> queue)
{
    while (queue.empty != true)
    {
        Node* new_root = queue.pop_back();
        
        
        queue.push_back(root);
        queue.push_back(root->left);
        queue.push_back(root->right);    
    }    
    
    
    

}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    // PrintTree(root);

    std::vector<Node*> queue;
    queue.push_back(root);
    LevelOrder(queue);
    return 0;
}

