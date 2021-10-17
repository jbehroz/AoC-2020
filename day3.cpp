#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <regex>
#include <fstream>
#include <string>
using namespace std;

int main()               //DAY 3, Opens file, reads line, checks if the current x value or place is a #, increases count if it is. Very simple if check, hard part was making it loop well
{
    ifstream input("list3.txt"); //opens file
    int lines = 323; //total number of lines, again hardcoded because I am doing this the same day as day 2
    string iline; //string that is line in file
    int place = 0; //this is the place in the forest I am in
    int trees = 0; //this counts how many trees I encountered
    int empty = 0; //counts empty tiles
    for (int ii = 0; ii < lines; ii++) //a for loop that checks every line if place is a tree
    {
        getline(input, iline); //gets the line and puts it into iline
        iline += iline; //this makes it much easier to turn this day into a solvable problem
        iline += iline; //same ^
        cout << iline << endl;; //first test to make sure it doubles
        if (iline[place] == '#') //if the current char is a tree, increase the tree count by 1
        {
            trees++; 
        }
        else
        {
            empty++;
        }
        place += 3; //always increase place by 3 after checking
        if (place == 93) //makes place loop back around BEFORE it goes through the previous if statement
        {
            place = 0;
        }
        
    }
    cout << to_string(trees) << " trees and " << to_string(empty) << " empty spots" << endl; //tells me the final results
    
}
