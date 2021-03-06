//
//  Stack.h
//  DevilScript
//
//  Created by Didrik Munther on 23/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __DevilScript__Stack__
#define __DevilScript__Stack__

#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "Lexer.h"


class Element {
    
public:
    Element(std::string value) : value(value) {}
    
    std::string toString()  {
        float floatValue = toFloat();
        int intValue = static_cast<int>(floatValue);
        return floatValue == intValue ? std::to_string(toInt()) : std::to_string(toFloat());
    }
    int toInt()             { return std::stoi(value); }
    float toFloat()         { return std::stof(value); }
    
private:
    std::string value;
    
};

class Stack {
    
public:
    Stack();
    ~Stack();
    
    std::string toString(int index) { return getElement(index)->toString(); }
    int toInt(int index)            { return getElement(index)->toInt();    }
    float toFloat(int index)        { return getElement(index)->toFloat();  }
    
    std::vector<Element*> elements;
    std::map<std::string, std::string> variables;
    
    bool hasVariable(std::string key) {
        bool toReturn = false;
        for(auto& i: variables) {
            toReturn |= !strcmp(i.first.c_str(), key.c_str());
        }
        
        return toReturn;
        
        //return variables.find(key.c_str()) != variables.end();
    }
    
    void popTopElement() {
        delete getElement(0);
        elements.pop_back();
    }
    
    void pushElement(Element* element) {
        elements.push_back(element);
    }
    
    void clearStack() {
        auto it = elements.begin();
        while(it != elements.end()) {
            delete *it;
            it++;
        }
        elements.clear();
    }
    
private:
    Element* getElement(int index);
    
};

#endif /* defined(__DevilScript__Stack__) */
