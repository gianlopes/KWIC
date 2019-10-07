//
//  Text_Input.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Text_Input.hpp"

//MARK: setup
bool Text_Input::setup(){
    std::cout << "Setting up Text Input enviroment." << std::endl;
    
    in_file.open(filepath);
    
    return in_file.is_open();
}

//MARK: reachedEND
bool Text_Input::reachedEND(){ //Check if eof was reached
    return in_file.eof();
}

//MARK: Extractors
void Text_Input::extractMain(){  //Extracts line : delimiter '\n'
    std::string line {};
    
    getline(in_file, line);
    data.originalLine_String = line;
    
    std::string tempWord {};
    for (auto c : line) {
        if (c == ' ') {
            data.originalLine_Vector.push_back(tempWord);
            tempWord = "";
        }
        else{
            tempWord += c;
        }
    }
    data.originalLine_Vector.push_back(tempWord);
}

void Text_Input::extractStops(){
    std::string line {};

    while (!reachedEND()) {
        getline(in_file, line);
        data.stopWords.push_back(line);
    }
}

//MARK: Finish
void Text_Input::finish(){
    in_file.close();
    
}

//MARK: Constructor
Text_Input::Text_Input(LineStorage & data, type entryType)
:Input(data, entryType)
{
    std::string filetype {}, line {};
    std::string folder = "Resources/";
    
    switch (entryType) {
        case typeStops:
            filetype = "stops";
            break;
        case typeInput:
            filetype = "input";
            break;
        default:
            break;
    }
    std::cout << "Enter " << filetype << " file name inside Resources folder: (no .json needed)" << std::endl;
    getline(std::cin, line);
    
    folder += line;
    folder += ".txt";
    
    filepath = folder;
    
    std::cout << "Created Text_Input object for reading." << std::endl;
    
}

