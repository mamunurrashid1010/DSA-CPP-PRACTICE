#include<iostream>
using namespace std;

//create structure node
struct node{
    int data;
    node* next;
    node(int value){
        data=value;
        next=NULL;
    }
};

//add node at begin
void insertAtBegin(node* &head, int value){

    //create a node
    node* n=new node(value);
    //if head null
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }

    //traverse node
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;

    return;

}

//add node at tail
void insertAtTail(node* &head,int value){

    if(head==NULL){
        insertAtBegin(head,value);
    }
    //create node
    node* n=new node(value);

    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;

    return;


}

//delete first node
void deleteFirstNode(node* &head){

        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        node* toDelete=temp->next;
        temp->next=head->next;
        head=head->next;
        delete toDelete;
        return;

}

//delete node 1 based index
void deleteNode(node* &head, int pos){
    if(pos==1){
        deleteFirstNode(head);
        return;
    }
    node* temp=head;
    int counter=2;
    while(counter<pos){
        counter++;
        temp=temp->next;
    }
    node* toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
    return;

}



//print node
void display(node* &head){

    node* temp=head;
    do{
        cout<<temp->data <<"->";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<"NULL" <<endl;
    return;
}

int main(){

    node* head=NULL;

    //insert node at begin
    insertAtBegin(head,5);
    insertAtBegin(head,6);
    insertAtBegin(head,7);
    display(head);
    //insert at tail
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);

    //delete linked list 1 based index
    cout<<"delete 3rd node:"<<endl;
    deleteNode(head,3);
    display(head);
    cout<<"delete 1st node:"<<endl;
    deleteNode(head,1);
    display(head);
    cout<<"delete last node:"<<endl;
    deleteNode(head,5);
    display(head);
    return 0;
}

