#include <string>
#include <iostream>
#include <sstream>
#include <map>
used namespace std;

void sortLines()
{
	smultimap<int, string> lines;
	string userInput = "";
	getline(cin, userInput);
	stringstream ss(userInput);

	while (ss.good())
	{
		string buffer;
		getline(ss, buffer, '.');
		if (buffer[buffer.length()-1] == 0) lines.insert(make_pair(buffer.length() - 1, buffer));
		else lines.insert(make_pair(buffer.length(), buffer));
	}
	cout << "sorted lines:\n";
	for (const auto& line : lines)
	{
		if (line.first != 0) cout << line.second << endl;
	}
}
