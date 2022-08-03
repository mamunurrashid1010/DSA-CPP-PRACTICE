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

// insert nth position
void insert_nth_position(node* &head, int value, int position){
    //create new node
    node* temp=new node(value);
    node* temp2=head;
    int p=1;
    while(temp2!=NULL){
        if(p+1 ==position){
            temp->next=temp2->next;
            temp2->next=temp;
        }
        p++;
        temp2=temp2->next;
    }
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
    cout<<"Insert front 1,2,3,4,5"<<endl;
    insertFront(head,1);
    insertFront(head,2);
    insertFront(head,3);
    insertFront(head,4);
    insertFront(head,5);
    //print linked list
    print(head);
    cout<<endl;

    //insert begin
    cout<<"Insert begin 6,7"<<endl;
    insertBegine(head,6);
    insertBegine(head,7);
    print(head);
    cout<<endl;

    //insert nth position
    cout<<"Insert 8 in 3rd position"<<endl;
    insert_nth_position(head,8,3);
    print(head);

    return 0;
}
