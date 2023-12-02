#include <unordered_map>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <cctype>
#include <tuple>

std::unordered_map<std::string, int> mapping = {
    { "one", 1 },
    { "two", 2 },
    { "three", 3 },
    { "four", 4 },
    { "five", 5 },
    { "six", 6 },
    { "seven", 7 },
    { "eight", 8 },
    { "nine", 9 }
};

std::pair<int, int> findOcc ( const std::string & haystack, const std::string & needle ) {
    size_t pos = 0;
    int first = -1, last = -1;
    while ( 1 ) {
        pos = haystack.find(needle, pos);
        if ( pos == std::string::npos ) 
            break;
        if ( first == -1 ) first = pos;
        last = pos;
        pos += 1;
    }
    return { first, last };
}

int main ( void ) {
    std::string s;
    int r = 0;
    while ( std::cin >> s ) {
        int min, minVal, max = 0, maxVal = 0;
        
        for ( size_t i = 0; i < s . size ( ); i++ ) {
            if ( isdigit(s[i]) ) {
                min = i;
                minVal = s[i] - '0';
                break;
            }
        }

        for ( size_t i = s . size ( ) - 1; i >= 0; i-- ) {
            if ( isdigit(s[i]) ) {
                max = i;
                maxVal = s[i] - '0';
                break;
            }
        }

        for ( const auto & m : mapping ) {
            auto idx = findOcc ( s, m . first );
            if ( idx . first != -1 && min > idx . first ) {
                min = idx . first;
                minVal = m . second;
            }

            if ( idx . second != -1 && max < idx . second ) {
                max = idx . second;
                maxVal = m . second;
            }
        }

        r += minVal * 10 + maxVal;
    }
    std::cout << "=> " << r << std::endl;
    return 0;
}