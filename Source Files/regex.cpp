#include <iostream>
#include <string>
#include <memory>
#include <stdio.h>
#include <regex>
#include <vector>
#include <sstream>
#include <ctype.h>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
int main()
{	
	stringstream ss;
	string str, newstr;
	smatch mt1, mt2; 
	while(getline(std::cin, str))
	{
		ss << str;
	}
	str.clear();
	while(ss >> str) 
	{
		newstr += str;
	}
	regex pattern1("<([[:w:]]+)>", regex_constant::icase);
	regex pattern2("</([[:w:]]+)>");
	bool found = regex_match(newstr, pattern1);
	bool submatch_str = regex_search(newstr, mt2, pattern2);
	cout << mt1.prefix().str() << mt1.suffix().str();
	sregex_token_iterator tok_start(newstr.cbegin(), newstr.cend(), pattern1, 1);
	sregex_token_iterator tok_end;
	// regex_replace(newstr, pattern1, "$1 is on $2");
	sregex_iterator DOM_open_start(newstr.cbegin(), newstr.cend(), pattern1);
	sregex_iterator DOM_end_start(newstr.cbegin(), newstr.cend(), pattern2);
	sregex_iterator end;
	for(; DOM_open_start != end, DOM_end_start != end; DOM_open_start++, DOM_end_start++)
	{
		cout << endl;
		cout << "<parseTreeNode>" << endl;
		cout << "	<start> ";
		cout << " Start Match Tag ::" << DOM_open_start->str(0);
		cout << " 	</start> ";
		cout << endl << "	<DOMElem> "; 
		cout << "  Qualified DOM Element : " << DOM_open_start->str(1);
		cout << "	</DOMElem> "; 
		DOMElementsMap.emplace(i++, DOM_open_start->str(0));
		cout << endl << "	<end>";
		cout << " End Match Tag ::" << DOM_end_start->str(0);
		cout << "	</end> ";
		cout << endl << "	<DOMElem> "; 
		cout << "  Qualified DOM Element : " << DOM_end_start->str(1);
		cout << "	</DOMElem> " << endl; 
		DOMElementsMap.emplace(i++, DOM_end_start->str(0));
		cout << "</parseTreeNode>" << endl;
	}
	return 0;
}