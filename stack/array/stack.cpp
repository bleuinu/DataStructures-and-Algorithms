#include <iostream> 
#include <cstdlib>
#include <ctime>
using namespace std;

#define SIZE 10

template <class T>
class Stack 
{
  private:
    T *stack;
    int top;
    int capacity;

  public:
    Stack(int n) 
    {
      stack = new T[n+1];
      top = 0;
      capacity = n;
    }

    ~Stack() 
    {
      capacity = top = 0;
      delete stack;
    }

    bool empty()
    {
      return top == 0;
    }

    void push(T val)
    {
      if (top == capacity)
      {
        cout << "Overflow...";
        return;
      }

      top += 1;
      stack[top] = val;
    }

    T pop() 
    {
      cout << "hello" << endl;
      if(empty())
      {
        cout << "Underflow...";
        return -1;
      }
      else
      {
        top -= 1;
        return stack[top + 1];
      }
    }

    void print() 
    {
      for(int i=1; i<=top; ++i)
      {
        cout << stack[i] << ' ';
      }
      cout << endl;
    }
};

int main()
{
  unsigned seed = time(0);
  srand(seed);

  Stack<double> stack(SIZE);

  for(int i=0; i<SIZE; ++i) 
  {
    stack.push(rand() % 100 / 17.0);
  }

  stack.print();

  while(!stack.empty())
  {
    cout << stack.pop() << endl;
  }

  stack.pop();

  return 0;
}
