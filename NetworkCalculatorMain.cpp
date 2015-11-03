/*
//
//  NetworkCalculatorMain.cpp
//  Egetskojs
//
//  Created by Axel Kennedal on 2014-02-13.
//  Copyright (c) 2014 Axel Kennedal. All rights reserved.
//

#include <iostream>
#include "NetworkCalculator.h"
using namespace std;


int main(){
    
    
    int ip;
    int subnet;
    
    networkOctet *networkOctetObject[4];
    
    for (int octet = 0; octet < 4; octet++) {
        cout << "OCTET NO." << octet << endl;
        cout << "IP:     "; cin >> ip;
        cout << "Subnet: "; cin >> subnet;
        if (octet == 3) {
            networkOctetObject[octet] = new networkOctet(ip, subnet, true);
        }
        else {
            networkOctetObject[octet] = new networkOctet(ip, subnet, false);
        }
    }
    
    cout << endl << "!-- RESULTS --!" << endl << endl;
    
    for (int octet = 0; octet < 4; octet++) {
        cout << "OCTET NO." << octet << endl;
        cout << "IP:          " << networkOctetObject[octet]->GetIPbin() << "  " << networkOctetObject[octet]->GetIPdec() << endl;
        cout << "Subnet mask: " << networkOctetObject[octet]->GetSubnetmaskBin() << "  " << networkOctetObject[octet]->GetSubnetmaskDec() << endl;
        cout << "Net ID:      " << networkOctetObject[octet]->GetNetworkIDbin() << "  " << networkOctetObject[octet]->GetNetworkIDdec() << endl;
        cout << "Broadcast:   " << networkOctetObject[octet]->GetBroadcastBin() << "  " << networkOctetObject[octet]->GetBroadcastDec() << endl;
        cout << "First IP:    " << networkOctetObject[octet]->GetFirstIPbin() << "  " << networkOctetObject[octet]->GetFirstIPdec() << endl;
        cout << "Last IP:     " << networkOctetObject[octet]->GetLastIPbin() << "  " << networkOctetObject[octet]->GetLastIPdec() << endl;
    }
    
    //Max hosts, special case calculation
    cout << "Max hosts:   "; int totalzeroes = 0;
    for (int octet = 0; octet < 4; octet++) {
        totalzeroes += networkOctetObject[octet]->GetZeroesInSubnetMask();
    }
    int maxhosts = pow(2, totalzeroes) -2;
    cout << maxhosts << endl;
    
    
    
    
    
    
    
    return 0;
}
*/