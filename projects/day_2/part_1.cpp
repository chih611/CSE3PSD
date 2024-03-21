#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;
bool is_number(const std::string &s)
{
    return (strspn(s.c_str(), "-.0123456789") == s.size());
}
string getPosibilityGame(string gamesInput)
{
    string records;
    string content;

    int pos = gamesInput.find(": ");
    content = gamesInput.substr(pos + 1);
    string after = content;

    try
    {

        while (after.length())
        {
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            int posRevealed = after.find(";");
            if (posRevealed == -1)
            {
                after.insert(after.length(), ";");
                posRevealed = after.find(";");
            }
            string before = after.substr(0, posRevealed);
            after = after.substr(posRevealed + 1, gamesInput.length());
            string afterCube = before;
            while (afterCube.length())
            {
                int posComma = afterCube.find(",");
                if (posComma == -1)
                {
                    afterCube.insert(afterCube.length(), ",");
                    posComma = afterCube.find(",");
                }
                string beforeCube = afterCube.substr(0, posComma);
                afterCube = afterCube.substr(posComma + 1, before.length());

                string numCube = beforeCube.substr(0, 3);

                int postColorCube;

                if (beforeCube.find("blue") != -1)
                    postColorCube = beforeCube.find("blue");
                if (beforeCube.find("red") != -1)
                    postColorCube = beforeCube.find("red");
                if (beforeCube.find("green") != -1)
                    postColorCube = beforeCube.find("green");
                string colorCube = beforeCube.substr(postColorCube, before.length());
                if (stoi(numCube) <= 14 && colorCube == "blue" ||
                    stoi(numCube) <= 13 && colorCube == "green" ||
                    stoi(numCube) <= 12 && colorCube == "red")
                {
                    records = gamesInput;
                    // if (colorCube == "blue")
                    //     sumBlue += stoi(numCube);
                    // if (colorCube == "green")
                    //     sumGreen += stoi(numCube);
                    // if (colorCube == "red")
                    //     sumRed += stoi(numCube);

                    // if (sumBlue <= 14 && sumGreen <= 13 && sumRed <= 12)
                    // {

                    // }
                }
                else
                {
                    records.erase();
                    return records;
                }
            }
        }
    }

    catch (string e)
    {
        cout << e;
    }
    return records;
}

int main()
{
    string content;
    vector<string> eachLineContainer;
    vector<string> container;

    ifstream MyReadFile("../../sample_and_input_files/aoc2_sample.txt");

    while (getline(MyReadFile, content))
    {
        eachLineContainer.push_back(content);
    }
    for (string i : eachLineContainer)
    {
        container.push_back(getPosibilityGame(i));
    }
    int sumID = 0;
    for (string c : container)
    {
        if (c != "")
        {
            // int posIDGame = c.find(":");
            // string IDGame = c.substr(posIDGame - 2, posIDGame-1);
            char IDGameChar = c.at(5);
            int IDGame = int(IDGameChar - '0');
            sumID = sumID + IDGame;
            cout << c << endl;
        }
    }
    cout << sumID;

    MyReadFile.close();
}