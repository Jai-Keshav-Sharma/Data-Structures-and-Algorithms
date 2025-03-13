#include <bits/stdc++.h> 
using namespace std;

void solve(string str, string output, int index, vector<string>& ans)
{
	if(index >= str.length())
	{
		if(output.length() > 0)
		{
			ans.push_back(output);
		}
		return;
	}

	//exlude
	solve(str, output, index + 1, ans);

	//include
	char element = str[index];
	output.push_back(element);

	solve(str, output, index + 1, ans);
}

int main()
{
    string str = "abc";
    vector<string> ans;
	string output = "";
	int index = 0;

	solve(str, output, index, ans);

    for(string each : ans)
    {
        cout << each << endl;
    }

    return 0;
}
