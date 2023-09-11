#include<iostream>


class Node{
    public:
        int val;
        int bf; 
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

        Node* AVLinsert(Node* root, int val){
            
        }

        void insert(int val){
            root = AVLinsert(root, val);
        }



        Node* rotate_left( Node* root){
            Node* r;
            Node* rl;
            
            r =root->right;
            rl = r->left;
            r->left = root;
            root->right = rl;
            
            root->bf = root->bf- 1;
            if( r->bf < 0){
                root->bf = root->bf - r->bf;
            }
            r->bf =r->bf -1;
            if(root->bf < 0){
                r->bf = r->bf+ root->bf;
            }
            return r;
        }

        Node* rotate_right( Node* root){
            Node* l;
            Node* lr;
            
            l =root->left;
            lr = l->right;
            l->right = root;
            root->left = lr;
            
            root->bf = root->bf- 1;
            if( l->bf < 0){
                root->bf = root->bf + l->bf;
            }
            l->bf =l->bf + 1;
            if(root->bf < 0){
                l->bf = l->bf - root->bf;
            }
            return l;
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
            remove_(root, val);
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
    Node *root = new Node;
    Btree  tree;
    Chunk chunk;
    tree.insert(544);
    tree.insert(644);
    tree.insert(744);
    
   
    
    printf("preorder\n");
    tree.pre_order();

    printf("\ninorder\n");
    tree.in_order();

    printf("\npostorder\n");
    tree.post_order();
    
    printf("\n\n");
    printf("\npreorder\n");
    tree.pre_order();
    printf("\n");
    tree.root = tree.rotate_left(tree.root);
    tree.root = tree.rotate_right(tree.root);
    printf("\nafter lrotate inorder\n");
    tree.pre_order();
    printf("\n");
}