#include <iostream>
#include <string>
#include <cctype>

int main ( void ) {
    std::string s;
    int r = 0;
    while ( std::cin >> s ) {
        int n = 0;
        for ( const auto & c : s ) {
            if ( isdigit(c) ) {
                n += c - '0';
                break;
            }
        }

        for ( auto it = s . rbegin(); it != s . rend(); ++it ) {
            if ( isdigit ( *it ) ) {
                n *= 10;
                n += *it - '0';
                break;
            }
        }
        r += n;
    }
    std::cout << r << std::endl;
    return 0;
}