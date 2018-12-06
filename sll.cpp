#include <vector>
#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
};

class mylist
{
private:
  node *head, *tail;

public:
  mylist();
  ~mylist();
  void push_front(int);
  void print_list();
  void push_back(int);
  void insert_at_position();
  void delete_from_position();
  void bubble_sort();
  void reverse();

};

mylist::mylist()
{
  head = NULL;
  tail = NULL;
}

mylist::~mylist()
{
  int c = 0;
  struct node *curr = head;
  while (curr != NULL)
  {
    c++;
    struct node *temp = curr;
    curr = curr->next;
    delete temp;
  }
  cout << endl
       << c << " nodes deallocated from memory" << endl;
}
void push_back(int new_data,struct node** head)
{
    struct node* new_node = new node();
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}
void insert_at_position(int pos, int value, struct node** head)
{
  node *pre=new node;
  node *cur=new node;
  node *temp=new node;
  cur = *head;
  for(int i=1;i<pos;i++)
  {
    pre=cur;
    cur=cur->next; 
  }
  temp->data=value;
  pre->next=temp;
  temp->next=cur;
}
void delete_from_position(int pos,struct node** head)
{
  if(*head == NULL)
  return;
  struct node* temp = *head;
  if(pos == 0)
  {
    *head = temp->next;
    free(temp);
    return;
  }
  for(int i=0;temp!=NULL && i<pos-1;i++)
  temp = temp->next;
  if(temp == NULL || temp->next ==NULL)
  return;
  struct node *next = temp->next->next;
  free(temp->next);
  temp->next = next;
}
void mylist::push_front(int value)
{
  node *temp = new node;
  temp->data = value;
  temp->next = head;
  if (head == NULL)
    tail = temp;
  head = temp;
}
void bubble_sort(struct node *start)
{
  int swapped, i;
  struct node *ptr1;
  struct node *lptr = NULL;
  if(start == NULL)
  return;
  do
  {
    swapped = 0;
    ptr1 = start;

    while (ptr1->next !=lptr)
    {
      if(ptr1->data > ptr1->next->data)
      {
        swap(ptr1, ptr1->next);
        swapped = 1;
      }
      ptr1 = ptr1->next;
    }
    lptr = ptr1;
  }
  while(swapped);
}
void mylist::reverse()
{
  node *current = head;
  node *prev = NULL, *next = NULL;

  while (current !=NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}
void mylist::print_list()
{
  node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << "\t";
    temp = temp->next;
  }
}

int main()
{
  vector<int> a = { 5, 7, 13, 21, 16};
  mylist alist;
  for (int x : a)
    alist.push_front(x);
  cout << "Single Linked List " << endl;
  alist.print_list();
  cout << "\nLinked List after sorting \n" << endl; 
  alist.print_list();
  cout << "\ndelete_from_position  \n" << endl;
  alist.reverse(); 
  cout << "\nReversed Linked list \n" << endl; 
  alist.print_list();
  return 0;
}