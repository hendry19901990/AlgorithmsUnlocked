#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string addSpaceFront(string s, unsigned long long int num)
{
	string output = "";
	for (unsigned long long int i = 0; i < num; i++)
	{
		output += " ";
	}

	return output + s;
}

vector<string> getArithm(string s)
{
	vector<string> lines(4);
	bool lReturn = true;

	for (unsigned long long int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 48)
		{
			lines[0] += s[i];
		}
		else
		{
			lines[1] += s.substr(i, s.length() - i + 1);
			break;
		}
	}

	unsigned long long int a = stoull(lines[0]), b = stoull(lines[1].substr(1, lines[1].length() - 1));

	if (lines[1][0] == '*')
	{
		lines[3] = to_string(stoull(lines[0]) * stoull(lines[1].substr(lines[1].length() - 1, 1)));

		if (lines[1].length() > 2)
		{
			lReturn = false;
		}
	}
	else if (lines[1][0] == '+')
	{
		lines[3] = to_string(stoull(lines[0]) + stoull(lines[1].substr(1, lines[1].length() - 1)));
	}
	else
	{
		lines[3] = to_string(stoull(lines[0]) - stoull(lines[1].substr(1, lines[1].length() - 1)));
	}

	for (unsigned long long int i = 0; i < max({ lines[0].length(), lines[1].length(), lines[3].length() }); i++)
	{
		lines[2] += "-";
	}

	for (unsigned long long int i = 0; i < 4; i++)
	{
		if (lines[i].length() < lines[2].length())
		{
			lines[i] = addSpaceFront(lines[i], lines[2].length() - lines[i].length());
		}
	}

	if (lReturn)
	{
		return lines;
	}
	else
	{
		string tempLine = lines[1].substr(1, lines[1].length() - 2);
		reverse(tempLine.begin(), tempLine.end());

		unsigned long long int countRes = 3;
		for (unsigned long long int i = 0; i < tempLine.length(); i++)
		{
			string tempS = "";
			unsigned long long int res = lines[countRes].length() - 2;

			tempS = to_string(stoull(lines[0]) * stoull(tempLine.substr(i, 1)));

			if (tempS.length() - 1 > res)
			{
				for (unsigned long long int j = 0; j < lines.size(); j++)
				{
					lines[j] = addSpaceFront(lines[j], tempS.length() - 1 - res);
				}
			}
			else if (tempS.length() - 1 < res)
			{
				tempS = addSpaceFront(tempS, res - (tempS.length() - 1));
			}
			countRes++;

			lines.push_back(tempS);
		}

		string tempAns = "";
		lines.push_back(tempAns);
		tempAns = to_string(a * b);
		lines.push_back(tempAns);

		for (unsigned long long int i = 0; i < max(lines[lines.size() - 1].length(), lines[3].length()); i++)
		{
			lines[lines.size() - 2] += "-";
		}

		return lines;
	}
}

void output(string num)
{
	vector<string> output;
	output = getArithm(num);

	for (unsigned long long int i = 0; i < output.size(); i++)
	{
		cout << output[i] << "\n";
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned long long int numInput;
	cin >> numInput;

	string input;
	for (unsigned long long int i = 0; i < numInput; i++)
	{
		cin >> input;
		output(input);
	}

	return 0;
}