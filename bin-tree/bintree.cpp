#include<iostream>
#include<string.h>

class Node{
    public:
        int val;
        Node* left;
        Node* right;

        Node(){
            left =right = NULL;

        }
    
};

class Chunk{
    public:
        Node* node;
        int val;
};

class Btree{
    public:
        Node* root;
        Btree(){
            root=NULL;
        }

        Node* insert_val(Node* root,int val){
            if(root==NULL){
                Node*novo = new Node;
                novo->val= val;
                return novo;
            }
            if(root->val > val){
                root->left = insert_val(root->left,val);
                return root;
            }else{
                root->right = insert_val(root->right,val);
                return root;
            }
        }

        void insert(int val){
            root = insert_val(root, val);
        }

        Chunk delete_min(Node* root){
            
            if(root->left == NULL){
                Chunk chunk;
                chunk.node =root->right;
                chunk.val = root->val;
                delete root;
                return chunk;    
            }else{
                Chunk chunk = delete_min(root->left);
                root->left = chunk.node;
                chunk.node = root;
                //chunk.val = root->val;
                return chunk;
            }
        }

        Node* remove_(Node* root, int val){
            if(root==NULL){
                return NULL;
            }else if(val < root->val ){
                root->left = remove_(root->left, val);
                return root;
            }else if(val > root->val){
                root->right = remove_(root->right, val);
                return root;
            }else{
                if( root->left==NULL){
                    Node* r = root->right;
                    delete root;
                    return r;
                }else if(root->right==NULL){
                    Node* l = root->left;
                    delete root;
                    return l;
                }else{
                    Chunk chunk = delete_min(root->right);
                    Node* node;
                    node->right = chunk.node;
                    node->val= chunk.val;
                    return node;
                }
            }
        }

        void remove(int val){
            root = remove_(root, val);
        }

        void pre_order(){
            preorder(root);
        }
        void post_order(){
            postorder(root);
        }
        void in_order(){
            inorder(root);
        }

        void preorder(Node* root){
            if(root==NULL){
                return;
            }
            printf("%d ",root->val);
            preorder(root->left);
            preorder(root->right);
        }

        void inorder(Node* root){
            if(root==NULL){
                return;
            }
            inorder(root->left);
            printf("%d ",root->val);
            inorder(root->right);
        }

        void postorder(Node* root){
            if(root==NULL){
                return;
            }
            postorder(root->left);
            postorder(root->right);
            printf("%d ",root->val);
        }

        int calcheight(Node* root){
            if(root==NULL){
                return 0;
            }
            int hl = calcheight(root->left);
            int hr = calcheight(root->right);

            if(hl > hr) return hl+1;
            return hr+1;
        }

        int getheight(){
            return calcheight(root);
        }
        
};
// ESQUECE
/*
void insert(Node* father, Node* root,int val){
    if(root==NULL){
        Node *novo = new Node;
        if(father!=NULL){
            if(father->val > val){
                father->left = novo;
                father->left->val= val;
            }else{
                father->right = novo;
                father->right->val= val;
            }
        }else{
            root = novo;
            root->val=val;
            printf("%d ",root->val);
        }

        return;
    }
    if(root->val < val) insert(root, root->right, val);
    if(root->val > val) insert(root, root->left, val);
}*/

void order(Node* root){
    if(root==NULL){
        return;
    }
    order(root->left);
    order(root->right);
}





int main(){

    Btree  tree;
    char command[30];

    int saida=1;

    while(saida){
        scanf(" %s", command);
        /*
        if(strcmp(command,"FND") ==0 || strcmp(command,"fnd") ==0){
            int val;
            scanf(" %d",&val);
            printf("%d\n", tree.find(val));
        }*/

        if(strcmp(command,"del") ==0 || strcmp(command,"DEL") ==0){
            int val;
            scanf(" %d",&val);
            tree.remove(val);
            //printf("%d\n", tree.remove(val));
        }

        if(strcmp(command,"ins") ==0 || strcmp(command,"INS") ==0){
            int val;
            scanf(" %d",&val);
            //printf("%d\n", tree.insert(val));
            tree.insert(val);
        }

        if(strcmp(command,"END") ==0 || strcmp(command,"end") ==0){
            saida=0;
        }  

        if(strcmp(command,"SHOW") ==0 || strcmp(command,"show") ==0){
            printf("post order: ");
            tree.post_order();
            printf("\npre order: ");
            tree.pre_order();
            printf("\nin order: ");
            tree.in_order();
            printf("\n\n");
        }





    }


}