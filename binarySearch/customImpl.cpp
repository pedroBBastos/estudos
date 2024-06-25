#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort

bool binarySearch(const std::vector<int>& vec, int target) {
    int left = 0;
    int right = vec.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoid overflow with (left + right) / 2
        
        if (vec[mid] == target) {
            return true;  // Target found
        } else if (vec[mid] < target) {
            left = mid + 1;  // Search the right half
        } else {
            right = mid - 1;  // Search the left half
        }
    }
    
    return false;  // Target not found
}

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    
    // First, we need to sort the vector
    std::sort(vec.begin(), vec.end());
    
    int target = 5;
    bool found = binarySearch(vec, target);
    
    if (found) {
        std::cout << "Element " << target << " is found in the vector." << std::endl;
    } else {
        std::cout << "Element " << target << " is not found in the vector." << std::endl;
    }
    
    return 0;
}
