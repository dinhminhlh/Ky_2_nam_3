#include <iostream>
using namespace std;

string PermutationEncyption(string input, int key)
{
	string output = "";
	int i = 0, j = 0, len_out = 0, len_in = input.length();
	while (i < key)
	{
		j = i;
		while (j < len_in)
		{
			output += input[j];
			j += key;
		}
		i++;
	}
	return output;
}

int main()
{
	string input;
	int key;

	cout << "Nhap input: ";
	cin >> input;
	cout << "Nhap key: ";
	cin >> key;

	cout << "\nInput: " << input << "\nKey: " << key << endl;
	input = PermutationEncyption(input, key);
	cout << "\nPermutation Encyption: " << input << endl;
}
