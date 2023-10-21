#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node *next;
  Node *prev;
  Node(int val){
    data = val;
    next = NULL;
    prev = NULL;
  }
};
void InsertAtHead(Node *&head,int val){
  if(head==NULL){
    head = new Node(val);
    return;
  }
  Node *n = new Node(val);
  n->next = head;
  head->prev = n;
  head = n;
}
void InsertAtTail(Node *&head,int val){
  if(head==NULL){
    head = new Node(val);
    return;
  }
  Node *temp = head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  Node *n = new Node(val);
  temp->next = n;
  n->prev = temp; 
}
void DeleteNode(Node *&head,int pos){
  if(head==NULL){
    return;
  }
  int jump=0;
  Node *temp=head;
  while(temp!=NULL&&jump<pos){
    jump++;
    temp=temp->next;
  }
  if(temp==NULL){
    cout<<"pos not found"<<endl;
    return;
  }
  if(temp==head){
    temp->next->prev=NULL;
    head = temp->next;
    delete temp;
  }
  else if(temp->next==NULL){
    temp->prev->next = NULL;
    delete temp;
  }
  else{
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
  }
}
Node * Input(){
  Node *head=NULL;
  int d;
  cin>>d;
  while(d!=-1){
    InsertAtHead(head,d);
    cin>>d;
  }
  return head;
}
void PrintLL(Node *head){
  while(head!=NULL){
    cout<<head->data<<"->";
    head = head->next;
  }
  cout<<"NULL"<<endl;
}

//Checking Prev and Next For a Key 
void FindPrevAndNext(Node *head,int key){
  if(head==NULL){
    return;
  }
  while(head!=NULL){
    if(head->data==key){
      if(head->prev==NULL){
        cout<<"prev :"<<"NULL"<<endl;
      }
      else{
        cout<<"prev :"<<head->prev->data<<endl;
      }
      if(head->next==NULL){
        cout<<"next :"<<"NULL"<<endl;
      }
      else{
        cout<<"next :"<<head->next->data<<endl;
      }
      
    }
    head=head->next;
  }
}
int main()
{
  Node *head = Input();
  PrintLL(head);
  int pos;
  cin>>pos;
  DeleteNode(head,pos);
  PrintLL(head);
  int key;
  cin>>key;
  FindPrevAndNext(head,key);
}