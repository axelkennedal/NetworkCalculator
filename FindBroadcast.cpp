/*
//
//  FindBroadcast.cpp
//  Egetskojs
//
//  Created by Axel Kennedal on 2014-02-13.
//  Copyright (c) 2014 Axel Kennedal. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string FindBroadcast(string octetNetworkIDbin, string octetSubnetBin);

int main(){
    
    
    string networkID = "01000000";
    string subnet    = "11000000";
    
    string octetBroadcast = FindBroadcast(networkID, subnet);
    cout << octetBroadcast << endl;
    
    return 0;
}

string FindBroadcast(string octetNetworkIDbin, string octetSubnetBin){
    string solution;
    int subnetZeroes = 0;
    cout << "running" << endl;
    for (int index = 0; index < 8; index++) {
        if (octetSubnetBin.at(index) == '0') {
            subnetZeroes++;
        }
        else break;
    }
    cout << subnetZeroes << endl;
    
    if (subnetZeroes == 8) solution = "11111111";
    if (subnetZeroes == 0) solution = octetNetworkIDbin;
    
    //Change the neccesary bits of the network ID to turn it into the broadcast address
    for (int index = 0; index >= (8 - subnetZeroes); index--) {
        octetNetworkIDbin.at(index) = '1';
    }
    
    solution = octetNetworkIDbin;
    return solution;
}
*/