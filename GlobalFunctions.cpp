#include "GlobalFunctions.h"


QString GlobalFunctions::QParagraph = "";
string GlobalFunctions::paragraph = "";
QString GlobalFunctions::filePath = "";

vector<string> GlobalFunctions::stringToVector(const string& text)
{
	vector<string> words;
	string word;
	bool inWord = false;
	for (char ch : text)
	{
		// Check if the character is a space
		if (ch == ' ')
		{
			// If we are already in a word, add it to the vector
			if (inWord)
			{
				words.push_back(word);
				word.clear();
				inWord = false;
			}
		}
		else
		{
			// If not a space , add the character to the current word
			word += ch; //basmala
			inWord = true;
		}
	}

	// Add the last word if it exists
	if (!word.empty())
	{
		words.push_back(word);
	}

	return words;
}

void GlobalFunctions::countWordFrequency()
{
	unordered_map<string, int> myCounter;
	vector<string> words;
	string text;
	bool inWord = false;
	//string word;

	for (char ch : paragraph)
	{
		// ignore the punctuation marks from the paragraph
		if (!ispunct(ch))
		{
			text += ch;
		}
	}

	// convert the text to vector of string
	words = stringToVector(text);

	// count the frequency of each word
	for (int i = 0; i < words.size(); i++)
	{
		myCounter[words[i]]++;
	}
}