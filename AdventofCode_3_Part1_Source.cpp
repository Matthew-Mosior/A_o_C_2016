#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
	int sizeofvector = 0;
	int count = 0;
	int impossiblecount = 0;
	int possiblecount = 0;
	int i = 0;
	double value = 0;
	vector<double> numbers;
	int numberofvalues;
	numberofvalues = numbers.size();
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
			if ((count < numbers.size()) && ((count + 1) < numbers.size()) && ((count + 2) <= numbers.size()))
			{
				if ((numbers[count] + numbers[count + 1]) <= (numbers[count + 2]))
				{
					impossiblecount++;
				}
				else if ((numbers[count] + numbers[count + 2]) <= (numbers[count + 1]))
				{
					impossiblecount++;
				}
				else if ((numbers[count + 1] + numbers[count + 2]) <= numbers[count])
				{
					impossiblecount++;
				}
				else if ((numbers[count] + numbers[count + 1]) > (numbers[count + 2]))
				{
					possiblecount++;
				}
				else if ((numbers[count] + numbers[count + 2]) > numbers[count + 1])
				{
					possiblecount++;
				}
				else if ((numbers[count + 1] + numbers[count + 2]) > numbers[count])
				{
					possiblecount++;
				}
			}
			count += 3;
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