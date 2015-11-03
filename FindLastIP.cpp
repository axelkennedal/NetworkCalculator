/*
//
//  FindLastIP.cpp
//  Egetskojs
//
//  Created by Axel Kennedal on 2014-02-13.
//  Copyright (c) 2014 Axel Kennedal. All rights reserved.
//

//VERY IMPORTANT!!! RUN ONLY ON LAST OCTET OF IPV4 ADDRESS
 
#include <iostream>
#include <string>
using namespace std;

string FindLastIP(string octetBroadcastBin);

int main(){
    
    string broadcast = "10110111";
    
    string lastIP = FindLastIP(broadcast);
    cout << lastIP << endl;
    
    return 0;
}

string FindLastIP(string octetBroadcastBin){
    string solution;
 
    octetBroadcastBin.at(7) = '0';
    solution = octetBroadcastBin;
 
    return solution;
}
*/