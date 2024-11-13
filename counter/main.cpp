#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int countSentences(string a)
{
  int sentences = 0;

  for (char c : a)
  {
    if (c == '.' || c == '?' || c == '!')
    {
      sentences++;
    }
  }

  return sentences;
}

int countLetters(string a)
{
  int letters = 0;

  for (int i = 0; i < a.length(); i++)
  {
    if (isalpha(a[i]))
    {
      letters++;
    }
  }

  return letters;
}

int countWords(string a)
{
  int words = 0;
  string word;
  stringstream s(a);

  while (s >> word)
  {
    words++;
  }

  return words;
}

void countMostUsedCharacter(string a)
{
  int highest = 0;
  char mostUsedLetter;
  map<char, int> mostUsed;

  for (char c : a)
  {
    if (isalpha(c))
    {
      mostUsed[c]++;
    }
  }

  for (const auto &pair : mostUsed)
  {
    if (pair.second > highest)
    {
      highest = pair.second;
      mostUsedLetter = pair.first;
    }
  }

  cout << "Most used letter: '" << mostUsedLetter << "' used: " << highest << " times" << endl;
}

int main()
{
  string x;

  cout << "x: ";
  getline(cin, x);
  transform(x.begin(), x.end(), x.begin(), ::tolower);

  // RESULTS
  cout << "Letters: " << countLetters(x) << endl;
  cout << "Sentences: " << countSentences(x) << endl;
  cout << "Words: " << countWords(x) << endl;
  countMostUsedCharacter(x);

  return 0;
}
