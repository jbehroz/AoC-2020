#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <regex>
#include <fstream>
#include <string>
using namespace std;
int main()                                                                            //DAY 2, FAIRLY CLEAN AND COMMENTED. This program opens the text file and line by line checks for multiple "groups" using regex.
{                                                                                      // The regex gives me the floor and ceiling, letter to check, and password. I have to find how many times letter appears in password and then
    ifstream input("list2.txt"); //opens file                                           check if it is within the floor and ceiling numbers. If so, it adds one to the valid password count, and if not nothing significant happens. 
    string iline; //initialize a string for the line being used                         I left in all the cout statements that let me know each step of this process actually works correctly, from actuall getting the line to seperating the values and comparing.
    regex reg("(\\d{1,2})-(\\d{1,2}) (\\w): (\\w+)"); //making a regex command "reg" 
    smatch result; //making a result smatch class
    int valid_count = 0; //count of valid passwords overall
    for(int ii = 0; ii < 1000; ii++) //this for loop uses getline once per line, 1000 is hardcoded because I couldn't figure out how to count the total # of lines
    {
        getline(input, iline); //gets the i'th line of the file and puts it into "iline"
        regex_match(iline, result, reg); //takes iline, the first line of the file, to use regex to scan. the result is the output, an array? that has elements 1-4 as each group, and reg is the regex command
        cout << iline << endl; //outputs that make sure every step is working correctly
        cout << result[1] << " " << result[2] << " " << result[3] << " " << result[4] << endl;
        int floor = stoi(result[1]); //start of proccess to check validity to passwords, assigning new integers/strings/chars to the values in result for easier (and safer?) access
        int ceiling = stoi(result[2]);
        string letter = result[3];
        char cletter = letter[0]; //dirty conversion of the letter to a char
        string password = result[4];
        int length = password.length(); //need length for a for loop
        int count = 0; //count of cletter within password
        
        // this will loop the next loops/if statements for each line in the document
        for(int i = 0; i < length; i++) //this loop goes through each letter in password and checks if it is equal to cletter. if so, increase count. if not, nothing.
        {
            if (password[i] == cletter)
            {
                count++;
            }
        };
        if (floor <= count) //this if statement is the first litmus test for whether or not the password is valid
        {
            if (count <= ceiling) //this if statement is the second, final litmus test for the password validity. if it's true we get a nice message and a +1 to the valid_count
            {
                cout << "true!" << endl;
                valid_count++;
            }
            }
            else //if not, false :(
           {
                cout << "false :(" << endl;
            };
    }
    cout << to_string(valid_count) << endl; //outputs the amount of valid passwords, the answer
}

