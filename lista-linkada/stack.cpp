#include<stdio.h>
#include<iostream>
/* demo.c:  My first C program on a Linux */

class Node{
    public:
        int val;
        Node *next;
};

class Stack{
    public:
        Node *head;
        Node *tail;
        Node *curr;
        Node *sentinel = new Node;
        int size=0;
        Stack(){
            sentinel->next = NULL;
            head = sentinel;
            curr = sentinel;
        }

        void push(int value ){
            Node *novo = new Node;
            novo->val = value;
            novo->next = NULL;
            
            curr = head; 
            while(curr->next != NULL){
                curr = curr->next;
            }

            curr->next = novo;
            curr = novo;
            tail=curr;
            size++;
        }

        void insert(int value){
            Node *novo = new Node;
            novo->val = value;
            novo->next = curr->next;
            curr->next = novo;
            size++;
        }

        int pop(){
            int res;
            if(curr->next != NULL){
                res = curr->next->val;
                Node *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                size--;
            }
            setcurr(size-1);
            tail=curr;
            return res;

        }

        void change(int oldvalue, int newvalue){
            curr  = find(oldvalue);
            curr->next->val = newvalue;
        }

        void setcurr(int pos){
            curr = head;
            int i=0;
            while(curr->next != NULL && i < pos){
                curr = curr->next;
                i++;
            }
        }

        Node* find(int value){
            curr = head;
            while(curr->next != NULL && curr->next->val != value ){
                curr = curr->next;
            }
            return curr;
        }

        void show(){
            curr = head; 
            printf("\n****************\n");
            while(curr->next != NULL){
                curr = curr->next;
                printf("%d\n", curr->val);
            }
            printf("****************\n");
            
        }

        ~Stack(){
            curr = head;
            while(curr->next!=NULL){
                Node *del = curr;
                curr = curr->next;
                delete del;
            }
        }
};


int main(){

    Stack pilha;
    pilha.push(1);
    pilha.push(2);
    pilha.push(3);
    pilha.push(4);
    pilha.push(5);
    pilha.show();
    int r = pilha.pop();
    printf("%d\n",r );
    r = pilha.pop();
    printf("%d\n",r );
    r = pilha.pop();
    printf("%d\n",r );
    pilha.show();



    
    return 0;
}