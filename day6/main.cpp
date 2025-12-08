// Advent of Code day6 Maths
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <numeric>
#include <deque>

std::vector<std::vector<long>> parse_data_part1(std::vector<std::string> lines)
{
    std::vector<std::vector<long>> data;
    for (auto &line : lines)
    {
        // Number line
        int column = 0;

        std::istringstream iss(line);

        int pos = data.size();
        data.push_back(std::vector<long>{});
        long value;
        // operator>> skips any amount of whitespace
        while (iss >> value)
        {
            if (data.size() <= column)
            {
                data.push_back(std::vector<long>{});
            }
            data[column].push_back(value);
            // std::cout << value << ", ";
            column++;
        }
    }
    return data;
}

std::vector<std::vector<long>> parse_data_part2(std::vector<std::string> lines)
{
    std::vector<std::vector<long>> data;
    std::vector<long> value_group{};

    for (int column = lines[0].length() - 1; column >= 0; column--)
    {
        int digits = 0;
        int number = 0;
        for (int row = 0; row < lines.size(); row++)
        {
            char c = lines[row][column];
            if (isalnum(c))
            {
                number *= 10;
                number += c - '0';
                digits++;
            }
        }
        // The column was a number if there were any digits
        if (digits > 0)
        {
            value_group.push_back(number);
        }
        else
        {
            data.push_back(value_group);
            value_group.clear();
        }
    }

    data.push_back(value_group);
    // Change order to be from left to right
    std::reverse(data.begin(), data.end());
    return data;
}

long long do_the_maths(const std::vector<std::vector<long>> &data, const std::vector<char> &operations)
{
    long long total = 0;
    for (int i = 0; i < operations.size(); i++)
    {
        char op = operations[i];
        auto &nums = data[i];

        long long column_result = 0;
        if (op == '*')
        {
            column_result = 1;
            for (int x = 0; x < nums.size(); x++)
            {
                column_result *= nums[x];
            }
        }
        else
        {
            column_result = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                column_result += nums[i];
            }
        }
        total += column_result;
    }
    return total;
}

int run_with_file(std::string datafile)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::fstream in_file(datafile);

    std::vector<std::string> lines{};
    std::string line;
    while (std::getline(in_file, line))
    {
        lines.push_back(line);
    }

    std::istringstream op_ss(lines.back());
    std::vector<char> operations{};
    char op;
    while (op_ss >> op)
    {
        operations.push_back(op);
    }
    // Remove last line which was for operations
    lines.pop_back();

    // Part 1
    auto data_part1 = parse_data_part1(lines);
    auto total_p1 = do_the_maths(data_part1, operations);

    // Part 2
    auto data_part2 = parse_data_part2(lines);
    auto total_p2 = do_the_maths(data_part2, operations);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "File: " << datafile << std::endl;
    std::cout << "Part 1: " << total_p1 << std::endl;
    std::cout << "Part 2: " << total_p2 << std::endl;
    std::cout << "Time (µs): " << duration.count() << std::endl;
    return 0;
}

int main()
{
    run_with_file("day6/data_test.txt");
    run_with_file("day6/data_real.txt");
    return 0;
}
