#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    string myText;
    vector<string> arr;
    vector<string> arr2;

    ifstream MyReadFile("../../sample_and_input_files/aoc1_sample.txt");

    while (getline(MyReadFile, myText))
    {
        arr.push_back(myText);
    }
    for (string i : arr)
    {
        arr2.push_back(i);
    }
    for (int i = 0; i < sizeof(arr2); i++)
    {
        string line = arr2[i];

        for (int j = 0; j <= line.length(); j++)
        {
            char charPerLine = line[j];

            if (iswalpha(charPerLine))
            {
                line.erase(j, 1);
                j = j--;
            }
        }
        cout << line << endl;
    }

    return 0;
}