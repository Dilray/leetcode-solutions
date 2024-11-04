#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

string convert(string s, int numRows) {

    if (numRows <= 1) return s;

    vector<string>v(numRows, "");
    uint16_t j = 0; bool b = false;

    for (uint16_t i = 0; i < s.length(); i++)
    {
        if (j == numRows - 1 || j == 0) b = !b;

        v[j] += s[i];

        if (b) j++;
        else j--;
    }
    string res;
    for (auto& it : v) res += it;

    return res;
}

int main()
{
    std::cout << convert("PAYPALISHIRING", 4);
}