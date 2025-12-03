// Advent of Code day3 - Joltage calculation
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

long long calc_joltage(std::vector<int>& data, int num_digits)
{
    std::vector<long long> digits;
    
    int pos = -1;
    for(int d = 0; d < num_digits; d++){
        int digit = -1;
        for(int i = pos + 1; i < data.size() - num_digits + d + 1; i++)
        {
            if(data[i] > digit)
            {
                pos = i;
                digit = data[i];
            }
        }
        digits.push_back(digit);
    }

    long long total = 0;
    for(int d = 0; d < num_digits; d++){
        total *= 10;
        total += digits[d];
        std::cout << digits[d];
    }
    std::cout << std::endl;

    return total;
}

int main() {
    std::fstream in_file("data/aoc/day3.txt");

    std::string line;

    long long total_joltage_p1 = 0;
    long long total_joltage_p2 = 0;
    while(std::getline(in_file, line))
    {
        std::vector<int> data;
        for(int i = 0; i < line.length(); i++)
        {
            data.push_back(line[i]-'0');
        }
        total_joltage_p1 += calc_joltage(data, 2);
        total_joltage_p2 += calc_joltage(data, 12);
    }
    std::cout << "Total joltage part1: " << total_joltage_p1 << std::endl;
    std::cout << "Total joltage part2: " << total_joltage_p2 << std::endl;

    return 0;
}
