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

bool subgame ( const std::string & thrw ) {
    auto dices = ssplit ( thrw, ',' );
    for ( const auto & dice : dices ) {
        auto split = ssplit ( dice.substr(1, dice.size()), ' ' );
        if ( split[1] == "red" && std::stoi(split[0]) > RED )
            return false;
        if ( split[1] == "green" && std::stoi(split[0]) > GREEN )
            return false;
        if ( split[1] == "blue" && std::stoi(split[0]) > BLUE )
            return false;   
    }
    return true;
}

size_t game ( const std::string & line ) {
    size_t r = 0;
    auto split = ssplit ( line, ':' );  
    auto throws = ssplit ( split[1], ';' );

    for ( const auto & thrw : throws )
        if ( ! subgame ( thrw ) )
            return 0;
    
    return std::stoi(ssplit ( split[0], ' ' )[1]);
}

int main ( void ) {
    size_t r = 0;
    std::string line;
    while ( std::getline ( std::cin, line ) )    
        r += game ( line );
    std::cout << "=> " << r << std::endl;
    return 0;
}