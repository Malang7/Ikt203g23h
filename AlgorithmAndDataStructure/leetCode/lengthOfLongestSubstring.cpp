#include <iostream>
#include <string>
#include <unordered_set>
#include <vector> 

using namespace std;

class solutions
{
public:
    int lengthOfLongestSubstring(string &myString)
    {
        if (myString.empty())
        {
            cout << "Empty input" << endl;
            return 0;
        }

        unordered_set<char> result;
        int lengthOfLongest = 0;
        int start = 0;
        int end = 0;

        while (start < myString.size())
        {
            if (result.find(myString[start]) == result.end())
            {
                result.insert(myString[start]);
                lengthOfLongest = max(lengthOfLongest, start - end + 1);
                start++;
            }
            else
            {
                result.erase(myString[end]);
                end++;
            }
        }

        return lengthOfLongest;
    }

};

int main()
{
    solutions s1;
    string test = "abbbcc";
    int length = s1.lengthOfLongestSubstring2(test);
    cout << "The length of the longest substring is: " << length << endl;



    return 0;
}
