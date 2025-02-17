#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"  // Include the given Stack class

using namespace std;

// Function to convert string to lowercase
string toLowerCase(const string& str) 
{
    string result = str;
    for (char& ch : result)
    {
        ch = tolower(ch);
    }
    return result;
}

// Function to check if a word is a palindrome using Stack
bool isPalindrome(const string& word)
{
    Stack stack(word.length()); // Create a stack of appropriate size

    // Push characters of the word onto the stack
    for (char ch : word)
    {
        stack.Push(ch);
    }

    // Pop characters and compare with original word
    for (char ch : word)
    {
        char topChar;
        stack.Pop(topChar); // Pop from stack
        if (topChar != ch)
        {
            return false; // If mismatch found, not a palindrome
        }
    }

    return true; // If all characters match, it's a palindrome
}

int main()
{
    ifstream file("words.txt");  // Open the input file
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string word;
    int palindromeCount = 0;

    while (file >> word)
    {  // Read words one by one
        string lowerWord = toLowerCase(word); // Convert to lowercase
        if (isPalindrome(lowerWord))
        {
            palindromeCount++;
        }
    }

    file.close(); // Close the file

    cout << "Total palindrome words found: " << palindromeCount << endl;

    return 0;
}
