#include<stdio.h>
#include<iostream>

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
    public:

        Graph(){
            head= tail = curr = sentinel;
            size=0;
        }

        void add(int val){
            Graphlistnode *novo = new Graphlistnode;
            novo->list.add(val);
            novo->next = NULL;
            
            tail->next = novo;
            tail = novo;
            
            size++;
        }

        void bind(int a, int b){
            search(a);
            if(curr->next !=NULL){
                curr->next->list.add(b);
            }

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

    g.add(10);
    g.add(30);
    g.add(50);
    g.show_vertices();
    g.bind(50,10);
    g.show();
    g.add(55);
    g.add(70);
    g.add(20);
    g.add(90);
    g.show_vertices();

    g.bind(50,70);
    g.bind(50,20);
    g.bind(50,55);
    g.bind(55,50);
    g.bind(90,55);
    g.bind(70,10);
    g.bind(30,10);
    g.bind(90,55);
    g.bind(20,30);
    g.show();

    Graph h;

    h.add(1);
    h.add(6);
    h.add(9);
    h.add(10);
    h.add(7);
    h.add(5);

    h.bind(1,5);
    h.bind(1,7);
    h.bind(1,6);

    h.bind(6,5);
    h.bind(6,9);

    h.bind(9,5);

    h.bind(10, 9);
    h.bind(10, 5);

    h.bind(7,1);

    h.show();       

    return 0;
}