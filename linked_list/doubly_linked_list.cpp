#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* previous;
    node* next;

    node(int value){
        data=value;
        previous=NULL;
        next=NULL;
    }
};

// insert front/tail
void insertFront(node* &head, int value){
    node* n=new node(value);

    //check head is NULL
    if(head==NULL){
        n->next=head;
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->previous=temp;

    return;
}

// insert begin
void insertBegin(node* &head, int value){

    node* n=new node(value);
    if(head==NULL){
        n->next=head;
        head=n;
        return;
    }
    n->next=head;
    head->previous=n;
    head=n;
}


//print
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data <<"<->";
        temp=temp->next;
    }
    cout<<"NULL" <<endl;
    return;
}


int main(){

    node* head=NULL;

    //insert front
    cout<<"insert tail/front 1,2,3,4,5:" <<endl;
    insertFront(head,1);
    insertFront(head,2);
    insertFront(head,3);
    insertFront(head,4);
    insertFront(head,5);
    print(head);

    //insert begin
    cout<<"insert begin 6:" <<endl;
    insertBegin(head,6);
    print(head);
    cout<<"insert begin 7:" <<endl;
    insertBegin(head,7);
    print(head);

    return 0;
}
