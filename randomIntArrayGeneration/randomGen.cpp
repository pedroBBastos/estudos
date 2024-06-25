#include <iostream>
#include <vector>
#include <random>   // For random number generation
#include <ctime>    // For seeding the random number generator

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    // Check if the input size is valid
    if (n <= 0) {
        std::cerr << "Size of array should be a positive integer." << std::endl;
        return 1;
    }

    // Initialize random number generator
    std::random_device rd;  // Seed generator
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dis(1, 100); // Define the range [1, 100]

    // Create and fill the array with random numbers
    std::vector<int> randomArray(n);
    for (int i = 0; i < n; ++i) {
        randomArray[i] = dis(gen);
    }

    // Output the generated random array
    std::cout << "Random array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << randomArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
