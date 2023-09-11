#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

class Node{
    public:
        int val;
        Node *next;
};

class List{
    public:
        Node *sentinel = new Node;
        Node *curr, *head, *tail = sentinel;
        int size=0;

        List(){
            curr = head = tail = sentinel;
        }

        void add(int val){
            Node *novo = new Node;
            novo->val = val;
            novo->next = NULL;
            
            tail->next = novo;
            tail = novo;
            size++;
        }

        void sethead(int val){
            Node *novo = new Node;
            novo->val = val;
            novo->next = NULL;
            
            head->next = novo;
            tail = novo;
            size++;
        }

        Node* search(int val){
            curr = head;
            
            while(curr->next !=NULL){
                if(curr->next->val == val){
                    return curr->next;
                }
                curr = curr->next; 
            }
            return NULL;
        }

        void show(){
            curr = head->next;
            while(curr->next !=NULL){
                printf("-> %d ", curr->next->val);
                curr = curr->next;
            }
            
        }

        ~List(){
            curr = head;
            
            while(head->next !=NULL){
                Node *tmp = head->next;
                head->next = head->next->next;
                delete tmp;
            }
            
        }
};

class Graphlistnode{
    public:
        List list;
        Graphlistnode *next;
};

class Graph{
    private:
        Graphlistnode *sentinel = new Graphlistnode;
        Graphlistnode *head, *tail, *curr = sentinel;
        int size=0;
        int numedge, numvert;
    public:

        Graph(){
            head= tail = curr = sentinel;
            size=numedge=numvert=0;
        }

        void add(int val){
            Graphlistnode *novo = new Graphlistnode;
            novo->list.add(val);
            novo->next = NULL;
            
            tail->next = novo;
            tail = novo;

            numvert++;
        }

        

        void dfs_visit(int s, int *p){
            p[s] = 1;
            
            
            setcurr(s);
            printf(" %d,", curr->list.head->next->val);
            Node *edge = curr->list.head->next;

            while(edge != NULL){
                int v = edge->val;
                if(p[v]==0){
                    dfs_visit(v , p);
                }
                edge = edge->next;
            }
            //printf("po%d,", curr->list.head->next->val);
        }

        void dfs(){
            int *p = new int[numvert];
            memset(p,0, numvert);

            for(int s=0 ; s < numvert ; s++){
                if(p[s]==0){
                    dfs_visit(s,p);
                }
            }
            printf("\n");
            delete p; 
        }

        void bind(int a, int b){
            search(a);
            if(curr->next !=NULL){
                curr->next->list.add(b);
            }
            numedge++;
        }

        void search(int val){
            curr = head;
            
            int saida=1;
            while(curr->next !=NULL && saida){
                if(curr->next->list.head->next->val == val){
                    saida = 0;
                }else{
                    curr = curr->next; 
                }
            }
        }

        void setcurr(int val){
            if(val >= numvert || val < 0) return;

            curr = head;
            int saida=1;
            while(val-- >= 0 && curr->next !=NULL){
                curr = curr->next;
            }
        }

        void show_vertices(){
            curr = head;
            printf("\nshowing vertices:\n");
            while(curr->next!=NULL){
                printf(" %d:\n",curr->next->list.head->next->val);
                curr = curr->next;
            }
        }

        void show(){
            curr = head;
            printf("\nshowing vertices and edges:\n");
            while(curr->next!=NULL){
                printf("\n  %d:",curr->next->list.head->next->val);
                curr->next->list.show();
                curr = curr->next;
            }
            printf("\n");
        }

};


int main(){
    Graph g;

    char comand[50];
    scanf(" %s",comand);

    while(strcmp(comand,"quit")!=0){

        if(strcmp(comand, "add")==0){
            int val;
            scanf("%d", &val);
            g.add(val);
        }

        if(strcmp(comand, "bind")==0){
            int val1, val2;
            scanf(" %d %d", &val1, &val2);
            g.bind(val1,val2);
        }

        if(strcmp(comand, "dfs")==0){
            g.dfs();
        }

        if(strcmp(comand, "show")==0){
            g.show();
        }

        scanf(" %s",comand);
    }

    return 0;
}