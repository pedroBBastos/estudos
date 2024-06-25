#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort and std::binary_search

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    
    // First, we need to sort the vector
    std::sort(vec.begin(), vec.end());
    
    // Now we can use std::binary_search
    int target = 5;
    bool found = std::binary_search(vec.begin(), vec.end(), target);
    
    if (found) {
        std::cout << "Element " << target << " is found in the vector." << std::endl;
    } else {
        std::cout << "Element " << target << " is not found in the vector." << std::endl;
    }
    
    return 0;
}
