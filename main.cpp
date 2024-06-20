#include <iostream>
using namespace std;

class Node {
  // Write Node Description here
  // Node variables are given in Assignment
  private: 
  int data;
  Node *nextNode;

  public:
  Node(int theData)
  {
    data = theData;
    nextNode = nullptr;
  }
  int getData()
  {
    return data;
  }
  void setData(int newData)
  {
    data = newData;
  }
  Node* getNext()
  {
    return nextNode;
  }
  void setNext(Node* nextNod)
  {
    nextNode = nextNod;
  }

};
class LLStack {
  // Stack ADT
  //  Use Appropriate Variables
  //  Write Stack methods here
  //  Stack is implemented as a linked list
  //   Stack methods are Push(), Pop(), Peek()
  private: 
  Node *top;
  int stackSize;
  

  public:
  LLStack()
  {
    stackSize = 0;
  }
  int getSize()
  {
    return stackSize;
  }
  void setSize(int size)
  {
    stackSize = size;
  }
  Node* getTop()
  {
    return top;
  }
  void setTop(Node *theTop)
  {
    top = theTop;
  }


  void Push(int num)
  {
    Node *aNode = new Node(num);
    if(top == nullptr)
    {
      setTop(aNode);
    }
    else
    {
      aNode->setNext(top);
      setTop(aNode);
    }
    stackSize++;
  }
  int Pop()
  { 
    if (top == nullptr) {
      cout << "List is empty" << endl;
      return -1;
    }

    Node *temp = top;
    int tempdata = temp->getData();
    // top = top->getNext(); // this whats causing segmentation fault

    //cout << "Deleted top is " << temp->getData() << endl;
   
    top = temp->getNext();
    delete temp;
    stackSize--;
    return tempdata; 
  }
  int Peek()
  {
    if(top == nullptr)
    {
      cout << "List is empty" << endl;
      return -1;
    }
    cout << "The top is " << top->getData() << endl;
    return top->getData();
  }
  void Print(LLStack *myList)
  {
    LLStack *temp = new LLStack();
    int hold;
    while(myList->getSize() != 0)
    {
      hold = myList->Pop();
      cout << hold;
      if(myList->getSize() != 0)
      {
        cout << ", ";
      }
      temp->Push(hold);
    }
    while(temp->getSize() != 0)
    {
      hold = temp->Pop();
      myList->Push(hold);
    }
    cout << endl;
  }

};

class StackQ  {
  // Queue ADT
  //  This is your queue class
  //  Implement queue methods here
  //  Queue methods are given in the Assignment
  //  Queue is implemented by manipulating two stacks.
  //  You will need references to 2 stacks here
  private: 
  LLStack* enQStack;
  LLStack* deQStack;

  public: 
  StackQ()
  {
    enQStack = new LLStack();
    deQStack = new LLStack();
  }
  LLStack* getEnqStack()
  {
    return enQStack;
  }
  LLStack* getDeqStack()
  {
    return deQStack;
  }

  void enQ(int num)
  {
    enQStack->Push(num);
  }
  void deQ()
  {
    int hold;
    while(enQStack->getSize() != 0)
    {
      hold = enQStack->Pop();
      deQStack->Push(hold);
    }
    cout << "You have dequeued: " << deQStack->Pop() << endl;
    if(deQStack->getSize() == 0 && enQStack->getSize() != 0)
    {
      while(enQStack->getSize() != 0)
      {
      hold = enQStack->Pop();
      deQStack->Push(hold);
      }
      cout << "You have dequeued: " << deQStack->Pop() << endl;
    }
  }
  
  void peek()
  {
    int hold;
    int holdPeek;
    while(enQStack->getSize() != 0)
    {
      hold = enQStack->Pop();
      deQStack->Push(hold);
    }
    while(deQStack->getSize() != 0)
    {
      if(enQStack->getSize() == 1)
      {
        holdPeek = enQStack->getTop()->getData();
      }
      hold = deQStack->Pop();
      
      enQStack->Push(hold);
    }
    cout << "Next in line is: " << holdPeek << endl;
    
  }
  void print()
  {
    int hold;
    while(enQStack->getSize() != 0)
    {
      hold = enQStack->Pop();
      deQStack->Push(hold);
    }
    while(deQStack->getSize() != 0)
    {
      hold = deQStack->Pop();
      cout << hold;
      if(deQStack->getSize() != 0)
      {
        cout << ", ";
      }
      enQStack->Push(hold);
    }
    cout << endl;
  }
  void printStack(LLStack *myList)
  {
    LLStack *temp = new LLStack();
    int hold;
    while(myList->getSize() != 0)
    {
      hold = myList->Pop();
      cout << hold;
      if(myList->getSize() != 0)
      {
        cout << ", ";
      }
      temp->Push(hold);
    }
    while(temp->getSize() != 0)
    {
      hold = temp->Pop();
      myList->Push(hold);
    }
    cout << endl;
  }
  
};
int main() {

  // Main method is written here
  // Write the options for menu
  // Implement appropriate exception Handling
  StackQ stack;
  bool isBool = true;
  string choice;
  int numChoice;
  while(isBool)
  {
    goBack:
    cout << "a. Enqueue in the queue" << endl;
    cout << "b. Dequeue from the queue" << endl;
    cout << "c. Peek from the Queue" << endl;
    cout << "d. Display the queue" << endl;
    cout << "e. Display enQStack and deQStack" << endl;
    cout << "f. Display size of the queue" << endl;
    cout << "g. Exit" << endl;
   

    cout << "Enter Choice:" << endl;
    cin >> choice;

    if((!choice.compare("a")) == 0 && (stack.getDeqStack()->getSize() + stack.getEnqStack()->getSize()) == 0)
    {
      if(choice.compare("g") == 0)
      {
        cout << endl<< "You have exited the program." << endl;
        break;
      }
      cout << "Your queue is empty or that is not a valid option." << endl << endl;
      goto goBack;
    }
    if(choice.compare("a") == 0)
    {
      onlyNum:
      cout << "What number would you like to enqueue: ";
      if(!(cin >> numChoice))
      {
        cout << "Please only input an integer" << endl << endl;
        cin.clear();
        cin.ignore(256,'\n');
        goto onlyNum;
      }
      
      stack.enQ(numChoice);
      
    }
    else if(choice.compare("b") == 0)
    {
      stack.deQ();
    }
    else if(choice.compare("c") == 0)
    {
      stack.peek();
    }
    else if(choice.compare("d") == 0)
    {
      cout << "Here is your Queue!" << endl;
      stack.print();
    }
    else if(choice.compare("e") == 0)
    {
      cout << "enQStack is : ";
      stack.printStack(stack.getEnqStack());
      cout << endl;
      cout << "deQStack is : ";
      stack.printStack(stack.getDeqStack());
      cout << endl;
    }
    else if(choice.compare("f") == 0)
    {
      cout << "Size of queue is: " << stack.getDeqStack()->getSize() + stack.getEnqStack()->getSize() << endl;
    }
    else if(choice.compare("g") == 0)
    {
      cout << endl<< "You have exited the program." << endl;
      isBool = false;
    }
    else
    {
      cout << "Invalid option, please select valid option." << endl;
    }
    cout << endl;
  }
  return 0;
}