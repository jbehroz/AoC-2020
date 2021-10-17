#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <regex>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main()               //DAY 4
{
    ifstream countlines("list4.txt"); //opens file just to count amount of passengers
    ifstream input("list4.txt"); //opens the file for actual analysis
    string info = ""; //string for the information of the passenger, blank for now
    string add = " "; //string for the informationt to be added to info, starts with a space so it doesn't skip the while loop
    //unordered_map<string, string> fields;
    string line = " "; //this string is for c hecking how many lines otherwise I go though all the lines before i even look into the contents
    int lines = 0; //lines == passengers btw
    int valid = 0; //valid amount of passports
    string field[8] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"}; //all of the fields that have to be valid, cid exluded but in here anyways
    while(countlines.good()) //this lets me know how many passengers are in the text file by going line by line until it hits a line that is empty, aka new passenger
    {
        getline(countlines, line);
        if (line == "")
        {
            lines++;
        }
    }
    cout << to_string(lines) << endl; //lets me know how many lines there are
    for (int ii = 0; ii < lines; ii++) //for loop that goes through all the passengers
    {
        while (add != "") //this while loop adds all the information to the info string by adding all the lines to info until it hits a line which is blank, indicating a new passenger information start
        {
            getline(input, add);
            info += add;
            info += " ";
        };
        add = " "; //makes add a space again so it doesn't just skip the while loop after 1 passenger
        size_t found; //this declaration lets me evaluate if the fields from field[] are in the string
        int correct; //an integer to keep track of whether or not a passport is correct
        correct = 0; //makes it 0, or valid
        for (int i = 0; i < 7; i++) //checks all the fields except the last, unecessary one
        {
            found = info.find(field[i]); //makes found equal to wherever the field was found, string::npos if not fo und
            if (found == string::npos) //if it isn't found, make correct negative. could have been positive too, doesn't really matter though
            {
                correct--;
            }
        }
        if (correct == 0) //after the for loop, this if checks correct out. if it never went down, it's a valid passport, increasing our count
        {
            valid++;
        }
        info = ""; //makes info blank again so we don't end up with all the passports stacking in one very very long string!
    }
    valid++; //idk why, I should know though
    //cout << info << endl; no longer relevant after testing
    cout << to_string(valid) << endl; //output answer
}