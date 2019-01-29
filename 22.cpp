#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>


std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token.substr(1,token.size() - 2));
   }
   return tokens;
}

int main(){
    std::string name;
    std::cin >> name;

    std::vector<std::string> names = split(name,',');
    std::sort(names.begin(),names.end());
    
    int totalSum = 0;
    for(int i = 1; i <= names.size(); i++){
        int sum = 0;
        for(char c : names[i-1]){
            sum+= (c - 'A') + 1;
        }
        totalSum += sum*i;
    }

    std::cout << totalSum;

    return 0;
}