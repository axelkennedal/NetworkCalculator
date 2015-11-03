/*
//
//  NetworkCalculator.cpp
//  Egetskojs
//
//  Created by Axel Kennedal on 2014-02-13.
//  Copyright (c) 2014 Axel Kennedal. All rights reserved.
//


/*
 HOW IT WORKS
 ////////////
 
 An IPv4 address is processed to produce useful information regarding it.
 One octet of it is processed at a time, each octet as an object of this class.
 
 INPUT:
 * decimal IP
 * decimal subnetmask
 
 OUTPUT:
 The following in both binary and decimal:
 * network ID
 * broadcast address
 * first usable address (only when the last octet of an IPv4 address is processed)
 * last usable address (only when the last octet of an IPv4 address is processed)
 * max amount of hosts on this octet
 
 PROCEDURE:
 1) Let user input decimal versions of IP number and subnetmask number - only one octet of an address
 2) Turn the decimal IP and decimal subnetmask into binary
 3) Compare the binary IP and binary subnetmask to get binary NETWORK ID
 4) Process the binary subnetmask to get the number of ZEROS IN SUBNETMASK (used later to calculate max hosts for entire IPv4 address)
 5) Use the now created binary network ID and the number of zeros in subnetmask to get the binary BROADCAST ADDRESS
 6a) Find out the binary FIRST USABLE ADDRESS in the network
 6b) Find out the binary LAST USABLE ADDRESS in the network
 7) Convert the binary versions of these into decimal:
 a)
 * network ID,
 * broadcast address
 !-- ONLY DO STEP 6b) FOR THE LAST (4th) OCTET OF AN IPV4 ADDRESS --!
 b)
 * first usable address
 * first usable address
 
 DONE!!!
 


#include "NetworkCalculator.h"

//All functions interacting with variables from the class 'networkOctet' need 'networkOctet::' before them

//1) CONSTRUCTOR
networkOctet::networkOctet(int octetIP, int octetSubnetmask, bool lastOctet){ //'lastOctet' should be true if the octet the object represents is the last one (4th) in an IPv4 address
    //Redirects input into object-member varibles
    IPdec = octetIP;
    subnetmaskDec = octetSubnetmask;
    
    //Corrects the foolish user
    if (IPdec > 255) {
        IPdec = 255;
    }
    if (subnetmaskDec > 255) {
        subnetmaskDec = 255;
    }
    
    // 2) Conversion to binary
    IPbin = DecimalToBinary(IPdec);
    subnetmaskBin = DecimalToBinary(subnetmaskDec);
    
    // 3) Find network ID
    networkIDbin = FindNetID(IPbin, subnetmaskBin);
    
    // 4) Find number of zeros in subnet mask
    zeroesInSubnetmask = FindZeroesInSubnetmask(subnetmaskBin);
    
    // 5) Find broadcast address
    broadcastBin = FindBroadcast(networkIDbin, subnetmaskBin);
    
    // 6) Check for first and last usable address of an IPv4 address
    firstIPbin = FindFirstIP(networkIDbin, lastOctet);
    lastIPbin = FindLastIP(broadcastBin, lastOctet);

    // 7) Convert binary variables into decimal
    networkIDdec = BinaryToDecimal(networkIDbin);
    broadcastDec = BinaryToDecimal(broadcastBin);
    firstIPdec = BinaryToDecimal(firstIPbin);
    lastIPdec = BinaryToDecimal(lastIPbin);
    
    
    //DONE, ALL CALCULATIONS COMPLETE!!!
}


string networkOctet::DecimalToBinary(int decimal){
    string solution;

    //Keeps counting until the modulu of 'decimal' == 0
    while(decimal > 0){
        if (decimal % 2 == 0) {
            solution.insert(0, "0");
            decimal /= 2;
        }
        
        else {
            solution.insert(0, "1");
            decimal /= 2;
        }
        
        if (decimal == 1)
        {
            decimal = 0;
            solution.insert(0, "1");
        }
    }
    
    //Calculation complete
    //Adds zeroes at the beginning to make it a complete, beautiful byte
    while (solution.size() < 8) {
        solution.insert(0, "0");
    }
    
    //Done!
    return solution;
}



string networkOctet::FindNetID(string octetIPbin, string octetSubnetmaskBin){
    int subnetmaskBits = 0;
    string solution;
    //Checking how many bits are set to '1' in the subnetmask octet
    for (char index = 0; index < 8; index++) {
        if (octetSubnetmaskBin.at(index) == '1') {
            subnetmaskBits++;
        }
        else break;
    }
    
    if (subnetmaskBits == 0) solution = "00000000"; //All bits in the subnetmask octet are set to zero, the net ID-octet becomes all zero
    
    //Change the neccesary bits of the IP to turn it into the net ID
    for (int index = subnetmaskBits; index < 8; index++) {
        octetIPbin.at(index) = '0';
    }
    //Done!
    solution = octetIPbin;
    return solution;
}


int networkOctet::FindZeroesInSubnetmask(string octetSubnetmaskBin){
    int subnetmaskZeroes = 0;
    
    for (int index = 7; index >= 0; index--) {
        if (octetSubnetmaskBin.at(index) == '0') {
            subnetmaskZeroes++;
        }
        else break;
    }
    
    return subnetmaskZeroes;
}


string networkOctet::FindBroadcast(string octetNetworkIDbin, string octetSubnetmaskBin){
    string solution;
    
    //Change the neccesary bits of the network ID to turn it into the broadcast address
    for (int index = 7; index >= (8 - zeroesInSubnetmask); index--) {
        octetNetworkIDbin.at(index) = '1';
    }
    
    solution = octetNetworkIDbin;
    return solution;
}


string networkOctet::FindFirstIP(string octetNetworkIDbin, bool lastOctet){
    string solution;
    
    if (lastOctet == true) {
        octetNetworkIDbin.at(7) = '1';
    }
    
    solution = octetNetworkIDbin;
    return solution;
}


string networkOctet::FindLastIP(string octetBroadcastBin, bool lastOctet){
    string solution;
    
    if (lastOctet == true) {
        octetBroadcastBin.at(7) = '0';
    }
    
    solution = octetBroadcastBin;
    return solution;
}


int networkOctet::BinaryToDecimal(string & binaryString){
    int solution = 0;
    
    int index = binaryString.length() - 1; //The index of the last (rightmost) bit in the string
    
    int currentBit = 0; //The exponent to be used when calculating the value of a bit
    
    for (;index >= 0; index--) {
        if (binaryString.at(index) == '1') {
            solution += pow(2, currentBit);
        }
        //Else: nothing happens
        currentBit++;
    }
    
    //Done!
    return solution;
}


//DAS GETTERS (a.k.a. goats)
string networkOctet::GetIPbin(){
    return IPbin;
}

string networkOctet::GetSubnetmaskBin(){
    return subnetmaskBin;
}

string networkOctet::GetNetworkIDbin(){
    return networkIDbin;
}

string networkOctet::GetBroadcastBin(){
    return broadcastBin;
}

string networkOctet::GetFirstIPbin(){
    return firstIPbin;
}

string networkOctet::GetLastIPbin(){
    return lastIPbin;
}

int networkOctet::GetIPdec(){
    return IPdec;
}

int networkOctet::GetSubnetmaskDec(){
    return subnetmaskDec;
}

int networkOctet::GetNetworkIDdec(){
    return networkIDdec;
}

int networkOctet::GetBroadcastDec(){
    return broadcastDec;
}

int networkOctet::GetFirstIPdec(){
    return firstIPdec;
}

int networkOctet::GetLastIPdec(){
    return lastIPdec;
}

int networkOctet::GetZeroesInSubnetMask(){
    return zeroesInSubnetmask;
}
*/