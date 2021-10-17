#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <regex>
#include <fstream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

int main()               //DAY 6 
{
    ifstream countlines("list6.txt"); //I have ifstream twice because one counts lines, other analyzes data
    ifstream input("list6.txt"); 
    string line = " ";
    int lines = 0; 
    while (countlines.good()) 
    {
        getline(countlines, line);
        if (line == "") //in this file, groups are seperated by a blank line so I need this if statement
        {
            lines++;
        }
    }
    cout << to_string(lines) << endl; 
    line = " ";
    string group = "";
    int total_count = 0;
    for (int i = 0; i < lines; i++) //puts each groups answers in a single string, then adds each non ' ' char to a set, then the set count is added to total_count
    {
        while (line != "")
        {
            getline(input, line);
            group += line;
        }
        set<char> answers;
        for (int ii = 0;  ii < group.size(); ii++)
        {
            if (group[ii] != ' ') //spaces take up a space in a set so this makes sure ONLY letters are in the set
            {
                answers.insert(group[ii]);
            }
        }
        total_count += answers.size();
        group = "";
        line = " ";
    }
    cout << to_string(total_count) << endl;
}