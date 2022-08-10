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

// delete node
void deleteNode(node* &head,int value){
    if(head==NULL){
        return;
    }
    node* temp=head;

    while(temp!=NULL){
        if(temp->next->data==value){
            node* toDelete=temp->next;
            temp->next=temp->next->next;
            delete toDelete;
            return;
        }
        temp=temp->next;
    }

    return;
}

//delete node index wise
node* deleteNode_indexWise(node* &head,int x)
{
     if(head == NULL)
        return NULL;

     if(x == 1)
     {
         head = head->next;
         return head;
     }
     else
     {
         node *temp = head;
         int count = 2;
         while(count < x)
        {
              temp = temp->next;
              count++;
        }
         temp->next = temp->next->next;
     }

    return head;
}


// reverse link list
node* reverseNode(node* &head){
    node* previousPtr=NULL;
    node* currentPtr=head;
    node* nextPtr;
    while(currentPtr!=NULL){
        nextPtr=currentPtr->next;
        currentPtr->next=previousPtr;

        previousPtr=currentPtr;
        currentPtr=nextPtr;
    }
    //head=previousPtr;
    return previousPtr;

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
    cout<<endl;

    //delete node value wise
    cout<<"Delete node where value 4"<<endl;
    deleteNode(head,4);
    print(head);
    cout<<endl;

    //delete node index wise
    cout<<"Delete 3rd position node"<<endl;
    node* newHead1=deleteNode_indexWise(head,3);
    print(newHead1);
    cout<<endl;

    //reverse node
    cout<<"Reverse node"<<endl;
    node* newHead=reverseNode(head);
    print(newHead);

    return 0;
}
