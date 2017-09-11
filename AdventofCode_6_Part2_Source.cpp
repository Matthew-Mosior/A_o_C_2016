#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;

int main()
{
	string input;
	ifstream inputFile;
	vector<char> letters;
	int sizeofvector;
	char inputchar;
	vector<int> counterarray = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int columncounter = 0;
	int indexcounter = 0;
	int count = 0;
	vector<int>::iterator i;

	inputFile.open("Challenge6Part1.txt");

	if (inputFile)
	{
		cout << "Reading data from file: " << endl;

		while (inputFile >> inputchar)
		{
			letters.push_back(inputchar);
		}

		sizeofvector = letters.size();
		cout << "Here is the size of the vector: " << endl;
		cout << sizeofvector << endl;

		cout << "Here is the saturated vector of letters: " << endl;
		for (int i = 0; i < letters.size(); i++)
		{
			cout << letters[i];
		}

		cout << endl;
		cout << endl;

		while (columncounter <= 7)
		{
			for (int i = count; i < (letters.size() - (7 - columncounter)); i += 8)
			{
				switch (letters[i])
				{
				case 'a': counterarray[0] += 1;
					break;
				case 'b': counterarray[1] += 1;
					break;
				case 'c': counterarray[2] += 1;
					break;
				case 'd': counterarray[3] += 1;
					break;
				case 'e': counterarray[4] += 1;
					break;
				case 'f': counterarray[5] += 1;
					break;
				case 'g': counterarray[6] += 1;
					break;
				case 'h': counterarray[7] += 1;
					break;
				case 'i': counterarray[8] += 1;
					break;
				case 'j': counterarray[9] += 1;
					break;
				case 'k': counterarray[10] += 1;
					break;
				case 'l': counterarray[11] += 1;
					break;
				case 'm': counterarray[12] += 1;
					break;
				case 'n': counterarray[13] += 1;
					break;
				case 'o': counterarray[14] += 1;
					break;
				case 'p': counterarray[15] += 1;
					break;
				case 'q': counterarray[16] += 1;
					break;
				case 'r': counterarray[17] += 1;
					break;
				case 's': counterarray[18] += 1;
					break;
				case 't': counterarray[19] += 1;
					break;
				case 'u': counterarray[20] += 1;
					break;
				case 'v': counterarray[21] += 1;
					break;
				case 'w': counterarray[22] += 1;
					break;
				case 'x': counterarray[23] += 1;
					break;
				case 'y': counterarray[24] += 1;
					break;
				case 'z': counterarray[25] += 1;
					break;
				}
			}

			count++;
			columncounter++;
			cout << "You have read through column " << columncounter << " of 8." << endl;

			auto smallest = min_element(counterarray.begin(), counterarray.end());
			cout << "Here is the least common letter in column " << columncounter << ": " << *smallest << endl;
			cout << endl;

			cout << "Finding position of smallest element of counterarray in column " << columncounter << ": " << endl;
			auto position = distance(counterarray.begin(), smallest);
			cout << "Found smallest at position " << position << "." << endl;
			cout << endl;

			cout << "Here is the counter array after reading column " << columncounter << ": " << endl;
			for (int j = 0; j < counterarray.size(); j++)
			{
				cout << counterarray[j] << " ";
			}

			cout << endl;
			cout << endl;

			counterarray = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		}
	}
	else
	{
		cout << "File opening error. " << endl;
	}

	cin.get();
	return 0;
}