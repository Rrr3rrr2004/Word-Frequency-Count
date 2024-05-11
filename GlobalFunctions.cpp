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

void GlobalFunctions::autoComplete(const QString& word, QStringListModel* wordsModel, QCompleter* autoCompleter)
{
	QString p = GlobalFunctions::QParagraph.toLower();

	// Define a regular expression pattern to match punctuation marks
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
	//completer->setCompletionPrefix(ui->newLine->text());
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
	//QString dict;
	//GlobalFunctions::readFile("./Files/dictionary.txt",dict);

	QString text = allTexts.replace("\n", " ").toLower();
	vector<string> dictionary = stringToVector(text.toStdString());
	
	/*for (QString line : dict)
	{
		dictionary.push_back(line);
	}*/
	//qSort(dictionary);
	
	// Threshold for maximum edit distance
	const int maxEditDistance = 2;

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

// Function to load words from a file into a vector
//QVector<QString> LoadDictionary(const QString& filepath) {
//	QVector<QString> dictionary;
//	QFile file(filepath);
//	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//		qWarning() << "Failed to open file:" << filepath;
//		return dictionary; // Return empty dictionary if file cannot be opened
//	}
//	QTextStream in(&file);
//	while (!in.atEnd()) {
//		QString line = in.readLine();
//		dictionary.append(line);
//	}
//	file.close();
//	qSort(dictionary);
//	return dictionary;
//}