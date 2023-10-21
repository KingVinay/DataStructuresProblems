#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node * next;
  Node(int val){
    data = val;
    next = NULL;
  }
};
int LengthofLL(Node*head){
  int count = 0;
  while(head!=NULL){
    count++;
    head = head->next;
  }
  return count; 
}
void PrintLL(Node *head){
  while(head!=NULL){
    cout<<head->data<<"->";
    head = head->next;
  }
  cout<<"NULL"<<endl;
}
int IntersectionPoint(Node *head1,Node *head2){
  int n1 = LengthofLL(head1);
  int n2 = LengthofLL(head2);
  int pos;
  if(n1>n2){
    pos=n1-n2;
    while(pos--){
      head1 = head1->next;
    }
  }
  else if(n2>n1){
    pos = n2-n1;
    while(pos--){
      head2=head2->next;
    }
  }
  while(head1!=NULL || head2!=NULL){
    if(head1==head2){
      return head1->data;
    }
    head1=head1->next;
    head2=head2->next;
  }
  return -1;
}
int main(){
  Node *head1 = new Node(5);
  head1->next = new Node(4);
  head1->next->next = new Node(3);
  head1->next->next->next = new Node(2);
  head1->next->next->next->next = new Node(1);
  head1->next->next->next->next->next = new Node(6);
  head1->next->next->next->next->next->next = new Node(9);
  Node *head2 = new Node(3);
  head2->next = new Node(8);
  //joining both linked list at a node
  head2->next->next = head1->next->next->next;

  PrintLL(head1);
  PrintLL(head2);
  cout<<"Intersection Node is : "<<IntersectionPoint(head1,head2)<<endl;
  return 0;
}