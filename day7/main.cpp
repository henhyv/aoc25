// Advent of Code day5 ingredients in range
#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <algorithm>
#include <chrono>
#include <vector>

int part1(std::string filename)
{
    std::fstream in_file(filename);

    std::string prev_line;
    std::getline(in_file, prev_line); // Starting line

    std::string line;
    int split_count = 0;
    while (std::getline(in_file, line))
    {
        //std::cout << prev_line << std::endl;
        for (int i = 0; i < line.length(); i++)
        {
            auto beam = prev_line[i] == '|' || prev_line[i] == 'S';
            auto splitter = line[i] == '^';
            if (beam)
            {
                if (splitter)
                {
                    line[i - 1] = '|';
                    line[i + 1] = '|';
                    split_count++;
                }
                else
                {
                    line[i] = '|';
                }
            }
        }
        prev_line = line;
    }
    return split_count;
}

long long part2(std::string filename)
{
    std::fstream in_file(filename);
    std::string line;
    std::getline(in_file, line); // Starting line

    std::vector<long long> current_line{};
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == 'S')
        {
            current_line.push_back(1);
        }
        else
        {
            current_line.push_back(0);
        }
    }

    std::vector<long long> new_line = current_line;
    while (std::getline(in_file, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            auto beam = current_line[i] > 0;
            auto splitter = line[i] == '^';
            if (beam)
            {
                if (splitter)
                {
                    new_line[i] = 0;
                    new_line[i - 1] += current_line[i];
                    new_line[i + 1] += current_line[i];
                }
                else
                {
                    line[i] = '|';
                }
            }
        }
        current_line = new_line;

        /*for (int i = 0; i < current_line.size(); i++)
        {
            if (new_line[i] > 0)
            {
                std::cout << "  " << new_line[i] << " ";
            }
            else
            {
                std::cout << line[i];
            }
        }
        std::cout << std::endl
                  << std::endl;*/
    }
    long long total = 0;
    for (int i = 0; i < current_line.size(); i++)
    {
        total += current_line[i];
    }
    return total;
}

int run_with_file(std::string filename)
{

    auto start = std::chrono::high_resolution_clock::now();
    int part1_result = part1(filename);
    auto part2_result = part2(filename);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Part 1: " << part1_result << std::endl;
    std::cout << "Part 2: " << part2_result << std::endl;
    std::cout << "Time (µs): " << duration.count() << std::endl;

    return 0;
}

int main()
{
    run_with_file("day7/data_test.txt");
    run_with_file("day7/data_real.txt");
    return 0;
}
