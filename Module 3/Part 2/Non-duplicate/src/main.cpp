#include <iostream>
#include <fstream>
#include <set>

using std::cout;

int main()
{
    std::ifstream file("words.txt");

    if (!file) 
    {
        cout << "Unable to open file!\n";
        return 1;
    }


    std::string word;
    std::set<std::string> wordSet;

    while (file >> word) 
    {
        wordSet.insert(word);
    }

    for (const auto word : wordSet) 
    {
        cout << word << '\n';
    }

    file.close();
}