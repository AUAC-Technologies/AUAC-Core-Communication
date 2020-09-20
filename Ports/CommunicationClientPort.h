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

#ifndef COMMUNICATION_CLIENT_PORTAL_
#define COMMUNICATION_CLIENT_PORTAL_

//#include<../DataValidity/src/transfer.h>
#include"../AUAC_TYPEDEFS/AUAC_TYPES.h"
#include"../Comms/Queue.h"

class COMMUNICATION_CLIENT_PORTAL {
    public:
        //Send Request to handler 
        AUAC_BASE_STRING forward(AUAC_BASE_STRING tag, AUAC_BASE_STRING data){Queue transmission;transmission.dispatch(tag,data);}

        //Request transmission from handler
         

};

#endif //COMMUNICATION_CLIENT_PORTAL