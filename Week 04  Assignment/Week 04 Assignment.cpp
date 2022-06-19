#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//set up constant variables
const int TITLE_SIZE = 60;
const char TITLE_CHAR = '*', VOWEL_CHAR = '.';
const string TITLE_WORDS = " Welcome to my Letter Count Program ";

int main(int argc, char* argv[])
{
	//declare variables
	int titleBorderSize = 0, aCounter = 0, eCounter = 0,
		iCounter = 0, oCounter = 0, uCounter = 0, chCounter = 0, vowelCounter = 0,
		jCounter = 0, mCounter = 0, lCounter = 0;
	char currentCh = ' ';
	string outString = " ", inString;

	//display title 
	titleBorderSize = (TITLE_SIZE - TITLE_WORDS.length()) / 2;
	cout << setfill(TITLE_CHAR);
	cout << setw(TITLE_SIZE) << TITLE_CHAR << endl;
	cout << setw(titleBorderSize) << TITLE_CHAR;
	cout << TITLE_WORDS;
	cout << setw(titleBorderSize) << TITLE_CHAR << endl;
	cout << setw(TITLE_SIZE) << TITLE_CHAR << endl << endl;

	
	

	// The executable name and at least one argument?
	if (argc < 2)
	{
		cout << "Error with input agrs.." << std::endl;
		return 1;
	}

	// For debugging purposes only
	/* for (int i = 0; i < argc; i++)
	{
		std::cout << i << ":" << argv[i] << std::endl;
	}
	*/

	ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile)
	{
		cout << "Error with file name.." << std::endl;
		return 1;
	}

	///////////////////////
	// Work here with open file.....
	///////////////////////

	cout << "Analyzing file '" << argv[1] << "'..." << endl << endl;

	//loop through the file characters and test whether it is a vowel or not
	//it also sorts out which vowel it is if it is a vowel

	//Extra three characters: j, m, and l

	while (inFile)
	{

	//	Didn't use:
	//  inFile.get()
	//	getline(inFile, inString);
	//	currentCh = inString[chCounter];

		inFile.get(currentCh);

		switch (currentCh)
		{
		case 'a':
		case 'A':
			aCounter++;
			break;
		case 'e':
		case 'E':
			eCounter++;
			break;
		case 'i':
		case 'I':
			iCounter++;
			break;
		case 'o':
		case 'O':
			oCounter++;
			break;
		case 'u':
		case 'U':
			uCounter++;
			break;
		case 'j':
		case 'J':
			jCounter++;
			break;
		case 'm':
		case 'M':
			mCounter++;
			break;
		case 'l':
		case 'L':
			lCounter++;
			break;
		default:
			break;
		}
		chCounter++;
	}
	//calculates the total number of vowels
	vowelCounter = aCounter + eCounter + iCounter + oCounter + uCounter + jCounter + mCounter + lCounter;

	//outputs the appropriate formatting an the number of each vowel and the total number of vowels
	outString = "The number of A's: ";
	cout << setfill(VOWEL_CHAR);
	cout << outString << setw(TITLE_SIZE - outString.length()) << VOWEL_CHAR << aCounter << endl;
	
	outString = "The number of E's: ";
	cout << outString << setw(TITLE_SIZE - outString.length()) << VOWEL_CHAR << eCounter << endl;

	outString = "The number of I's: ";
	cout << outString << setw(TITLE_SIZE - outString.length()) << VOWEL_CHAR << iCounter << endl;

	outString = "The number of O's: ";
	cout << outString << setw(TITLE_SIZE - outString.length()) << VOWEL_CHAR << oCounter << endl;

	outString = "The number of U's: ";
	cout << outString << setw(TITLE_SIZE - outString.length()) << VOWEL_CHAR << uCounter << endl;

	outString = "The number of J's: ";
	cout << outString << setw(TITLE_SIZE - outString.length()) << VOWEL_CHAR << jCounter << endl;

	outString = "The number of M's: ";
	cout << outString << setw(TITLE_SIZE - outString.length()) << VOWEL_CHAR << mCounter << endl;

	outString = "The number of L's: ";
	cout << outString << setw(TITLE_SIZE - outString.length()) << VOWEL_CHAR << lCounter << endl;

	outString = "The vowel count is: ";
	cout << outString << setw(TITLE_SIZE - outString.length()) << VOWEL_CHAR << vowelCounter << endl;

	inFile.close();

	system("pause");

	return 0;
}

