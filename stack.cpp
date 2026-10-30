#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 5


//                 COLOR CODES
//=====================================================

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"



//                 STACK TEMPLATE
//=====================================================

template <class Type>
class Stack
{
    static int TOP;
    Type stk[MAX_SIZE];

public:

    // Constructor
    Stack()
    {
        TOP = -1;
    }

    // PUSH
    

    void push(Type value)
    {
        if (TOP == MAX_SIZE - 1)
        {
            cout << RED << "\nStack Overflow!" << RESET << endl;
            return;
        }

        TOP++;
        stk[TOP] = value;

        cout << GREEN
             << "\nElement pushed successfully."
             << RESET << endl;
    }


    //=================================================
    // POP
    //=================================================

    void pop()
    {
        if (TOP == -1)
        {
            cout << RED
                 << "\nStack Underflow!"
                 << RESET << endl;
            return;
        }

        cout << GREEN
             << "\nDeleted element : "
             << stk[TOP]
             << RESET << endl;

        TOP--;
    }


    
    // DISPLAY
    //=================================================

    void display()
    {
        if (TOP == -1)
        {
            cout << RED
                 << "\nStack is empty."
                 << RESET << endl;
            return;
        }

        cout << CYAN
             << "\n+----------------------+\n"
             << "|    STACK ELEMENTS    |\n"
             << "+----------------------+\n"
             << RESET;

        for (int i = TOP; i >= 0; i--)
        {
            cout << BLUE
                 << "|        "
                 << stk[i]
                 << "           |\n"
                 << RESET;
        }

        cout << CYAN
             << "+----------------------+\n"
             << RESET;
    }


    // CREATE NEW STACK
    //=================================================

    void newStack()
    {
        TOP = -1;

        cout << GREEN
             << "\nNew stack created successfully."
             << RESET << endl;
    }
};


//          STATIC MEMBER DEFINITION
//=====================================================

template <class Type>
int Stack<Type>::TOP = -1;

int main()
{

    Stack<int>    intStack;
    Stack<char>   charStack;
    Stack<float>  floatStack;
    Stack<double> doubleStack;
    Stack<string> stringStack;

    bool intUsed = false;
    bool charUsed = false;
    bool floatUsed = false;
    bool doubleUsed = false;
    bool stringUsed = false;


    int choice;
    int subChoice;

    // Three chances for wrong main-menu option
    int chance = 3;



    while (1)
    {
        cout << CYAN << BOLD;

        cout << "\n============================================\n";
        cout << "          TEMPLATE STACK APPLICATION\n";
        cout << "============================================\n";

        cout << RESET;

        cout << BLUE;
        cout << "1. int\n";
        cout << "2. char\n";
        cout << "3. float\n";
        cout << "4. double\n";
        cout << "5. string\n";
        cout << "6. Exit\n";
        cout << RESET;


        cout << YELLOW
             << "\nEnter your choice : "
             << RESET;

        cin >> choice;


        //=================================================
        //                    EXIT
        //=================================================

        if (choice == 6)
        {
            cout << GREEN
                 << "\nThanks for using our Stack Application."
                 << RESET << endl;

            cout << GREEN
                 << "Program terminated successfully."
                 << RESET << endl;

            break;
        }


        //=================================================
        //              INVALID MAIN OPTION
        //=================================================

        if (choice < 1 || choice > 6)
        {
            chance--;

            if (chance == 2)
            {
                cout << YELLOW
                     << "\nPlease read the options carefully."
                     << RESET << endl;
            }
            else if (chance == 1)
            {
                cout << RED
                     << "\nLast chance! Please take care."
                     << RESET << endl;
            }
            else
            {
                cout << RED
                     << "\nThanks for using our application."
                     << RESET << endl;

                cout << RED
                     << "Please read the manual and come back properly."
                     << RESET << endl;

                break;
            }

            continue;
        }


        // Valid option
        // Reset chances
        chance = 3;


        //=================================================
        //                  INTEGER STACK
        //=================================================

        if (choice == 1)
        {
            if (intUsed == false)
            {
                cout << GREEN << BOLD;

                cout << "\n--------------------------------------------\n";
                cout << "       INTEGER STACK APPLICATION\n";
                cout << "           READY TO USE\n";
                cout << "--------------------------------------------\n";

                cout << RESET;

                intUsed = true;
            }
            else
            {
                cout << YELLOW
                     << "\nYou are entering Integer Stack again."
                     << RESET << endl;

                cout << BLUE;
                cout << "1. Continue old stack\n";
                cout << "2. Create new stack\n";
                cout << RESET;

                cout << YELLOW
                     << "Enter your choice : "
                     << RESET;

                cin >> subChoice;


                if (subChoice == 2)
                {
                    intStack.newStack();
                }
                else if (subChoice != 1)
                {
                    cout << RED
                         << "\nInvalid choice."
                         << RESET << endl;

                    continue;
                }
            }


            //=================================================
            // INTEGER SUB MENU
            //=================================================

            while (1)
            {
                int value;

                cout << MAGENTA << BOLD;

                cout << "\n============================================\n";
                cout << "             INTEGER STACK\n";
                cout << "============================================\n";

                cout << RESET;

                cout << BLUE;
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Display Stack\n";
                cout << "4. Main Menu\n";
                cout << RESET;

                cout << YELLOW
                     << "Enter choice : "
                     << RESET;

                cin >> subChoice;


                if (subChoice == 1)
                {
                    cout << YELLOW
                         << "Enter integer : "
                         << RESET;

                    cin >> value;

                    intStack.push(value);
                }
                else if (subChoice == 2)
                {
                    intStack.pop();
                }
                else if (subChoice == 3)
                {
                    intStack.display();
                }
                else if (subChoice == 4)
                {
                    break;
                }
                else
                {
                    cout << RED
                         << "\nInvalid submenu option."
                         << RESET << endl;
                }
            }
        }


        //=================================================
        //                  CHAR STACK
        //=================================================

        else if (choice == 2)
        {
            if (charUsed == false)
            {
                cout << GREEN << BOLD;

                cout << "\n--------------------------------------------\n";
                cout << "       CHARACTER STACK APPLICATION\n";
                cout << "           READY TO USE\n";
                cout << "--------------------------------------------\n";

                cout << RESET;

                charUsed = true;
            }
            else
            {
                cout << YELLOW
                     << "\nYou are entering Character Stack again."
                     << RESET << endl;

                cout << BLUE;
                cout << "1. Continue old stack\n";
                cout << "2. Create new stack\n";
                cout << RESET;

                cout << YELLOW
                     << "Enter your choice : "
                     << RESET;

                cin >> subChoice;

                if (subChoice == 2)
                {
                    charStack.newStack();
                }
                else if (subChoice != 1)
                {
                    cout << RED
                         << "\nInvalid choice."
                         << RESET << endl;

                    continue;
                }
            }


            while (1)
            {
                char value;

                cout << MAGENTA << BOLD;

                cout << "\n============================================\n";
                cout << "             CHARACTER STACK\n";
                cout << "============================================\n";

                cout << RESET;

                cout << BLUE;
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Display Stack\n";
                cout << "4. Main Menu\n";
                cout << RESET;

                cout << YELLOW
                     << "Enter choice : "
                     << RESET;

                cin >> subChoice;


                if (subChoice == 1)
                {
                    cout << YELLOW
                         << "Enter character : "
                         << RESET;

                    cin >> value;

                    charStack.push(value);
                }
                else if (subChoice == 2)
                {
                    charStack.pop();
                }
                else if (subChoice == 3)
                {
                    charStack.display();
                }
                else if (subChoice == 4)
                {
                    break;
                }
                else
                {
                    cout << RED
                         << "\nInvalid submenu option."
                         << RESET << endl;
                }
            }
        }


        //=================================================
        //                  FLOAT STACK
        //=================================================

        else if (choice == 3)
        {
            if (floatUsed == false)
            {
                cout << GREEN << BOLD;

                cout << "\n--------------------------------------------\n";
                cout << "          FLOAT STACK APPLICATION\n";
                cout << "             READY TO USE\n";
                cout << "--------------------------------------------\n";

                cout << RESET;

                floatUsed = true;
            }
            else
            {
                cout << YELLOW
                     << "\nYou are entering Float Stack again."
                     << RESET << endl;

                cout << BLUE;
                cout << "1. Continue old stack\n";
                cout << "2. Create new stack\n";
                cout << RESET;

                cout << YELLOW
                     << "Enter your choice : "
                     << RESET;

                cin >> subChoice;

                if (subChoice == 2)
                {
                    floatStack.newStack();
                }
                else if (subChoice != 1)
                {
                    cout << RED
                         << "\nInvalid choice."
                         << RESET << endl;

                    continue;
                }
            }


            while (1)
            {
                float value;

                cout << MAGENTA << BOLD;

                cout << "\n============================================\n";
                cout << "               FLOAT STACK\n";
                cout << "============================================\n";

                cout << RESET;

                cout << BLUE;
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Display Stack\n";
                cout << "4. Main Menu\n";
                cout << RESET;

                cout << YELLOW
                     << "Enter choice : "
                     << RESET;

                cin >> subChoice;


                if (subChoice == 1)
                {
                    cout << YELLOW
                         << "Enter float value : "
                         << RESET;

                    cin >> value;

                    floatStack.push(value);
                }
                else if (subChoice == 2)
                {
                    floatStack.pop();
                }
                else if (subChoice == 3)
                {
                    floatStack.display();
                }
                else if (subChoice == 4)
                {
                    break;
                }
                else
                {
                    cout << RED
                         << "\nInvalid submenu option."
                         << RESET << endl;
                }
            }
        }


        //=================================================
        //                 DOUBLE STACK
        //=================================================

        else if (choice == 4)
        {
            if (doubleUsed == false)
            {
                cout << GREEN << BOLD;

                cout << "\n--------------------------------------------\n";
                cout << "         DOUBLE STACK APPLICATION\n";
                cout << "             READY TO USE\n";
                cout << "--------------------------------------------\n";

                cout << RESET;

                doubleUsed = true;
            }
            else
            {
                cout << YELLOW
                     << "\nYou are entering Double Stack again."
                     << RESET << endl;

                cout << BLUE;
                cout << "1. Continue old stack\n";
                cout << "2. Create new stack\n";
                cout << RESET;

                cout << YELLOW
                     << "Enter your choice : "
                     << RESET;

                cin >> subChoice;

                if (subChoice == 2)
                {
                    doubleStack.newStack();
                }
                else if (subChoice != 1)
                {
                    cout << RED
                         << "\nInvalid choice."
                         << RESET << endl;

                    continue;
                }
            }


            while (1)
            {
                double value;

                cout << MAGENTA << BOLD;

                cout << "\n============================================\n";
                cout << "              DOUBLE STACK\n";
                cout << "============================================\n";

                cout << RESET;

                cout << BLUE;
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Display Stack\n";
                cout << "4. Main Menu\n";
                cout << RESET;

                cout << YELLOW
                     << "Enter choice : "
                     << RESET;

                cin >> subChoice;


                if (subChoice == 1)
                {
                    cout << YELLOW
                         << "Enter double value : "
                         << RESET;

                    cin >> value;

                    doubleStack.push(value);
                }
                else if (subChoice == 2)
                {
                    doubleStack.pop();
                }
                else if (subChoice == 3)
                {
                    doubleStack.display();
                }
                else if (subChoice == 4)
                {
                    break;
                }
                else
                {
                    cout << RED
                         << "\nInvalid submenu option."
                         << RESET << endl;
                }
            }
        }


        //=================================================
        //                 STRING STACK
        //=================================================

        else if (choice == 5)
        {
            if (stringUsed == false)
            {
                cout << GREEN << BOLD;

                cout << "\n--------------------------------------------\n";
                cout << "          STRING STACK APPLICATION\n";
                cout << "             READY TO USE\n";
                cout << "--------------------------------------------\n";

                cout << RESET;

                stringUsed = true;
            }
            else
            {
                cout << YELLOW
                     << "\nYou are entering String Stack again."
                     << RESET << endl;

                cout << BLUE;
                cout << "1. Continue old stack\n";
                cout << "2. Create new stack\n";
                cout << RESET;

                cout << YELLOW
                     << "Enter your choice : "
                     << RESET;

                cin >> subChoice;

                if (subChoice == 2)
                {
                    stringStack.newStack();
                }
                else if (subChoice != 1)
                {
                    cout << RED
                         << "\nInvalid choice."
                         << RESET << endl;

                    continue;
                }
            }


            while (1)
            {
                string value;

                cout << MAGENTA << BOLD;

                cout << "\n============================================\n";
                cout << "              STRING STACK\n";
                cout << "============================================\n";

                cout << RESET;

                cout << BLUE;
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Display Stack\n";
                cout << "4. Main Menu\n";
                cout << RESET;

                cout << YELLOW
                     << "Enter choice : "
                     << RESET;

                cin >> subChoice;


                if (subChoice == 1)
                {
                    cout << YELLOW
                         << "Enter string : "
                         << RESET;

                    cin >> value;

                    stringStack.push(value);
                }
                else if (subChoice == 2)
                {
                    stringStack.pop();
                }
                else if (subChoice == 3)
                {
                    stringStack.display();
                }
                else if (subChoice == 4)
                {
                    break;
                }
                else
                {
                    cout << RED
                         << "\nInvalid submenu option."
                         << RESET << endl;
                }
            }
        }
    }

    return 0;
}
