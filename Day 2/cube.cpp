#include <iostream>
#include <vector>
#include <string>
#include <regex>

const int RED   = 12;
const int GREEN = 13;
const int BLUE  = 14;

std::vector<std::string> ssplit ( const std::string & str, const char delim ) {
    std::vector<std::string> r;
    std::string tmp = "";
    for ( const auto & c : str ) {
        tmp += c;
        if ( c == delim ) {
            r . push_back ( tmp );
            tmp = "";
        }
    }
    r . push_back ( tmp );
    return r;
}

size_t game ( const std::string & line ) {
    auto split = ssplit ( line, ':' );  
    auto game = ssplit ( split[0], ' ' );
    size_t id = std::stoi(game[1].substr(0, game[1] . size ( ) - 1));
    return 0;
}

int main ( void ) {
    size_t r = 0;
    std::string line;
    while ( std::getline ( std::cin, line ) )    
        r += game ( line );
    std::cout << "=> " << r << std::endl;
    return 0;
}