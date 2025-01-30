#include <array>
#include <iostream>
#include <exception>

using std::cout, std::cin;

int lowScore(std::array<int, 16> scores)
{
    int lowestScore = scores[0];
    int moduleWithLowestScore = 1;

    for (int i = 0; i < scores.size(); i++)
    {
        int score = scores[i];
        if (score < lowestScore)
        {
            lowestScore = score;
            moduleWithLowestScore = i + 1;
        }
    }

    return moduleWithLowestScore;
}

int highScore(std::array<int, 16> scores)
{
    int highestScore = scores[0];
    int moduleWithHighestScore = 1;

    for (int i = 0; i < scores.size(); i++)
    {
        int score = scores[i];
        if (score > highestScore)
        {
            highestScore = score;
            moduleWithHighestScore = i + 1;
        }
    }

    return moduleWithHighestScore;
}

float calculateAverageScore(std::array<int, 16> scores) 
{
    float sum = 0;

    for (const int score : scores)
    {
        sum += score;
    }

    return sum / scores.size();
}

void assertValidRange(int score)
{
    if (score < 0 || score > 15)
    {
        throw std::invalid_argument("Invalid score `" + std::to_string(score) +  "` must be in range 0 <= score <= 15");
    }
}

std::array<int, 16> getData()
{
    
    std::array<int, 16> scores;
    
    cout << "Lets get the score data!\n";
    int scoreIndex = 0;
    while (scoreIndex < scores.size())
    {
        cout << "Week " << (scoreIndex + 1) << ": ";
        int score;
        cin >> score;

        if (cin.fail())
        {
            cout << "Make sure the score is a integer!\n";
            cin.clear();
            cin.ignore();
            continue;
        }


        try
        {
            assertValidRange(score);
        } 
        catch (const std::invalid_argument& e)
        {
            cout << e.what() << '\n';
            continue;
        }

        scores[scoreIndex] = score;
        scoreIndex++;
    }

    return scores;
}

int main()
{
    std::array<int, 16> scores = getData();
    std::cout << lowScore(scores) << '\n';

    for (int i = 0; i < scores.size(); i++)
    {
        std::cout << "Module " << (i + 1) << ": " << scores[i] << '\n';
    }

    cout << '\n';
    cout << "The average score was: " << calculateAverageScore(scores) << '\n';
    cout << "The highest score was: " << highScore(scores) << '\n';
    cout << "The lowest score was: " << lowScore(scores) << '\n';
}