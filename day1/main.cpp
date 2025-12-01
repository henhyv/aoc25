// Advent of Code day1
#include <iostream>
#include <fstream>

int main() {
    std::fstream in_file("data/aoc/day1.txt");
    
    int dial = 50;
    int zeroes_part1 = 0;
    int zeroes_part2 = 0;
    std::string rotation;
    while(std::getline(in_file, rotation))
    {
        int sign = rotation[0] == 'R' ? 1 : -1;
        int abs_rota = std::stoi(rotation.substr(1));

        for(int i = 0; i < abs_rota; i++)
        {
            dial += sign;
            if(dial % 100 == 0)
            {
                zeroes_part2++;
            }
        }
        
        if(dial % 100 == 0)
        {   
            zeroes_part1++;
        }
    }
    std::cout << "Part 1 - zeroes after rotation: " << zeroes_part1 << std::endl;;
    std::cout << "Part 2 - zeroes during/after rotation: " << zeroes_part2 << std::endl;;

    return 0;
}
