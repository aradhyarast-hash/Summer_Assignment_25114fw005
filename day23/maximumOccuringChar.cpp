#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string s = "aradhya";

    unordered_map<char, int> freq;

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]]++;
    }

    char elem;
    int maxi = 0;
    for (auto a : freq)
    {
        if (a.second > maxi)
        {
            maxi = a.second;
            elem = a.first;
        }
    }
    cout << "the most occuring character is : " << elem << endl;

    return 0;
}