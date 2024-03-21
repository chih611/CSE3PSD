#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

int main()
{
    string content;
    vector<string> eachLineContainer;
    vector<int> resultInt;

    ifstream MyReadFile("../../sample_and_input_files/aoc1_input.txt");

    while (getline(MyReadFile, content))
    {
        eachLineContainer.push_back(content);
    }
    for (string i : eachLineContainer)
    {
        string line = i;

        if (line != "")
        {
            for (int j = 0; j < line.length(); j++)
            {
                char charPerLine = line[j];

                if (iswalpha(charPerLine))
                {
                    line.erase(j, 1);
                    j = j--;
                }
            }
        }

        if (line.length() > 2)
        {
            for (int j = 0; j < line.length(); j++)
            {
                int numLine = line[j];
                line.erase(j + 1, line.length() - 2);
            }
        }
        if (line.length() == 1)
        {
            line.append(line);
        }
        resultInt.push_back(stoi(line));
        // cout << line << endl;
    }
    cout << accumulate(resultInt.begin(), resultInt.end(), 0);
    MyReadFile.close();
}