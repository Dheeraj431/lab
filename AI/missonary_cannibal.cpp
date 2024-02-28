#include <iostream>
using namespace std;

int main()
{
    int lM = 3;       // Number of missionaries on the left side
    int lC = 3;       // Number of cannibals on the left side
    int rM = 0;       // Number of missionaries on the right side
    int rC = 0;       // Number of cannibals on the right side
    int userM, userC; // User input for number of missionaries and cannibals

    cout << "\tGame Start\nNow the task is to move all of them to the right side of the river" << endl;
    cout << "Rules:\n1. The boat can carry at most two people\n2. If the number of cannibals is greater than missionaries, the cannibals would eat the missionaries\n3. The boat cannot cross the river by itself with no people on board" << endl;
    cout << "\nM M M C C C |     --- | \n"
         << endl;

    try
    {
        while (true)
        {
            while (true)
            {
                cout << "Left side -> right side river travel" << endl;
                cout << "Enter number of Missionaries travel => ";
                cin >> userM;
                cout << "Enter number of Cannibals travel => ";
                cin >> userC;

                if ((userM == 0) && (userC == 0))
                {
                    cout << "Empty travel not possible\nRe-enter : ";
                }
                else if (((userM + userC) <= 2) && ((lM - userM) >= 0) && ((lC - userC) >= 0))
                {
                    break;
                }
                else
                {
                    cout << "Wrong input re-enter : ";
                }
            }

            lM -= userM;
            lC -= userC;
            rM += userM;
            rC += userC;

            cout << endl;
            for (int i = 0; i < lM; ++i)
            {
                cout << "M ";
            }
            for (int i = 0; i < lC; ++i)
            {
                cout << "C ";
            }
            cout << "| --> | ";
            for (int i = 0; i < rM; ++i)
            {
                cout << "M ";
            }
            for (int i = 0; i < rC; ++i)
            {
                cout << "C ";
            }
            cout << endl;

            if (((lC == 3) && (lM == 1)) || ((lC == 3) && (lM == 2)) || ((lC == 2) && (lM == 1)) || ((rC == 3) && (rM == 1)) || ((rC == 3) && (rM == 2)) || ((rC == 2) && (rM == 1)))
            {
                cout << "Cannibals eat missionaries:\nYou lost the game" << endl;
                break;
            }

            if ((rM + rC) == 6)
            {
                cout << "You won the game : \n\tCongrats" << endl;
                break;
            }

            while (true)
            {
                cout << "Right side -> Left side river travel" << endl;
                cout << "Enter number of Missionaries travel => ";
                cin >> userM;
                cout << "Enter number of Cannibals travel => ";
                cin >> userC;

                if ((userM == 0) && (userC == 0))
                {
                    cout << "Empty travel not possible\nRe-enter : ";
                }
                else if (((userM + userC) <= 2) && ((rM - userM) >= 0) && ((rC - userC) >= 0))
                {
                    break;
                }
                else
                {
                    cout << "Wrong input re-enter : ";
                }
            }

            lM += userM;
            lC += userC;
            rM -= userM;
            rC -= userC;

            cout << endl;
            for (int i = 0; i < lM; ++i)
            {
                cout << "M ";
            }
            for (int i = 0; i < lC; ++i)
            {
                cout << "C ";
            }
            cout << "| <-- | ";
            for (int i = 0; i < rM; ++i)
            {
                cout << "M ";
            }
            for (int i = 0; i < rC; ++i)
            {
                cout << "C ";
            }
            cout << endl;

            if (((lC == 3) && (lM == 1)) || ((lC == 3) && (lM == 2)) || ((lC == 2) && (lM == 1)) || ((rC == 3) && (rM == 1)) || ((rC == 3) && (rM == 2)) || ((rC == 2) && (rM == 1)))
            {
                cout << "Cannibals eat missionaries:\nYou lost the game" << endl;
                break;
            }
        }
    }
    catch (const exception &e)
    {
        cout << "\nInvalid input please retry !!" << endl;
    }

    return 0;
}
