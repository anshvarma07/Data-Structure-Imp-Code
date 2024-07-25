#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;


    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* BuildTree(Node* root){
    cout<<"Enter Data for the Tree ";
    int data;
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }  
    cout << "Enter Data to be added to Left of " << data << endl;
    root->left=BuildTree(root->left);
    cout<<"Enter Data to be added to Right of "<< data <<endl;
    root->right=BuildTree(root->right);
    
    return root;

};




int main() {
    Node* root=NULL;
    root=BuildTree(root);
    return 0;
}