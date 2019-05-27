/*
 * This program uses recursion to double
 * the integers found in a stack.
 * Based on a Stanford CS 106B lab exercise
 * Glenn Langdon
*/

#include "console.h"
#include "simpio.h" // getInteger()
#include "stack.h"

using namespace std;

Stack<int> doubleStack(Stack<int> &stk);
Stack<int> makeStack();

int main() {

    Stack<int> myStack = makeStack();
    Stack<int> s = doubleStack(myStack);
    cout << "Ther stack doubled is:" << s << endl;

    return 0;
}
// Take a stack, removes first item on the stack
// for each iteration until the stack is empty
// Then the returned values are put back onto
// the stack in the original order, but doubled.
Stack<int> doubleStack(Stack<int> &myStack) {
    if (!myStack.isEmpty()) {
        int n = myStack.pop();
        doubleStack(myStack);
        myStack.push(n);
        myStack.push(n);
    }
    return myStack;
}


// Function to take in numbers and return a stack
Stack<int> makeStack() {
    cout << "Please enter a number to be put in the stack:" << endl;
    cout << "Enter '0' to stop entering numbers" << endl;

    Stack<int> stk;
    while(true) {
    int num = getInteger("Please enter an integer:");
    if (num != 0) {
    stk.push(num);
    }
    else break;
   }
    cout << "The stack entered is: " << stk << endl;
    return stk;
}
