#include<iostream>
using namespace std;
void printLinkedList();

struct node{
    int data;
    node* next;
};

node* head=NULL;
int main(){
    int value;

    for(int i=0;i<5;i++){
        //get user data
        cout<<"Enter data:";
        cin>>value;
        //create node
        node* temp=new node();
        temp->data=value;
        temp->next=NULL;

        if(head==NULL){
            head=temp;
            continue;
        }

        node* temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    //print linked list
    printLinkedList();
}

void printLinkedList(){
    cout<<"Link list:" <<endl;
    node* temp=head;
    while(temp!=NULL){
        cout<<"Data:" <<temp->data <<" next:" <<temp->next <<endl;
        temp=temp->next;
    }
}



