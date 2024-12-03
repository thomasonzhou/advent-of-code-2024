#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>

int main() {

    std::vector<int> v1;
    std::unordered_map<int, int> m2;

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
            m2[num2] += 1;
        }
        else{
            std::cerr << "Failed to read numbers from line: " << line << std::endl;
        }
    }
    infile.close();


    int similarity = 0;
    for (int i = 0; i < v1.size(); i++){
        similarity += v1[i] * m2[v1[i]];
    }

    std::cout << "Total: " << similarity << std::endl;


}
