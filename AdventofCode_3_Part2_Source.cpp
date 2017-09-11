#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
	int counterforcount = 0;
	int sizeofvector = 0;
	int count = 0;
	int impossiblecount = 0;
	int possiblecount = 0;
	double value = 0;
	vector<double> numbers;
	ifstream inputFile;

	inputFile.open("Challenge3Part1.txt");

	if (inputFile)
	{
		cout << "Reading data from file: " << endl;

		while (inputFile >> value)
		{
			numbers.push_back(value);
		}

		sizeofvector = numbers.size();
		cout << "Here is the size of the vector: " << endl;
		cout << sizeofvector << endl;

		while (count < numbers.size())
		{
			if ((count + 8) <= numbers.size())
			{
				if ((numbers[count] + numbers[count + 3]) <= (numbers[count + 6]))
				{
					impossiblecount++;
				}
				else if ((numbers[count] + numbers[count + 6]) <= (numbers[count + 3]))
				{
					impossiblecount++;
				}
				else if ((numbers[count + 3] + numbers[count + 6]) <= numbers[count])
				{
					impossiblecount++;
				}
				else if ((numbers[count] + numbers[count + 3]) > (numbers[count + 6]))
				{
					possiblecount++;
				}
				else if ((numbers[count] + numbers[count + 6]) > numbers[count + 3])
				{
					possiblecount++;
				}
				else if ((numbers[count + 3] + numbers[count + 6]) > numbers[count])
				{
					possiblecount++;
				}
			}
			else if ((count + 7) <= numbers.size())
			{
				if ((numbers[count] + numbers[count + 3]) <= (numbers[count + 6]))
				{
					impossiblecount++;
				}
				else if ((numbers[count] + numbers[count + 6]) <= (numbers[count + 3]))
				{
					impossiblecount++;
				}
				else if ((numbers[count + 3] + numbers[count + 6]) <= numbers[count])
				{
					impossiblecount++;
				}
				else if ((numbers[count] + numbers[count + 3]) > (numbers[count + 6]))
				{
					possiblecount++;
				}
				else if ((numbers[count] + numbers[count + 6]) > numbers[count + 3])
				{
					possiblecount++;
				}
				else if ((numbers[count + 3] + numbers[count + 6]) > numbers[count])
				{
					possiblecount++;
				}
			}
			else if ((count + 6) < numbers.size())
			{
				if ((numbers[count] + numbers[count + 3]) <= (numbers[count + 6]))
				{
					impossiblecount++;
				}
				else if ((numbers[count] + numbers[count + 6]) <= (numbers[count + 3]))
				{
					impossiblecount++;
				}
				else if ((numbers[count + 3] + numbers[count + 6]) <= numbers[count])
				{
					impossiblecount++;
				}
				else if ((numbers[count] + numbers[count + 3]) > (numbers[count + 6]))
				{
					possiblecount++;
				}
				else if ((numbers[count] + numbers[count + 6]) > numbers[count + 3])
				{
					possiblecount++;
				}
				else if ((numbers[count + 3] + numbers[count + 6]) > numbers[count])
				{
					possiblecount++;
				}
			}
			if (counterforcount == 0)
			{
				count++;
				counterforcount++;
			}
			else if (counterforcount == 1)
			{
				count++;
				counterforcount++;
			}
			else if (counterforcount == 2)
			{
				count += 7;
				counterforcount = 0;
			}
		}
	}

	else
	{
		cout << "File opening error has occured." << endl;
	}

	cout << "Here are the total number of triangles assessed: " << endl;
	cout << (impossiblecount + possiblecount) << endl;

	cout << "Here is how many triangles were possible: " << endl;
	cout << possiblecount << endl;

	cout << "Heres how many triangles were impossible: " << endl;
	cout << impossiblecount << endl;

	inputFile.close();

	cin.get();

	return 0;
}