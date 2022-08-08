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

// insert nth position
void insert_nth_position(node* &head,int value, int position){
    node* n=new node(value);
    int c=0;

    if(position==0){
        n->next=head;
        head->previous=n;
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL){
        //c++; //add here if 1 based index
        if(c==position){
            temp->previous->next=n;
            n->previous=temp->previous;
            n->next=temp;
            return;
        }
        c++; //add here if 0 based index
        temp=temp->next;
    }
}

// delete nth position node
void delete_nth_node(node* &head, int pos){
    // 1 based index
    if(pos==1){
        node* toDelete=head;
        head=head->next;
        head->next->previous=head;
        delete toDelete;
        return;
    }

    int c=0;
    node* temp=head;
    while(temp->next!=NULL){
         c++;
        if(c==pos){
            temp->next->previous=temp->previous;
            temp->previous->next=temp->next;
            delete temp;
            return;
        }
        temp=temp->next;
    }
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

    //insert nth position
    cout<<"insert 8 in 3rd position:" <<endl;
    insert_nth_position(head,8,3);
    print(head);

    //insert 1st position
    cout<<"insert 9 in 1st position:" <<endl;
    insert_nth_position(head,9,1);
    print(head);

    // delete nth(1) position node
    cout<<"delete 1 position node:" <<endl;
    delete_nth_node(head,1);
    print(head);

    // delete nth(2) position node
    cout<<"delete 3 position node:" <<endl;
    delete_nth_node(head,3);
    print(head);

    return 0;
}
