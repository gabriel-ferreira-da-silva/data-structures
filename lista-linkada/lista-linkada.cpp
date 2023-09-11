#include<stdio.h>
#include<iostream>
/* demo.c:  My first C program on a Linux */

class Node{
    public:
        int val;
        Node *next;
};

class Lista{
    public:
        Node *head;
        Node *curr;
        Node *sentinel = new Node;
        int size=0;
        Lista(){
            sentinel->next = NULL;
            head = sentinel;
            curr = sentinel;
        }

        void append(int value ){
            Node *novo = new Node;
            novo->val = value;
            novo->next = NULL;
            
            curr = head; 
            while(curr->next != NULL){
                curr = curr->next;
            }

            curr->next = novo;
            curr = novo;
            size++;
        }

        void insert(int value){
            Node *novo = new Node;
            novo->val = value;
            novo->next = curr->next;
            curr->next = novo;
            size++;
        }

        void remove(){
            if(curr->next != NULL){
                Node *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                size--;
            }
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

        ~Lista(){
            curr = head;
            while(curr->next!=NULL){
                Node *del = curr;
                curr = curr->next;
                delete del;
            }
        }
};


int main(){

    Lista lista;
    lista.append(1);
    lista.append(2);
    lista.append(3);
    lista.append(4);
    lista.append(5);
    lista.show();
    lista.remove();
    lista.show();

    
    return 0;
}