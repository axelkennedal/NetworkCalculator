/*
//
//  FindFirstIP.cpp
//  Egetskojs
//
//  Created by Axel Kennedal on 2014-02-13.
//  Copyright (c) 2014 Axel Kennedal. All rights reserved.
//

//VERY IMPORTANT!!! RUN ONLY ON LAST OCTET OF IPV4 ADDRESS
 
#include <iostream>
#include <string>
using namespace std;

string FindFirstIP(string octetNetworkIDbin);

int main(){
    
    
    string networkID = "00000000";
    string firstIP = FindFirstIP(networkID);
    cout << firstIP << endl;
    
    
    return 0;
}

string FindFirstIP(string octetNetworkIDbin){
    string solution;
    
    octetNetworkIDbin.at(7) = '1';
    solution = octetNetworkIDbin;
    
    return solution;
}
*/