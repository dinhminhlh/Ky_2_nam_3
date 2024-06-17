#include <iostream>
using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string repeatKey(string input, string key)
{
	string newKey = key;
	int length = input.length();

	while (newKey.length() < length)
	{
		for (int i = 0; i < length; i++)
		{
			newKey += input[i];
			if (newKey.length() == length)
				break;
		}
	}

	return newKey;
}

int position(char c)
{
	if (c > 'Z')
		return c - 'a';
	return c - 'A';
}

string VigenereEncryption(string input, string key)
{
	string cipher = "";
	int p, k, c;

	for (int i = 0; i < input.length(); i++)
	{
		p = position(input[i]);
		k = position(key[i]);
		c = (p + k) % 26;
		cipher += alphabet[c];
	}

	return cipher;
}

int main()
{
	string input, k, key;
	int length;

	cout << "Nhap input: ";
	cin >> input;
	cout << "Nhap key: ";
	cin >> key;

	cout << "\nInput: " << input << "\nKey: " << key << endl;

	string newKey;
	newKey = repeatKey(input, key);

	cout << "\nNew Key: " << newKey << endl;

	string res = VigenereEncryption(input, newKey);

	cout << "\nVigenere Encryption: " << res << endl;
}
