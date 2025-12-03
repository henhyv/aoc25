// Advent of Code day1
#include <iostream>
#include <fstream>
#include <cmath>

int get_num_digits(long long value){
    // Compare against 1, 10, 100 etc.
    long long check = 1;
    for(int i = 0; i < 20; i++){
        if(value < check){
            return i;
        }
        check *= 10;
    }
    return 20;
}

long long part1_count_in_range(long long first, long long second){
    long long total = 0;
    int num_digits = get_num_digits(first);
    long long start = 0;
    long long divisor = pow(10, num_digits/2);

    if(num_digits % 2 != 0){
        // Not valid -> start at next
        start = pow(10, num_digits) + pow(10, num_digits/2); // 3 -> 1010 -> digits 4
        num_digits++;
        divisor *= 10;
    }
    else{
        start = (first / divisor) * (divisor + 1);
    }
    int digits_second = get_num_digits(second);
    if(digits_second % 2 != 0){
        second = pow(10, digits_second-1) - 1;
        std::cout << "Clamped second to " << second << std::endl;
    }
    std::cout << "Start at " << start << std::endl;

    while(start <= second){
        if(start >= first){
            total += start;
            std::cout << "Found " << start << std::endl;
        }
        start += divisor + 1;
    }
    return total;
}

void part1(){
    std::fstream in_file("data/aoc/day2.txt");
    //std::fstream in_file("data/aoc/day2_test.txt");
    
    int dial = 50;
    int zeroes_part1 = 0;
    int zeroes_part2 = 0;
    std::string numpair;

    long long total = 0;
    int found_count = 0;
    while(std::getline(in_file, numpair, ','))
    {
        std::cout << "Range: " << numpair << std::endl;
        std::string delimiter = ">=";
        int pos = numpair.find('-');
        long long first = std::stoll(numpair.substr(0, pos));
        long long second = std::stoll(numpair.substr(pos+1, numpair.length()));

        total += part1_count_in_range(first, second);
    }
    std::cout << "Invalid id count: " << found_count << std::endl;
    std::cout << "Part 1 Total: " << total << std::endl;
}

void part2(){
    // TODO
}

int main() {
    part1();

    return 0;
}
