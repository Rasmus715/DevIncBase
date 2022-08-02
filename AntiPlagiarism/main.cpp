#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

const int SELECTION = 4;
const char separator[] = "{},;.!-?:_%$@^<>()[]*`~=-+\t\n\v\f|}{#};";

double antiPlagiarism (string text, string fragment);
bool isSeparator(char);
string normalize(string text);
bool isSign(char value);
int strLen(string text);
int getThreeWords(string text, char[], int startIndex);
bool strCmp(char src[], char dst[]);


int main()
{
    string input = "-----One thing$%$%$^*@#  $#$#%@@--- I don't      know why  @@@@@@   \n"
                   "It doesn't even matter how hard you try\n"
                   "Keep that in mind, I designed this rhyme\n"
                   "To explain in due time";

    cout << input << endl;

    cout << endl << "Normalizing..." << endl;
    input = normalize(input);
    cout << input << endl;

    string fragment = "I designed this rhyme";

    char words[1024];
    char inputWords[1024];
    int fragmentPos = 0;
    int inputPos = 0;
    int totalComparisons = 0;
    int correctComparisons = 0;

    input = normalize(input);

    cout << endl << "Searching for:" << endl;
    while(fragment[fragmentPos] != 0)
    {
        fragmentPos = getThreeWords(fragment, words, fragmentPos);
        cout << words << endl;
        while(input[inputPos] != 0)
        {
            inputPos = getThreeWords(input, inputWords,inputPos);
            //cout << "Input words: " << inputWords << endl << "words: " << words << endl;

            if(strCmp(inputWords,words))
            {
                correctComparisons++;
                totalComparisons++;
            }
            else
                totalComparisons++;
            memset(inputWords, 0, sizeof inputWords);
        }
        memset(words, 0, sizeof words);
        inputPos = 0;
    }

    //cout << "Total comparisons: " << totalComparisons << endl;
    //cout << "Correct comparisons: " << correctComparisons << endl;

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
    char words[strLen(fragment)];
    int fragmentPos = 0;
    fragment = normalize(fragment);

    while(fragment[fragmentPos] != 0)
    {
        fragmentPos = getThreeWords(fragment, words, fragmentPos);
        cout << words << endl;
        memset(words, 0, sizeof words);
    }

    return 100;
}

string normalize(string text)
{
   int textPos = 0;
   string result;
   for (; text[textPos] != 0; textPos++)
   {
       bool putSpace = false;

       while (isSeparator(text[textPos]))
       {
           if (text[textPos + 1] == '\0')
               return result;

           else if(result != "")
           {
               if(isSign(text[textPos + 1]))
               {
                   result += ' ';
                   textPos++;
                   continue;
               }

           }

           textPos++;
       }


       while (text[textPos] == ' ')
       {
           if(!isSign(text[textPos + 1]))
           {
               textPos++;
               continue;
           }

           if (!putSpace)
           {
               result += ' ';
               putSpace = true;
           }

           if (isSeparator(text[textPos + 1]))
               continue;

           textPos++;
       }

       if (!isSeparator(text[textPos]))
           result += text[textPos];

   }

   return result;
}


//strLen is messed. Better use fixed 1024 size.
int strLen(string text)
{
    int pos;
    while(text[pos] != 0)
        pos++;
    //cout << "Pos: " << pos;
    return pos;
}

bool strCmp(char src[], char dst[])
{
    int i = 0;
    while (src[i] != '\0') {
        if (dst[i] != src[i])
            return false;
        i++;

    }
    return true;
}

int getThreeWords(string text, char words[], int startIndex) {
    int textPos = startIndex;
    int wordsPos = 0;
    int wordsCounter = 0;
    bool firstWordFound = false;
    int firstWordIndex = 0;

    while (wordsCounter < SELECTION)
    {
        if (text[textPos] == 32)
        {
            if(!firstWordFound)
            {
                firstWordFound = true;
                firstWordIndex = textPos + 1;
            }
            wordsCounter++;
        }

        if(wordsCounter == 3)
            break;

        if(text[textPos] == 0)
            return textPos;

        words[wordsPos] = text[textPos];

        wordsPos++;
        textPos++;
    }

    return firstWordIndex;
}

bool isSign(char value)
{
    if((value >= 65 && value <= 90) || (value >= 97 && value <= 122))
        return true;
    else
        return false;
}







