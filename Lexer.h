//
//  Lexer.h
//  DevilScript
//
//  Created by Didrik Munther on 23/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __DevilScript__Lexer__
#define __DevilScript__Lexer__

#include <stdio.h>
#include <string>
#include <map>
#include <vector>


enum Tokens {
    t_err = -2,
    t_end = 0,
    t_name,
    t_equals,
    t_numeral,
    t_plus
};

class Lexer {
    
public:
    Lexer();
    
    std::map<std::string, Tokens> keywords;
    
    std::vector<std::pair<Tokens, std::string>> lex(std::string input);
    
private:
    bool hasToken(std::string token);
    bool tokenIsName(std::string token);
    bool tokenIsNumeral(std::string token);
    
};

#endif /* defined(__DevilScript__Lexer__) */