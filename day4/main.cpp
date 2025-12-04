// Advent of Code day4 - Paper rolls
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <chrono>

using namespace std::chrono;

bool valid_roll(std::vector<std::string>& data, int x, int y){
    int rows = data.size();
    int columns = data[0].size();
    
    if(data[y][x] != '@')
    {
        return false;
    }
    int rollCount = 0;
    int radius = 1;
    for(int xOff = std::max(x - radius, 0); xOff < std::min(x + radius + 1, columns); xOff++)
    {
        for(int yOff = std::max(y - radius, 0); yOff < std::min(y + radius + 1, rows); yOff++)
        {
            if(data[yOff][xOff] == '@')
            {
                rollCount++;
            }
        }
    }
    //std::cout << "Rolls near " << x << "," << y << ": " << rollCount << std::endl;
    return rollCount < 5;
}

int part1_count_rolls(std::vector<std::string>& data)
{
    int rows = data.size();
    int columns = data[0].size();

    int validRolls = 0;
    for(int x = 0; x < columns; x++)
    {
        for(int y = 0; y < rows; y++)
        {
            if(valid_roll(data, x, y))
            {
                validRolls++;
            }
        }
    }
    return validRolls;
}

int part2_remove_rolls(std::vector<std::string>& data)
{
    int rows = data.size();
    int columns = data[0].size();

    int radius = 1;
    int validRolls = 0;
    
    int removed_total = 0;
    int round = 0;
    while(true){
        int removed_this_cycle = 0;
        for(int x = 0; x < columns; x++)
        {
            for(int y = 0; y < rows; y++)
            {
                if(data[y][x] != '@')
                {
                    continue;
                }
                if(valid_roll(data, x, y))
                {
                    data[y][x] = '.';
                    removed_this_cycle++;
                    removed_total++;
                }
            }
        }
        //std::cout << "Round " << round++ << ": removed " << removed_this_cycle << std::endl;
        if(removed_this_cycle == 0)
        {
            break;
        }
    }
    return removed_total;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::fstream in_file("data/aoc/day4.txt");
    
    std::vector<std::string> data;
    std::string line;
    while(std::getline(in_file, line))
    {
        data.push_back(line);
    }
    auto rolls = part1_count_rolls(data);
    auto removed = part2_remove_rolls(data);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Total rolls part1: " << rolls << std::endl;
    std::cout << "Removed rolls part2: " << removed << std::endl;

    std::cout << "Time (µs): " << duration.count() << std::endl;

    return 0;
}
