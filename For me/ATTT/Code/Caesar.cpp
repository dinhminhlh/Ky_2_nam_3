#include <iostream>
using namespace std;

string encrypt(string text, int key)
{
	string result = "";

	for (int i = 0; i < text.length(); i++)
	{
		if (isupper(text[i]))
			result += char(int(text[i] + key - 65) % 26 + 65);
		else
			result += char(int(text[i] + key - 97) % 26 + 97);
	}

	return result;
}

int main()
{
	string input;
	int key;

	cout << "Nhap input: ";
	cin >> input;
	cout << "Nhap key: ";
	cin >> key;

	cout << "\nInput : " << input;
	cout << "\nKey: " << key;

	cout << "\nCipher: " << encrypt(input, key);
	return 0;
}
