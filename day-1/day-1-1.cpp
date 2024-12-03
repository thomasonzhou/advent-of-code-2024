#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

int main() {

    std::vector<int> v1;
    std::vector<int> v2;

    std::ifstream infile("input.txt");
    if (!infile) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }
    std::string line;
    int num1, num2;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if(iss >> num1 >> num2){
            v1.push_back(num1);
            v2.push_back(num2);
        }
        else{
            std::cerr << "Failed to read numbers from line: " << line << std::endl;
        }
    }
    infile.close();

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int total = 0;
    for (int i = 0; i < v1.size(); i++){
        total += abs(v1[i] - v2[i]);
    }

    std::cout << "Total: " << total << std::endl;


}
