#include "GlobalFunctions.h"
#include "ui_FinalPage.h"

QString GlobalFunctions::QParagraph;
QString GlobalFunctions::allTexts;
QString GlobalFunctions::filePath;
unordered_map<string, int> GlobalFunctions::localFrequencies;
unordered_map<string, int> GlobalFunctions::globalFrequencies;

void GlobalFunctions::writeToFile()
{
	QFile file(filePath);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QTextStream out(&file);
		out << QParagraph;
		file.close();
	}
}

void GlobalFunctions::readFile(const QString& path, QString& text)
{
	QFile file(path);

	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&file);
		text = in.readAll();
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
		QFile file(fileName);

		if (file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QTextStream in(&file);

			allTexts += in.readAll();
			allTexts += "\n";
			
			// get the unicode of the number (i);
			ushort unicodeValue = i.unicode();
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
	// Iterate over each element of the vector
	for (string str : text)
	{
		// Concatenate the current string to the result
		finalPara += str;
		finalPara += " ";
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

	if (flag)
	{
		for (int i = 0; i < delVector.size(); i++)
		{
			paraVector.erase(paraVector.begin() + index);
		}

		string finalPara = vectorToString(paraVector);
		QParagraph = QString::fromStdString(finalPara);
	}
	return index;
}

void GlobalFunctions::autoComplete(const QString& word, QStringListModel* wordsModel, QCompleter* autoCompleter)
{
	QString p = GlobalFunctions::QParagraph;

	// to ignore punctuation marks and split text to words
	QRegularExpression pattern("\\b|\\W");
	QStringList history = p.split(pattern, Qt::SkipEmptyParts);

	QSet<QString> uniqueWords;
	for (const QString& word : history)
	{
		uniqueWords.insert(word);
	}

	QStringList filteredList;
	for (const QString& word : uniqueWords)
	{
		filteredList << word;
	}

	wordsModel->setStringList(filteredList);
	// Set the completion prefix and complete
	autoCompleter->setCompletionPrefix(word);
	autoCompleter->complete();
}

int GlobalFunctions::calculateDistance(const string& word1, const string& word2) {
	int m = word1.size();
	int n = word2.size();

	QVector<QVector<int>> dp(m + 1, QVector<int>(n + 1, 0));

	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == 0) {
				dp[i][j] = j;
			}
			else if (j == 0) {
				dp[i][j] = i;
			}
			else if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = 1 + qMin(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[m][n];
}

// Function to perform autocorrection for the search term
string GlobalFunctions::autoCorrect(const string& searchTerm)
{
	QString text = allTexts.replace("\n", " ").toLower();
	vector<string> dictionary = stringToVector(text.toStdString());
	
	// Threshold for maximum edit distance
	const int maxEditDistance = 3;

	// Vector to store candidate words
	vector<pair<int, string>> candidates;

	// Iterate through each word in the word frequencies map
	for (int i = 0; i < dictionary.size(); i++) {
		const string& word = dictionary[i]; //editDistance
		int distance = calculateDistance(searchTerm, word);

		// If the edit distance is within the threshold, add the word to candidates
		if (distance <= maxEditDistance) {
			candidates.emplace_back(distance, word); // emplace_back(1, 2) = push_back(obj(1, 2) )
		}
	}

	// Sort candidates based on edit distance
	sort(candidates.begin(), candidates.end());

	// Return the closest word if found, otherwise return the original search term
	return candidates.empty() ? searchTerm : candidates[0].second;
}

void GlobalFunctions::autoCorrection(QLineEdit* lineEdit, QString& text)
{
	text = lineEdit->text();
	QString lastWord = GlobalFunctions::getLastWord(text);
	string wordCorrection = GlobalFunctions::autoCorrect(lastWord.toStdString());
	if (lastWord.toStdString() != wordCorrection)
	{
		for (int i = 0; i < lastWord.length(); i++)
		{
			text.removeLast();
		}
		text += wordCorrection + " ";
	}
	lineEdit->clear();
	lineEdit->setText(text);
}

QString GlobalFunctions::getLastWord(const QString& text) {
	// Split the text into individual words
	QStringList words = text.split(QRegularExpression("\\b|\\W"), Qt::SkipEmptyParts);

	// Check if there are any words
	if (!words.isEmpty()) {
		// Return the last word
		return words.last();
	}
	else {
		// Return an empty string if there are no words
		return QString();
	}
}