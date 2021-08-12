#include<iostream>
#include <vector>
#include <string>
#include <sstream>

// Came up with naive solution to very quickly realise that I run out of sapce for storing larger numbers
//std::vector<int> plusOne(std::vector<int>& digits)
//{
//    // Turn digits in vector into a string
//    std::string number = "";
//
//    for (int i = 0; i < digits.size(); ++i)
//    {
//        number += std::to_string(digits[i]);
//    }
//
//    // Check
//    std::cout << "String vector number is: " << number << '\n';
//
//    // Turn string into an int
//    std::stringstream ss(number);
//    long long num = 0;
//
//    // Assign whatever is in the ss to the var num
//    ss >> num;
//
//    // Add 1 to that value
//    ++num;
//
//    // Check
//    std::cout << "Int vector new number is: " << num << '\n';
//
//    // Turn new int back into another string so we know how
//    // many digits we are dealing with for our loop
//    std::string numPlusOne = std::to_string(num);
//    std::vector<int> plusOne;
//
//    for (int i = 0; i < numPlusOne.size(); ++i)
//    {
//        // Extract last digit
//        int singleDigit = num % 10;
//        // Push back onto vector, IN WRONG ORDER!
//        plusOne.push_back(singleDigit);
//        num /= 10;
//    }
//
//    // Reverse the vector to get the correct number
//    std::reverse(plusOne.begin(), plusOne.end());
//
//    // Return that vector
//    return plusOne;
//}


std::vector<int> plusOne(std::vector<int> num)
{
    // Add 1 to last digit
    num[num.size() - 1] += 1;

    // Calculate carry, it will be either 1 or 0
    int carry = num[num.size() - 1] / 10;

    // Will remain the same or be changed to a 0
    num[num.size() - 1] = num[num.size() - 1] % 10;

    // Loop from second last digit to first
    for (int i = num.size() - 2; i >= 0; --i)
    {
        if (carry == 1)
        {
            num[i] += 1;

            // Calculate new carry, again it will be either 1 or 0
            carry = num[i] / 10;

            // Again, this will either remain the same, or change to a 0
            num[i] = num[i] % 10;
        }
    }

    // If we get this far and still have a carry of 1 it means
    // all the numbers must have been 9's and so we must add a
    // 1 to  the front of the vec, i.e. 999 becomes 1000
    if (carry == 1)
    {
        num.insert(num.begin(), 1);
    }
    
    return num;
}

int main()
{
    // TEST CASES
    std::vector<int> test1 = { 9, 9, 9, 9 };

    std::vector<int> testPlusOne = plusOne(test1);

    // Check
    for (int i = 0; i < testPlusOne.size(); ++i)
    {
        std::cout << testPlusOne[i];
    }

	return 0;
}