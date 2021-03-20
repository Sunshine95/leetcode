#include<bits/stdc++.h>
using namespace std;

int maxScore;

bool canAdd(string &word, vector<int> &availableLetters)
{

    vector<int> wordHash(26);
    for (int i = 0; i < word.size(); i++)
    {
        int c = word[i] - 'a';
        wordHash[c]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (wordHash[i] > availableLetters[i])
        {
            return false;
        }
    }

    return true;
}

void backtrack(vector<string> &words, int step, vector<int> &availableLetters, vector<int> &score, int nowScore)
{

    if (step >= words.size())
        return ;

    
    // cout << "step " << step << ":\n";
    for (int i = step; i < words.size(); i++)
    {
        string word = words[i];

        if (canAdd(word, availableLetters))
        {
            // cout << "can add " << word << "\t";
            int wordScore = 0;
            for (int j = 0; j < word.size(); j++)
            {
                int ch = word[j] - 'a';
                availableLetters[ch]--;

                wordScore += score[ch];
            }
            nowScore += wordScore;
            // cout << "score: " << nowScore << "\n";
            backtrack(words, i + 1, availableLetters, score, nowScore);
            // cout << "back to step " << step << "\n";
            maxScore = max(nowScore, maxScore);
            // cout << "remove word, " << word << "\n";
            nowScore -= wordScore;
            for (int j = 0; j < word.size(); j++)
            {
                int ch = word[j] - 'a';
                availableLetters[ch]++;
            }
        }
    }
}

int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
{

    maxScore = 0;
    vector<int> availableLetters(26, 0);

    for (int i = 0; i < letters.size(); i++)
        availableLetters[letters[i] - 'a']++;

    backtrack(words, 0, availableLetters, score, 0);

    return maxScore;
}

int main() {

    vector<string> words;
    vector<char> letters;
    vector<int> score;

    words = {"add", "dda", "bb", "ba", "add"};
    letters = {'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'b', 'c', 'c', 'c', 'c', 'c', 'd', 'd', 'd'};
    score = { 3,
              9,
              8,
              9,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0,
              0 };
    maxScoreWords(words, letters, score);

    return 0;
}
