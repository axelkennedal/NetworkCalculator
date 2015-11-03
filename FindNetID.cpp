/*
//
//  FindNetID.cpp
//  Egetskojs
//
//  Created by Axel Kennedal on 2014-02-12.
//  Copyright (c) 2014 Axel Kennedal. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string FindNetID(string octetIPbin, string octetSubnetBin);

int main(){
    
    //EXAMPLE ADDRESSES
    string IPaddress = "192.168.0.12";
    string subNetMask = "255.255.255.0";
    
    string inoctetIPbinbin     = "11111111";
    string inoctetSubnetBin = "00000000";
 
    string netID = FindNetID(inoctetIPbin,inoctetSubnetBin);
    cout << netID << endl;
    
    return 0;
}

string FindNetID(string octetIPbin, string octetSubnetBin){
    int subnetBits;
    string solution;
    //Checking how many bits are set to '1' in the subnet octet
    for (char index = 0; index < 8; index++) {
        if (octetSubnetBin.at(index) == '1') {
            subnetBits++;
        }
        else break;
    }
    cout << subnetBits << endl;
    if (subnetBits == 0) solution = "00000000"; //All bits in the subnet octet are set to zero, the net ID-octet becomes all zero
    if (subnetBits == 8) solution = octetIPbin; //All bits in the subnet octet are set to one, the net ID-octet is the same as the IP address-octet
    
    //Change the neccesary bits of the IP to turn it into the net ID
    for (int index = subnetBits; index < 8; index++) {
        octetIPbin.at(index) = '0';
    }
    //Done!
    solution = octetIPbin;
    return solution;
}
*/