#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;
set<string> dict;
int main()
{
    string s, buf;
    while (cin >> s && s != "end")
    {
        for (size_t i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';
        }
        stringstream ss(s);
        while(ss >> buf)
            dict.insert(buf);
    }
    for (set<string>::iterator i = dict.begin(); i != dict.end(); i++)
        cout << *i << endl;
    system("pause");
    return 0;
}
