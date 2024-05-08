#include "GlobalFunctions.h"

QString GlobalFunctions::QParagraph;
string GlobalFunctions::paragraph;
string GlobalFunctions::allTexts;
QString GlobalFunctions::filePath;
unordered_map<string, int> GlobalFunctions::localFrequencies;
unordered_map<string, int> GlobalFunctions::globalFrequencies;

void GlobalFunctions::writeToFile(const QString& filePath)
{
	QFile file(filePath);
	// Open the file in write mode
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		// Create a QTextStream to write to the file
		QTextStream out(&file);
		// Write the data to the file
		out << QParagraph;
		// Close the file
		file.close();
	}
}

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

unordered_map<string, int> GlobalFunctions::countWordFrequency(const string& text)
{
	unordered_map<string, int> wordFrequency;
	vector<string> words;
	string textEdited;
	bool inWord = false;

	for (char ch : text)
	{
		// ignore the punctuation marks from the paragraph
		if (!ispunct(ch))
		{
			textEdited += ch;
		}
	}

	// convert the text to vector of string
	words = stringToVector(textEdited);

	// count the frequency of each word
	for (int i = 0; i < words.size(); i++)
	{
		wordFrequency[words[i]]++;
	}
	return wordFrequency;
}