#pragma once

#include <iostream>
#include <string>
#include <set>
used namespace std;

template <typename T>
void findWords(T itBegin, T itEnd)
{
	set<string> words;
	string word = "";
	char truncationSymbol = ' ';
	for (T it = itBegin; it != itEnd; ++it)
	{
		if (*it != truncationSymbol) { word += *it; }
		else if (word != ""){
			words.insert(word);
			word = "";
		}
	}
	if (word != "") { words.insert(word); }
	for (auto it = words.begin(); it != words.end(); ++it)
	{
		cout << *it << " ";
	}
}
