#include "GlobalFunctions.h"
#include "ui_FinalPage.h"

QString GlobalFunctions::QParagraph;
//string GlobalFunctions::paragraph;
QString GlobalFunctions::allTexts;
QString GlobalFunctions::filePath;
unordered_map<string, int> GlobalFunctions::localFrequencies;
unordered_map<string, int> GlobalFunctions::globalFrequencies;

void GlobalFunctions::writeToFile()
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

void GlobalFunctions::readFile()
{
	QFile file(filePath);

	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&file);

		QParagraph = in.readAll();
		// store the Paragraph that in the file in paragraph after convert it to string
		/*QString fileContentEdited = QParagraph;
		fileContentEdited.replace("\n", " ");
		fileContentEdited = fileContentEdited.toLower();
		paragraph = fileContentEdited.toStdString();*/

		file.close();
	}
}

void GlobalFunctions::readAllTexts()
{
	QString fileName = "./Files/text.txt";
	QChar i('1');
	while (true)
	{
		fileName.insert(12, i);
		//fileName.append(12, i);
		QFile file(fileName);

		if (file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QTextStream in(&file);

			allTexts += in.readAll();
			allTexts += "\n";
			// store the Paragraph that in the file in paragraph after convert it to string
			
			// Get the Unicode value of the character
			ushort unicodeValue = i.unicode();

			// Increment the Unicode value
			unicodeValue++;

			i = unicodeValue++;
			fileName.remove(12, 1);
			file.close();
		}
		else
		{
			break;
		}
	}
}

vector<string> GlobalFunctions::stringToVector(string text)
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

unordered_map<string, int> GlobalFunctions::countWordFrequency(QString text)
{
	string stext = text.replace("\n", " ").toLower().toStdString();

	unordered_map<string, int> wordFrequency;
	vector<string> words;
	string textEdited;
	bool inWord = false;

	for (char ch : stext)
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

string GlobalFunctions::vectorToString(vector<string> text)
{
	string finalPara;
	int n = 0;
	// Iterate over each element of the vector
	for (string str : text)
	{
		// Concatenate the current string to the result
		finalPara += str;
		finalPara += " ";
		if (n == 18)
		{
			finalPara += '\n';
			n = 0;
		}
		n++;
	}
	return finalPara;
}

int GlobalFunctions::deleteFromText(const QString& text, bool& flag)
{
	string sDelText = text.toLower().toStdString();
	vector<string> delVector = GlobalFunctions::stringToVector(sDelText);
	string paragraph = GlobalFunctions::QParagraph.toLower().replace("\n", " ").toStdString();
	vector<string> paraVector = GlobalFunctions::stringToVector(paragraph);

	int index = -1;
	for (int i = 0; i < paraVector.size(); i++)
	{
		if (paraVector[i] == delVector[0])
		{
			index = i;
			for (int j = 0; j < delVector.size(); j++)
			{
				if (paraVector[i] == delVector[j])
				{
					flag = true;
					i++;
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
		{
			break;
		}
	}

	//if (!flag)
	//{
		//QMessageBox::information(this, "Warning!!", QString::fromStdString(sDelText) + "\nIS NOT VALID IN YOUR TEXT!!\nPlease, Enter another Sentance");
	//}
	if (flag)
	{
		//QMessageBox::information(this, "Congratulation", "The Sentance Is Updated");
		for (int i = 0; i < delVector.size(); i++)
		{
			paraVector.erase(paraVector.begin() + index);
		}

		string finalPara = vectorToString(paraVector);
		QParagraph = QString::fromStdString(finalPara);
	}
	return index;
}

