#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        std::string input;
        std::cin >> input;
        char smallest_character = *std::min_element(input.begin(), input.end());
        std::vector<int> indices; 
        indices.reserve(input.length());
        std::size_t pos = input.find(smallest_character);
        // encontrar todos los Indices del carácter más pequeño
        while(pos != std::string::npos){
            indices.emplace_back(pos);
            pos = input.find(smallest_character, pos + 1);
        }
        std::string answer;
        for(int i = 0 ; i != indices.size() ; ++i){
            // construir circulo
            int counter = input.length();
            std::string circular_string;
            int index = indices[i];
            while(counter--){
                circular_string += input[index];
                index = (index + 1) % input.length();
            }
            // comprobar si la cadena es mas pequeña
            if(answer.empty() || circular_string < answer) answer = circular_string;
        }
        std::cout << answer << '\n';
    }
    return 0;
}