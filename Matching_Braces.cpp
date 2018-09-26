#include <string>
#include <iostream>

/* Once upon a time I was asked by Hackerrank to write a program that checks whether a given string                 //
//  comprised of only ({[ and ]}) was balanced, and that nested braces too were balanced.                           //
//  E.g. {[]()} is balanced. {[}] is not balanced.                                                                  //
//  I had the genius idea of counting the amount of braces nested within a set of braces. If that                   //
//  count was an even number, or if it ever went below zero, the braced were unbalanced. std::stringhe run time complexity    //
//  was quite ugly.                                                                                                //
//  std::stringhe very next day I learned what a stack was. And so:                                                           */

class StringStack
{
    class Node
    {
        public:
            Node* next;
            std::string value;
            operator= (Node* other)
            {
                this->value = other->value;
                this->next = other;

            }
    };

    Node* head;
    int stack_size = 0;

    public:
        void push(std::string item)
        {
            Node* new_head = new Node;
            new_head->value = item;
            new_head->next = this->head;
            this->head = new_head;
            ++stack_size;
        }

        bool isEmpty()
        {
            return stack_size == 0;
        }

        std::string peek()
        {
            return this->head->value;
        }

        void pop()
        {
            //std::string ret_value = this->head->value
            //Node *old_head = this->head;
            this->head = this->head->next;
            --stack_size;

            //return old_head->value;
        }

        BraceStack()
        {
            this->head = NULL;
        }
};

bool isBalanced(std::string braces)
{
     BraceStack<std::string> b_stack;

     for(int i = 0; i < braces.length; ++i)
     {
         switch(braces[i])
         {
            case '{':
            case '[':
            case '(':
                b_stack.push(braces[i]);
                break;
            case '}':
                if(!b_stack.peek().equals("{"))
                {
                    return false;
                }
                else
                {
                    b_stack.pop();
                }
                break;
            case ']':
                if(!b_stack.peek().equals("["))
                {
                    return false;
                }
                else
                {
                    b_stack.pop();
                }
                break;
            case ')':
                if(!b_stack.peek().equals("("))
                {
                    return false;
                }
                else
                {
                    b_stack.pop();
                }
                break;
            default:
                std::cout << "Extraneous character found.\n";
                return false;
         }
     }

     if(!b_stack.isEmpty())
     {
         return false;
     }

     return true;
}

int main()
{

}


/* And so I've learned: if I want to make a generic template of a stack using a linked list, do it in Java and not C++ */
