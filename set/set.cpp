#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Node{
    public:
        int val;
        int height;
        Node *father;

        Node(){
            father = NULL;
            height = 1;
        }
};

class Set{
    private:
    public:

    vector<Node*> U;

    void make_set(int val){
        Node *novo = new Node;
        novo->val = val;
        novo->height = 1;
        novo->father = novo;
        
        U.push_back(novo);
    }

    Node* find_(Node* node){
        if(node->father != node){
            node->father = find_(node->father);
        }
        return node->father;
    }

    Node* find(int val){
        int end = U.size();
        int i;
        for(i =0 ; i<end;i++){
            if(val == (U[i]->val) ){
                U[i]->father = find_(U[i]);
                return U[i]->father;
            }
        }
        return NULL;
    }

    Node* uni(int a, int b){
        int i,j, end = U.size();

        for(i=0; i <end ; i++){
            if(a == U[i]->val){
                Node *n1 = find_(U[i]);
                for(j=0 ; j < end; j++){
                    if(b == U[j]->val){
                        Node *n2 = find_(U[j]);
                        if(n1->height  > n2->height ){
                            n2->father=n1;
                            return n1;
                        }

                        if(n1->height  < n2->height ){
                            n1->father=n2;
                            return n2;
                        }

                        n1->father=n2;
                        n2->height++;
                        return n2;
                    }
                }
            
                return U[i];
            }    
        }
        
        return NULL;
    }

    void show(){
        int end = U.size();
        for(int i =0 ; i< end; i++){
            printf("(v:%d,f:%d,h:%d)\n", U[i]->val, U[i]->father->val, U[i]->height);
        }
        printf("\n");
    }
};

int main(){

    char comand[50];
    scanf(" %s",comand);

    Set universe;

    while(strcmp(comand,"quit")!=0){

        if(strcmp(comand, "add")==0){
            int val;
            scanf(" %d",&val);
            universe.make_set(val);
        }

        if(strcmp(comand, "union")==0){
            int a,b;
            scanf(" %d%d",&a,&b);
            Node *novo = universe.uni(a,b);
            if(novo!=NULL) printf("(v:%d,f:%d)\n", novo->val, novo->father->val);
            else printf("not found\n");
        }

        if(strcmp(comand, "find")==0){  
            int val;
            scanf(" %d",&val);
            Node *novo = universe.find(val);
            if(novo!=NULL)printf("(v:%d,f:%d)\n", novo->val, novo->father->val);
            else printf("not found\n");
        }

        if(strcmp(comand, "show")==0){
            universe.show();
            printf("\n");
        }

        scanf(" %s",comand);
    }

    return 0;
}