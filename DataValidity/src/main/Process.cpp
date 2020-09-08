/*Copyright (c) 2020 AUAC-Technologies

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
//Author - Nyameaama Gambrah

#include"Process.h"

void P_MAIN::transmit(uint8_t data, void (*func)(char*)){
    CHECKSUM *instance = new CHECKSUM();
    MISC *util = new MISC();
    //CHECKSUM
    char* convertedData;
    util->itoa(data,convertedData,10);
    auto checksum = instance -> verhoeffChecksum(convertedData);
    delete instance;
    //MERGE TO PACKET
    auto merged = util -> PACKET_MERGE_2VALUES(data,checksum);
    delete util;
    //OUTPUT METHOD
    func(merged);
    return;
}

char* P_MAIN::get(char* (*func)()){
    //PARSE PACKET
    MISC *util = new MISC();
    auto *elements = util -> PARSE_PACKET(func);
    delete util;
    //CHECKSUM FOREIGN DATA
    auto data = elements[0];
    char checkDigit[1];
    checkDigit[0] = elements[1];
    //VALIDATE CHECKSUMS
    CHECKSUM *instance = new CHECKSUM();
    auto validate = instance -> validate_verhoeff(checkDigit);
    delete instance;
    //RETURN 
    //return (validate == 0) ? elements[0] : 0;
}