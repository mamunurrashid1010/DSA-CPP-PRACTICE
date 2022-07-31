#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int value){
        data=value;
        next=NULL;
    }
};

// insert node front
void insertFront(node* &head,int value){
    node* n=new node(value);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    return;
}

// insert begine
void insertBegine(node* &head, int value){
    //create node
    node* temp=new node(value);
    temp->next=head;
    head=temp;

    return;
}

// linked list node print
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data <<"->";
        temp=temp->next;
    }
    cout<<"NULL" <<endl;
    return;

}

int main(){
    node* head=NULL;
    // insert front
    insertFront(head,1);
    insertFront(head,2);
    insertFront(head,3);
    insertFront(head,4);
    insertFront(head,5);
    //print linked list
    print(head);

    //insert begin
    insertBegine(head,6);
    insertBegine(head,7);
    print(head);

    return 0;
}
