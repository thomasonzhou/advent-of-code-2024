#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

bool isSafe(const int num1, const int num2, const int ascending_factor){
    const int diff = (num2 - num1) * ascending_factor;
    return 1 <= diff && diff <= 3;
}

int main(){
    std::ifstream infile("input.txt");

    if (!infile) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }


    int safe_count = 0;
    std::string line;
    while (std::getline(infile, line)){
        std::istringstream iss(line);
        int num1;
        iss >> num1;
        int num2;
        if(!(iss>>num2)){
            safe_count++;
            continue;
        }
        if (num1 == num2){
            continue;
        }
        bool ascending = num1 < num2;
        int ascending_factor = ascending ? 1 : -1;
        if (!isSafe(num1, num2, ascending_factor)){
            continue;
        }
        num1 = num2;

        bool safe = true;
        while(iss>> num2){
            if (!isSafe(num1, num2, ascending_factor)){
                safe = false;
                break;
            }
            num1 = num2;
        }

        if (safe){
            safe_count++;
        }
    }
    infile.close();

    std::cout << "Safe count: " << safe_count << std::endl;

}
