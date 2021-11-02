// MazeSolvingAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    /*Initializing arrays*/
    char b[50], c[50];

    char mazeMap[] = { 's','r','r','l','l','b','l','l','b','r','l','l','l','s','b','l','l','r','r','s','r','l','r','r','l','l','s','b','l','l','l','l','b','l','l','r','s','s' };

    //char mazeMap[] = { 'l','b','r','l','b','s','l','b','l','r','b','l','r','b','r','s','b','l','s','b','s' };

    //char mazeMap[] = { 'r','b','s','b','l','r' };
    /*Array size optimization*/
    int aSize = *(&mazeMap + 1) - mazeMap; //Number of elements present in array mazeMap[]
    int bSize = 0;
    int cSize = 0;

    int boolean = 0;

    std::cout << "Length of mazeMap: " << aSize << "\n";

    /*Printing the initial maze map*/
    std::cout << "mazeMap: ";
    for (int i = 0;i < aSize;i++)
    {
        std::cout << mazeMap[i] << ", ";
    }


    std::cout << "\n";
    while (boolean == 0)
    {
        /*Executing lsrb algorithm*/
        for (int i = 0;i < aSize;i++)
        {
            /*sbl is replaced with r*/
            if (mazeMap[i] == 's' && mazeMap[i + 1] == 'b' && mazeMap[i + 2] == 'l')
            {
                b[i] = 'r';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;
            }
            /*lbr is replaced with b*/
            else if (mazeMap[i] == 'l' && mazeMap[i + 1] == 'b' && mazeMap[i + 2] == 'r') {
                b[i] = 'b';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;
            }
            /*lbs is replaced with r*/
            else if (mazeMap[i] == 'l' && mazeMap[i + 1] == 'b' && mazeMap[i + 2] == 's') {
                b[i] = 'r';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;
            }
            /*lbl is replaced with s*/
            else if (mazeMap[i] == 'l' && mazeMap[i + 1] == 'b' && mazeMap[i + 2] == 'l') {
                b[i] = 's';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;
            }
            /*rbl is replaced with b*/
            else if (mazeMap[i] == 'r' && mazeMap[i + 1] == 'b' && mazeMap[i + 2] == 'l') {
                b[i] = 'b';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;
                boolean = 1;
                bSize = bSize + 3;
            }
            /*sbs is replaced with b*/
            else if (mazeMap[i] == 's' && mazeMap[i + 1] == 'b' && mazeMap[i + 2] == 's') {
                b[i] = 'b';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;
            }
            /*rbr is replaced with s*/
            else if (mazeMap[i] == 'r' && mazeMap[i + 1] == 'b' && mazeMap[i + 2] == 'r') {
                b[i] = 's';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;
            }
            /*bsb is replaced with b*/
            /*else if (mazeMap[i] == 'b' && mazeMap[i + 1] == 's' && mazeMap[i + 2] == 'b') {
                b[i] = 'b';
                b[i + 1] = 'o';
                b[i + 2] = 'o';
                i = i + 2;

                bSize = bSize + 3;
                boolean = 1;
            }*/
            else
                /*If none of the above combinations are available then print the map as it is*/
            {
                b[i] = mazeMap[i];

                bSize++;
                boolean = 0;
            }


        }

        std::cout << "Length of b: " << bSize << "\n"; //bSize=aSize

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
            }
        }

        if (bSize != cSize || bSize != aSize || aSize != cSize) {
            boolean = 0;
        }
        else {
            boolean = 1;
        }

        bSize = 0; // For restarting the intermediate array when the loop iterates

        std::cout << "Length of c: " << cSize << "\n";

        std::cout << "c: ";
        for (int i = 0;i < cSize;i++)
        {
            std::cout << c[i] << ", ";
        }

        std::cout << "\n";
        std::cout << "\n";

        aSize = cSize;

        std::cout << "Length of mazeMap: " << aSize << "\n";

        std::cout << "mazeMap: ";
        for (int j = 0;j < aSize;j++)
        {
            mazeMap[j] = c[j];
            std::cout << mazeMap[j] << ", ";
            //boolean = 0;
        }

        cSize = 0; // For restarting the intermediate array when the loop iterates

        std::cout << "\n";
    }//end of while

    std::cout << "Result: ";
    for (int i = 0;i < aSize; i++) {
        std::cout << mazeMap[i] << ", ";
    }

    std::cout << "\n";
    std::cout << "\n";

    int int_detected;
    for (int i=0; i < aSize; i++) {
        std::cout << "Intersection detected? ";
        std::cin >> int_detected;
        if (int_detected == 1) {
            if (mazeMap[i] == 'l') {
                std::cout << i + 1 << ". Turn left..." << mazeMap[i];
            }
            if (mazeMap[i] == 's') {
                std::cout << i + 1 << ". Head straight..." << mazeMap[i];
            }
            if (mazeMap[i] == 'r') {
                std::cout << i + 1 << ". Turn right..." << mazeMap[i];
            }
            if (mazeMap[i] == 'b') {
                std::cout << i + 1 << ". Turn back..." << mazeMap[i];
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
