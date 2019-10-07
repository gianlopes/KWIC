//
//  Input.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 06/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Input.hpp"

//MARK: Constructors
Input::Input(std::string filepath, LineStorage & data, type entryType) //3 Args Constructor
: entryType(entryType), filepath(filepath), data(data) {
}

Input::Input(LineStorage & data, type entryType)
: entryType(entryType), data(data){
    
}

//MARK: Setup
void Input::open(){
    std::cout << "Trying to open." << std::endl;
    
    if(setup()){
        std::cout << "Open() successfully executed." << std::endl;
    }
    else{
        std::cout << "Open() unsuccessfully executed." << std::endl;
        exit(1);
    }
}

//MARK: Extract
void Input::extract(){
    switch (entryType) {
        case typeStops:
            cout << "Extracting stop words" << endl;
            extractStops();
            cout << "Extracted " << data.storedStops() << " words" << endl;
            break;
        case typeInput:
            /// cout << "Extracting line from main program" << endl;
            extractMain();
        break;
            
        default:
            exit(2);
            break;
    }
}

//MARK: Close
void Input::close(){
    std::cout << "Closing.." << std::endl;
    
    finish();
}
