#include <iostream>
#include "string_algorithms.h"


void word_backwards()
{
    std::string word;
    int word_size;

    std::cout << "enter word to print backwards:\n";
    std::cin >> word;
    word_size = word.length();

    for (int i = word_size - 1; i >= 0; i--)
        std::cout << word[i];

    if (palindrome_word_check(word))
        std::cout << "\nit is palindrome";

    std::cout << '\n';
}

bool palindrome_word_check(std::string word)
{
    bool palindrome = true;
    int word_size = word.length();

    for (int i = 0; i < word_size / 2; i++)
        if (word[i] != word[word_size - 1 - i])
        {
            palindrome = false;
            break;
        }
    return palindrome;
}

void palindrome_word_check()
{
    std::string word;
    int word_size;

    std::cout << "enter word to print palindrome test:\n";
    std::cin >> word;
    word_size = word.length();
    if (palindrome_word_check(word))
        std::cout << "it is palindrome";
    else
        std::cout << "it is not palindrome";

    std::cout << '\n';
}