#pragma once

class Node {
  private:
    Node *prev;
    int data;

  public:
    Node(int data)
    {
      this->data = data;
      this->prev = nullptr;
    }

    friend class Stack;
};

class Stack {
  private:
    Node *head;
    int size;

  public:
    Stack();
    Stack(int data);

    ~Stack();

    void push (int data);
    int pop ();

    int top();
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
};


Stack::Stack()
{
  head = nullptr;
  size = 0;
}

Stack::Stack(int data)
{
  head = new Node(data);
  size = 1;
}

Stack::~Stack()
{
  while (!isEmpty())
  {
    pop();
  }

  delete(head);
  head = nullptr;
}

void Stack::push(int data)
{
  if (head == nullptr)
  {
    head = new Node(data);
    size = 1;
  }
  else
  {
    Node *newNode = new Node(data);
    newNode->prev = head;
    head = newNode;
    ++size;
  }
}

int Stack::pop()
{
  if (size > 0) 
  {
    Node *temp = head;
    int value = head->data;
    head = head->prev;
    temp->prev = nullptr;
    delete(temp);
    --size;
  
    return  value;
  }
  else
  {
    exit(1);
  }
}

int Stack::top()
{
  if (head)
  {
    return head->data;
  }
  else 
  {
    exit(1);
  }
}
