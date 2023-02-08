#include <iostream>
#include <string>
using namespace std;

string LongestCommonSubsequence(string R, string S)
{
    string tableLCS[R.length() + 1][S.length() + 1];

    for (int i = 0; i <= R.length(); i++)
    {
        for (int j = 0; j <= S.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                tableLCS[i][j] = "";
            }
            else if (R[i - 1] == S[j - 1])
            {
                tableLCS[i][j] = tableLCS[i - 1][j - 1] + R[i - 1];
            }
            else
            {
                tableLCS[i][j] = tableLCS[i][j - 1].length() > tableLCS[i - 1][j].length() ? tableLCS[i][j - 1] : tableLCS[i - 1][j];
            }
        }
    }

    return tableLCS[R.length()][S.length()];
}

void findSubsequences(string str, string currString)
{
    if (str.empty())
    {
        cout << currString << (" ");
        return;
    }
    findSubsequences(str.substr(1), currString);
    findSubsequences(str.substr(1), currString + str[0]);
}

int main()
{
    // Inputs
    string R = "ACGTTCGA";
    string S = "BCTBBCA";

    // Problem description
    cout << ("\nGiven strings -> R = ") << R << (" | S = ") << S << endl;

    // Finding out LCS
    string LCS;
    cout << ("\nThe LCS of R & S is -> ");
    LCS = LongestCommonSubsequence(R, S);
    cout << LCS << endl;

    // Finding out length of LCS
    int lengthLCS;
    cout << ("\nThe length of LCS is -> ");
    lengthLCS = LCS.length();
    cout << lengthLCS << endl;

    // Finding out all Subsequences of the LCS
    cout << ("\nSubsequences of the LCS are ->") << endl;
    findSubsequences(LCS, "");
    cout << endl;

    // Footer
    cout << ("\nDevanshu Gupta [21BCE0597]\n") << endl;
    return 0;
}