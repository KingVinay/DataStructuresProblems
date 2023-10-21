//STL List - Doubly Linked List
#include <bits/stdc++.h>
using namespace std;

int main()
{
  list<int>l;
  //init
  list<int>l1{1,2,3,4,5,6};

  //different datatype
  list<string>l2{"apple","peach","grapes","guava","orange","melon","papaya","guava"};
  //push at back
  l2.push_back("banana");

  //sort
  l2.sort();

  //reverse
  l2.reverse();

  //pop front
  cout<<l2.front()<<endl;
  l2.pop_front();

  //iterate over list and print
  for(string s:l2){
    cout<<s<<"-->";
  }
  cout<<endl;

  //push front
  l2.push_front("kiwi");
  cout<<l2.back()<<endl;
  l2.pop_back();

  //print using iterator
  for(auto it=l2.begin();it!=l2.end();it++){
    cout<<(*it)<<"-->";
  }
  cout<<endl;

  //remove
  string s;
  cin>>s;
  l2.remove(s);

  for(string s:l2){
    cout<<s<<"-->";
  }
  cout<<endl;

  //erase
  auto it = l2.begin();
  it++;
  l2.erase(it);

  for(string s:l2){
    cout<<s<<"-->";
  }
  cout<<endl;

  //insert
  auto it1 = l2.begin();
  it1++;
  l2.insert(it1,"apricot");
  
  for(string s:l2){
    cout<<s<<"-->";
  }
  cout<<endl;

}