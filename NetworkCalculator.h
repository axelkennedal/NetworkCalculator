/*
//
//  NetworkCalculator.h
//  Egetskojs
//
//  Created by Axel Kennedal on 2014-02-13.
//  Copyright (c) 2014 Axel Kennedal. All rights reserved.
//

#ifndef __Egetskojs__NetworkCalculator__
#define __Egetskojs__NetworkCalculator__

#include <string>
#include <cmath>
using namespace std;


class networkOctet {
private:
    int IPdec;           //Decimal IP number inputted by user
    int subnetmaskDec;   //Decimal subnetmask inputted by user
    string IPbin;        //Binary version of IP number
    string subnetmaskBin;//Binary version of subnetmask
    string networkIDbin; //Binary version of network ID, created by ANDing IPbin with subnetmaskmaskBin
    string broadcastBin; //Binary version of broadcast address
    string firstIPbin;   //ONLY USED FOR LAST OCTET IN IPV4 ADDRESS!!! Binary version of first usable address
    string lastIPbin;    //ONLY USED FOR LAST OCTET IN IPV4 ADDRESS!!! Binary version of last usable address
    int networkIDdec;    //Decimal version of network ID, created from networkIDbin using BinaryToDecimal() function
    int broadcastDec;    //Decimal version of broadcast address, created from networkIDbin using BinaryToDecimal() function
    int firstIPdec;      //ONLY USED FOR LAST OCTET IN IPV4 ADDRESS!!! Decimal version of first usable address, created from networkIDbin using BinaryToDecimal() function
    int lastIPdec;       //ONLY USED FOR LAST OCTET IN IPV4 ADDRESS!!! Decimal version of last usable address, created from networkIDbin using BinaryToDecimal() function
    int zeroesInSubnetmask;//How many hosts can be used in this octet, !-- To get the max hosts for an entire IPv4 address this value has to be added up from all 4 octets using a function outside this class --!
    
    
public:
    //Step 1) Constructor
    networkOctet(int octetIP, int octetSubnetmask, bool lastOctet);
    
    //Step 2
    string DecimalToBinary(int decimal);
    
    //Step 3
    string FindNetID(string octetIP, string octetSubnet);
    
    //Step 4
    int FindZeroesInSubnetmask(string subnetmaskBin);
    
    //Step 5
    string FindBroadcast(string octetNetworkID, string octetSubnet);
    
    //Step 6
    string FindFirstIP(string octetNetworkID, bool lastOctet);
    string FindLastIP(string octetBroadcast, bool lastOctet);
    
    //Step 7
    int BinaryToDecimal(string & binaryString);
    
    
    //Getters
    string GetIPbin();
    string GetSubnetmaskBin();
    string GetNetworkIDbin();
    string GetBroadcastBin();
    string GetFirstIPbin();
    string GetLastIPbin();
    int GetIPdec();
    int GetSubnetmaskDec();
    int GetNetworkIDdec();
    int GetBroadcastDec();
    int GetFirstIPdec();
    int GetLastIPdec();
    int GetZeroesInSubnetMask();
};

#endif
*/