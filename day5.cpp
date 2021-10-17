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

int main()               //DAY 5
{
    ifstream countlines("list5.txt"); //opens file to count lines
    ifstream input("list5.txt"); //opens file to analyze contents
    string line = " "; //string for getline
    string boarding_pass;
    int lines = 0; //# of lines integer
    while (countlines.good()) //while loop that goes through each line once with getline to count the # of lines
    {
        getline(countlines, line);
        lines++;
    }
    cout << to_string(lines) << endl; //outputs total number of lines
    vector<int> id; //vector to hold ALL the ids
    for (int i = 0; i < lines; i++) //for loop to read each line
    {
        int row[2] = {0, 127}; //a small array for all the possible rows the seat could be, we modify this array to find it
        int column[2] = {0, 7}; //same as above for column
        getline(input, boarding_pass); //reads the i'th line of the file
        for (int ii = 0; ii < 7; ii++) //although this could be in 1 for loop, I split it up. oh well. 7 is how many B or F there are
        {
            if  (boarding_pass[ii] == 'B') //if it's B, we get the difference between the upper and lower end and add 1 and then divide it in half and then add it to the lower end
            {
                row[0] += (row[1] - row[0] + 1)/2;
            }
            else if (boarding_pass[ii] == 'F') //if it's F, we reduce the lower half by half the difference plus 1
            {
                row[1] -= (row[1] - row[0] + 1)/2;
            }
        }
        for (int ii = 7; ii < 10; ii++) //2nd for loop technicaly not needed and could have just had the first one go to 10
        {
            if  (boarding_pass[ii] == 'R') //same process as above but for column.
            {
                column[0] += (column[1] - column[0] + 1)/2;
            }
            else if (boarding_pass[ii] == 'L') //see above
            {
                column[1] -= (column[1] - column[0] + 1)/2;
            }
        }
        id.push_back(row[0] * 8 + column[0]); //adds the ID to the ID vector by pushback, making it so we don't have to pre define the length, formula inside is how ID is calculated
    }
    sort (id.begin(), id.end()); //simple sort
    cout << to_string(id.back()) << endl; //brings me the BIGGEST ID, the first step answer
    for (int i = 1; i < lines; i++) //very simple for loop checks if the previous ID number was NOT 1 less than the current one to find "our" seat
    {
        if (id[i-1] != id[i] - 1)
        {
            cout << to_string(id[i] - 1); //-1 because the i'th seat is the one missing a passenger behind them
        }
    }
}