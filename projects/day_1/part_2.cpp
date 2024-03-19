#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string combindFirstEndDigit(string (&holder)[100])
{
    string result;
    for (string rs : holder)
    {
        result.append(rs);
    }
    if (result.length() > 2)
    {
        for (int j = 0; j < result.length(); j++)
        {
            int numLine = result[j];
            result.erase(j + 1, result.length() - 2);
        }
    }
    if (result.length() == 1)
    {
        result.append(result);
    }
    return result;
}

int main()
{
    string content;
    vector<string> eachLineContainer;
    string dictionary[] = {
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"};
    string temp;
    string digit = "0";
    string number;
    string blank;

    ifstream MyReadFile("../../sample_and_input_files/aoc1_input.txt");

    while (getline(MyReadFile, content))
    {
        eachLineContainer.push_back(content);
    }

    for (string line : eachLineContainer)
    {
        temp = line;
        string holder[100] = {};
        string result;
        for (string dicNum : dictionary)
        {
            size_t found = 1;
            while (found != -1)
            {

                found = temp.find(dicNum);
                if (found != -1)
                {
                    if (digit != "")
                    {
                        if (dicNum == "one" || dicNum == "1")
                            digit = "1";
                        if (dicNum == "two" || dicNum == "2")
                            digit = "2";
                        if (dicNum == "three" || dicNum == "3")
                            digit = "3";
                        if (dicNum == "four" || dicNum == "4")
                            digit = "4";
                        if (dicNum == "five" || dicNum == "5")
                            digit = "5";
                        if (dicNum == "six" || dicNum == "6")
                            digit = "6";
                        if (dicNum == "seven" || dicNum == "7")
                            digit = "7";
                        if (dicNum == "eight" || dicNum == "8")
                            digit = "8";
                        if (dicNum == "nine" || dicNum == "9")
                            digit = "9";

                        if (dicNum == "1" ||
                            dicNum == "2" ||
                            dicNum == "3" ||
                            dicNum == "4" ||
                            dicNum == "5" ||
                            dicNum == "6" ||
                            dicNum == "7" ||
                            dicNum == "8" ||
                            dicNum == "9")
                        {
                            blank = "-";
                        }
                        if (dicNum == "one" ||
                            dicNum == "two" ||
                            dicNum == "six")
                        {
                            blank = "-";
                        }
                        if (dicNum == "four" ||
                            dicNum == "five" ||
                            dicNum == "nine")
                        {
                            blank = "--";
                        }
                        if (dicNum == "three" ||
                            dicNum == "seven" ||
                            dicNum == "eight")
                        {
                            blank = "---";
                        }
                    }
                    if (holder[found] == "")
                    {
                        if (dicNum.length() < 2)
                        {
                            temp = temp.replace(found, dicNum.length(), blank);
                        }
                        else
                        {
                            temp = temp.replace(found + 1, dicNum.length() - 2, blank);
                        }
                        holder[found] = digit;
                    }
                }
            }
        }
        result = combindFirstEndDigit(holder);
        cout << result << endl;
    }
    MyReadFile.close();
}
