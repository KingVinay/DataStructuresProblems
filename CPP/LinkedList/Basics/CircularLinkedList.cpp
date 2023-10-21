#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node *next;
  Node(int val){
    data = val;
    next = NULL;
  }
};
void InsertAtTail(Node *&head,int val){
  if(head==NULL){
    head = new Node(val);
    head->next = head;
    return;
  }
  Node *temp=head;
  while(temp->next!=head){
    temp=temp->next;
  }
  Node *n = new Node(val);
  temp->next = n;
  n->next = head;
}
void InsertAtHead(Node *&head,int val){
  if(head==NULL){
    head = new Node(val);
    head->next = head;
    return;
  }
  Node * temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next = new Node(val);
  temp->next->next = head;
  head = temp->next;
}
Node * DeleteNode(Node *head,int pos){
  if(head==NULL){return NULL;}
  Node *temp=head;
  if(pos==0){
    while(temp->next!=head){
      temp=temp->next;
    }
    Node *del = head;
    temp->next = head->next;
    head = temp->next;
    delete del;
    return head;
  }
  int jump=1;
  while(jump<pos){
    temp=temp->next;
    jump++;
  }
  Node *del = temp->next;
  temp->next = temp->next->next;
  delete del;
  return head;

}
void PrintCircular(Node *head){
  Node *temp=head;
  while(temp->next!=head){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<temp->data<<endl;
}
Node *Input(){
  Node *head = NULL;
  int d;
  cin>>d;
  while(d!=-1){
    InsertAtTail(head,d);
    cin>>d;
  }
  return head;
}
int main()
{
  Node *head=Input();
  PrintCircular(head);
  int pos;
  cin>>pos;
  head = DeleteNode(head,pos);
  PrintCircular(head);
  return 0;
}