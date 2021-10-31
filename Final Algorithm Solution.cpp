// MazeSolvingAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


int main()
{
    /*Initializing arrays*/
    char b[50], c[50];

    //char a[] = { 's','r','r','l','l','b','l','l','b','r','l','l','l','s','b','l','l','r','r','s','r','l','r','r','l','l','s','b','l','l','l','l','b','l','l','r','s','s' };

    char a[] = { 'l','b','r','l','b','s','l','b','l','r','b','l','r','b','r','s','b','l','s','b','s' };

    //char a[] = { 'r','b','s','b','l','r' };
    /*Array size optimization*/
    int aSize = *(&a + 1) - a;
    int bSize = 0;
    int cSize = 0;

    int boolean = 0;

    std::cout << "Length of a: " << aSize << "\n";

    /*Printing the initial maze map*/
    std::cout << "a: ";
    for (int i = 0;i < aSize;i++)
    {
        std::cout << a[i] << ", ";
    }


    std::cout << "\n";
    while (boolean == 0)
    {

        /*Executing lsrb algorithm*/
        for (int i = 0;i < aSize;i++)
        {
            /*sbl is replaced with r*/
            if (a[i] == 's' && a[i + 1] == 'b' && a[i + 2] == 'l')
            {
                //std::cout << i << " bingo" << "\n";
                b[i] = 'r';
                b[i + 1] = 'o';
                b[i + 2] = 'o';

                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;

            }
            /*lbr is replaced with b*/
            else if (a[i] == 'l' && a[i + 1] == 'b' && a[i + 2] == 'r') {
                //std::cout << i << " bingo" << "\n";
                b[i] = 'b';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;
            }
            /*lbs is replaced with r*/
            else if (a[i] == 'l' && a[i + 1] == 'b' && a[i + 2] == 's') {
                //std::cout << i << " bingo" << "\n";
                b[i] = 'r';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;
            }
            /*lbl is replaced with s*/
            else if (a[i] == 'l' && a[i + 1] == 'b' && a[i + 2] == 'l') {
                //std::cout << i << " bingo" << "\n";
                b[i] = 's';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;
            }
            /*rbl is replaced with b*/
            else if (a[i] == 'r' && a[i + 1] == 'b' && a[i + 2] == 'l') {
                //std::cout << i << " bingo" << "\n";
                b[i] = 'b';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;
                boolean = 1;
                bSize = bSize + 3;
            }
            /*sbs is replaced with b*/
            else if (a[i] == 's' && a[i + 1] == 'b' && a[i + 2] == 's') {
                //std::cout << i << " bingo" << "\n";
                b[i] = 'b';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;
            }
            /*rbr is replaced with s*/
            else if (a[i] == 'r' && a[i + 1] == 'b' && a[i + 2] == 'r') {
                //std::cout << i << " bingo" << "\n";
                b[i] = 's';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;
            }
            /*bsb is replaced with b*/
            /*else if (a[i] == 'b' && a[i + 1] == 's' && a[i + 2] == 'b') {
                b[i] = 'b';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;
            }*/
            else
                /*If non of the above combinations are available then print the map as it is*/
            {
                //std::cout << i << " not bingo" << "\n";
                b[i] = a[i];

                bSize++;
                boolean = 0;
            }


        }




        std::cout << "Length of b: " << bSize << "\n";


        std::cout << "b: ";
        for (int i = 0;i < aSize;i++)
        {
            //std::cout << i << " b " << b[i] << "\n";
            std::cout << b[i] << ", ";
        }

        std::cout << "\n";

        int iCounter = 0;
        for (int i = 0;i < aSize;i++)
        {
            if (b[i] != 'o')
            {
                c[iCounter] = b[i];
                iCounter++;
                cSize++;
                boolean = 1;
            }
            else
            {
                c[iCounter] = b[i];
                boolean = 0;
                //a[i] = c[i];

            }

        }

        if (bSize != cSize || bSize != aSize || aSize != cSize) {
            boolean = 0;
        }
        else {
            boolean = 1;
        }

        bSize = 0;



        std::cout << "Length of c: " << cSize << "\n";

        std::cout << "c: ";

        /*for (int n = 0; n < cSize; n++) {
            if (a[n] != 'b') {
                boolean = 1;
            }
            else {
                boolean = 0;
            }
        }*/

        for (int i = 0;i < cSize;i++)
        {
            //std::cout << i << " c " << c[i] << "\n";
            std::cout << c[i] << ", ";
        }

        /*for (int i = 0;i < cSize;i++)
        {
            //std::cout << i << " c " << c[i] << "\n";
            a[i]=c[i];
            //td::cout << c[i] << ", ";
        }*/

        std::cout << "\n";
        std::cout << "\n";

        //aSize = cSize;
        //a[30] = c[30];

        aSize = cSize;

        std::cout << "Length of a: " << aSize << "\n";



        std::cout << "a: ";

        for (int j = 0;j < aSize;j++)
        {
            //std::cout << i << " c " << c[i] << "\n";
            a[j] = c[j];
            std::cout << a[j] << ", ";
            //boolean = 0;
        }



        cSize = 0;


        std::cout << "\n";




    }//en of while

    std::cout << "Result: ";

    for (int i = 0;i < aSize; i++) {
        std::cout << a[i] << ", ";
    }

    std::cout << "\n";
    std::cout << "\n";

    int int_detected;
    for (int i=0; i < aSize; i++) {
        std::cout << "Intersection detected? ";
        std::cin >> int_detected;
        if (int_detected == 1) {
            if (a[i] == 'l') {
                std::cout << i + 1 << ". Turn left..." << a[i];
            }
            if (a[i] == 's') {
                std::cout << i + 1 << ". Head straight..." << a[i];
            }
            if (a[i] == 'r') {
                std::cout << i + 1 << ". Turn right..." << a[i];
            }
            if (a[i] == 'b') {
                std::cout << i + 1 << ". Turn back..." << a[i];
            }
            std::cout << "\n";
        }
        else {
            std::cout << "Invalid";
        }
        if (i == aSize-1) {
            std::cout << "End Reached!";
        }
    }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
