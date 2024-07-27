#include <iostream>
#include <queue>
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

void LevelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);       //Root will always have only one element. Therefore escape sequence is used.

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){   // Last level has been traversed completelty.
            cout<<endl;      
            if(!q.empty()){
                q.push(NULL);
            };
        }
        else{
            cout<<temp->data<<" ";
            //Check if left is NULLS
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            //Check if right is NULL
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node* root){
    if(root==NULL){
        return; 
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root==NULL){
        return; 
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return; 
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}




int main() {
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root=NULL;
    root=BuildTree(root);

    cout<<"LevelOrderTraversal"<<endl;
    LevelOrderTraversal(root);

    cout<<"Inorder Traversal is:"<<" ";
    inorder(root);
    cout<<endl;
    
    cout<<"Preorder Traversal is:"<<" ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder Traversal is:"<<" ";
    postorder(root);
    cout<<endl;

    return 0;
}