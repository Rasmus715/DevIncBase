#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

double antiPlagiarism (string text, string fragment);
bool isSeparator(char);

int getThreeWords(string text, char words[], int textPos);

char separator[] = "!,.;?";

int main()
{
    string input = "amongus. Sus; Vitebsk. Minsk, Grodno, Molode4no";
    cout << input << endl;
    cout << antiPlagiarism(input,"SUS");
    return 0;
}

bool isSeparator(char symbol)
{
    for(int i = 0; separator[i] != '\0'; i++)
        if(separator[i] == symbol)
            return true;
    return false;
}


double antiPlagiarism(string text, string fragment)
{
    int textPos = 0;
    int fragmentPos = 0;
    char words[100];

    while(text[textPos] != '\0')
    {
        textPos = getThreeWords(text, words, textPos);

        cout << words << endl;
    }

    return 100;
}

int normalize(string text, char words[], int textPos)
{
    int wordsCounter = 0;
    int wordsPos = 0;
    int firstWordPos = 0;
    bool firstWordFlag = false;
    for (; wordsCounter < 3; textPos++)
    {
        if (!isSeparator(text[textPos]))
        {
            words[wordsPos] = text[textPos];
        }
        else
        {
            while(isSeparator(text[textPos]))
                textPos++;

            wordsCounter++;
            words[wordsPos] = ' ';
            if (!firstWordFlag)
            {
                firstWordPos = textPos + 1;
                firstWordFlag = true;
            }
        }

        if (text[textPos + 1] == '\0')
            return textPos + 1;

        wordsPos++;
    }

    words[wordsPos + 1] = '\0';
    return firstWordPos + 1;
}




