// Advent of Code day5 ingredients in range
#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <algorithm>
#include <chrono>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::fstream in_file("day5/day5.txt");

    std::string line;

    std::list<std::pair<long long, long long>> ranges;
    while (std::getline(in_file, line))
    {
        // Empty line marks end of the ranges section
        if (line.length() == 0)
        {
            break;
        }
        int pos = line.find('-');
        long long first = std::stoll(line.substr(0, pos));
        long long second = std::stoll(line.substr(pos + 1, line.length()));

        ranges.emplace_back(first, second);
    }
    int found_count = 0;

    // Part 1
    while (std::getline(in_file, line))
    {
        auto ingredient = std::stoll(line);
        auto range = ranges.begin();
        while (range != ranges.end())
        {
            if (ingredient >= range->first && ingredient <= range->second)
            {
                found_count++;
                break;
            }
            range++;
        }
    }
    
    auto p2_start = std::chrono::high_resolution_clock::now();

    // Part 2
    // Sort the ranges by the first element to make merging easier
    ranges.sort([](auto a, auto b){ return a.first < b.first; });

    long long total_ingredients = 0;
    auto range1 = ranges.begin();
    while (range1 != ranges.end())
    {
        auto range2 = std::next(range1);

        // Find if there's overlap
        if (range2 != ranges.end() && range1->second >= range2->first)
        {
            // Merge second range into first range, then remove second range
            // std::cout << "Merging\n " << range1->first << "-" << range1->second << "\n " << range2->first << "-" << range2->second << std::endl;
            range1->second = std::max(range1->second, range2->second);
            ranges.erase(range2);
        }
        else
        {
            // If there's no overlap, count ingredients in range and move to next range
            total_ingredients += range1->second - range1->first + 1;
            range1++;
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    auto p2_duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - p2_start);

    std::cout << "Part 1 good ingredients: " << found_count << std::endl;
    std::cout << "Part 2 total ingredients: " << total_ingredients << std::endl;
    std::cout << "P2 time (µs): " << duration.count() << std::endl;
    std::cout << "Time (µs): " << duration.count() << std::endl;

    return 0;
}
