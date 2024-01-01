#include <iostream>
#include <cctype>
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
        if ( c == delim ) {
            r . push_back ( tmp );
            tmp = "";
        } else tmp += c;
    }
    r . push_back ( tmp );
    return r;
}

void subgame ( const std::string & thrw, size_t & minRed, size_t & minGreen, size_t & minBlue ) {
    auto dices = ssplit ( thrw, ',' );
    for ( const auto & dice : dices ) {
        auto split = ssplit ( dice.substr(1, dice.size()), ' ' );
        size_t n = std::stoi(split[0]);
        if ( split[1] == "red" ) 
            minRed = std::max ( minRed, n );
        if ( split[1] == "green" )
            minGreen = std::max ( minGreen, n );
        if ( split[1] == "blue" )
            minBlue = std::max ( minBlue, n );
    }
}

size_t game ( const std::string & line ) {
    size_t r = 0;
    auto throws = ssplit ( ssplit ( line, ':' )[1], ';' );

    size_t minRed = 0;
    size_t minGreen = 0;
    size_t minBlue = 0;

    for ( const auto & thrw : throws )
        subgame ( thrw, minRed, minGreen, minBlue );
    
    return minRed * minGreen * minBlue;
}

int main ( void ) {
    size_t r = 0;
    std::string line;
    while ( std::getline ( std::cin, line ) )    
        r += game ( line );
    std::cout << "=> " << r << std::endl;
    return 0;
}