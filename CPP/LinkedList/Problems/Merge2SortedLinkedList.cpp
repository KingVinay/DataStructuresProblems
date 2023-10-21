#include<iostream>
using namespace std;
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
    return;
  }
  Node*temp = head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next = new Node(val);
}
Node * Input(){
  Node * head = NULL;
  int d;
  cin>>d;
  while(d!=-1){
    InsertAtTail(head,d);
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
//Recursive way by merging 2 into one
Node * RecursiveMerge(Node *head1,Node *head2){
  //base case
  if(head1==NULL){return head2;}
  if(head2==NULL){return head1;}
  Node *temp;
  if(head1->data<head2->data){
    temp = head1;
    temp->next = RecursiveMerge(head1->next,head2);
  }
  else{
    temp = head2;
    temp->next = RecursiveMerge(head1,head2->next);
  }
  return temp;
}

//Iterative Way By creating new linked list from 2
Node * Merge2Sorted(Node *head1,Node *head2){
  Node *mergehead = NULL;
  while(head1!=NULL && head2!=NULL){
    if(head1->data>head2->data){
      InsertAtTail(mergehead,head2->data);
      head2=head2->next;
    }
    else{
      InsertAtTail(mergehead,head1->data);
      head1=head1->next;
    }
  }
  while(head1!=NULL){
    InsertAtTail(mergehead,head1->data);
    head1=head1->next;
  }
  while(head2!=NULL){
    InsertAtTail(mergehead,head2->data);
    head2=head2->next;
  }
  return mergehead;
}
int main()
{
  Node *head1 = Input();
  Node *head2 = Input();
  PrintLL(head1);PrintLL(head2);
  // Node * mergehead = Merge2Sorted(head1,head2);
  Node *recursivemergehead = RecursiveMerge(head1,head2);
  PrintLL(recursivemergehead);
}