/* This code provides the pattern matches using Naïve String-
Matching Algorithm as well as KMP String-Matching Algorithm. */

#include <iostream>
#include <string>
using namespace std;

void NaiveStringMatcher(string, string);
void KMPMatcher(string, string);
int *ComputePrefixFunction(string);

int main()
{
    string text, pattern;
    cout << endl;
    cout << "Enter the text string: " << endl;
    cin >> text;
    cout << "Enter the pattern string: " << endl;
    cin >> pattern;
    cout << endl;

    cout << "Using Naive String Matching Algorithm:" << endl;
    NaiveStringMatcher(text, pattern);
    cout << endl;

    cout << "Using KMP String Matching Algorithm:" << endl;
    KMPMatcher(text, pattern);
    cout << endl;

    cout << "Devanshu Gupta 21BCE0597\n" << endl;
    return 0;
}

// Naive String Matching Function
void NaiveStringMatcher(string text, string pattern)
{
    int tLength = text.length();
    int pLength = pattern.length();

    for (int shift = 0; shift <= tLength - pLength; shift++)
    {
        int index;
        for (index = 0; index < pLength; index++)
        {
            if (pattern[index] != text[index + shift])
            {
                break;
            }
        }
        if (index == pLength)
        {
            cout << "=> Pattern occurs with shift = " << shift << endl;
        }
    }
}

// KMP String Matching Functions
int *ComputePrefixFunction(string pattern, int pLength)
{
    int *piTable = new int[pLength];
    piTable[0] = 0;

    int k = 0;

    for (int q = 1; q < pLength; q++)
    {
        while ((k > 0) && (pattern[k] != pattern[q]))
        {
            k = piTable[k - 1];
        }
        if (pattern[k] == pattern[q])
        {
            k = k + 1;
        }
        piTable[q] = k;
    }

    return piTable;
}
void KMPMatcher(string text, string pattern)
{
    int tLength = text.length();
    int pLength = pattern.length();
    int *piTable = ComputePrefixFunction(pattern, pLength);
    int q = 0;

    for (int i = 0; i < tLength; i++)
    {
        while ((q > 0) && (pattern[q] != text[i]))
        {
            q = piTable[q - 1];
        }
        if (pattern[q] == text[i])
        {
            q = q + 1;
        }
        if (q == pLength)
        {
            cout << "=> Pattern occurs with shift = " << i - pLength + 1 << endl;
            q = piTable[q - 1];
        }
    }
}