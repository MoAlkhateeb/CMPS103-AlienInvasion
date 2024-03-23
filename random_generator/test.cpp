#include<iostream>
#include<random>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;



vector<int> readnumbers(const string& input){
    vector<int> numbers;
    istringstream iss(input);
    int num;
    string line;
    while (iss >> num)
    {
        for (int i = 0; i < line.size(); i++){
            if(line[i] != '-' || line[i] != ' '){
                numbers.push_back(num);
            }
        }
    return numbers;
    }
        return numbers;
}
int main()
{
    string input = "1-2 3-4 5-6";
    vector<int> numbers = readnumbers(input);
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    return 0;
}
