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

#ifndef QUEUE_
#define QUEUE_

#include"../AUAC_TYPEDEFS/AUAC_TYPES.h"
#include"../DataValidity/src/transfer.h"
#include<stdlib.h>

#define RAND_SEED 0

class Queue {
    private:
        NO_RETURN logTransmsission();

        //Linear Congruential Generator function to generate a random number within set boundaries
        AUAC_BASE_8 LCG(AUAC_BASE_8 x,AUAC_BASE_8 y,AUAC_BASE_8 seed);

        //Method to determine next comm task (Send / Receive) 
        AUAC_BASE_8 determineNextTask();

        //Method to add transmission request to queue
        NO_RETURN addToSendQueue(AUAC_BASE_STRING tag, AUAC_BASE_STRING data);

        //Method to remove transmission request to queue once fulfilled
        NO_RETURN removeFromSendQueue(AUAC_BASE_STRING tag, AUAC_BASE_STRING data);

    public:
        //Driver Function to dispatch formatted data to output
        AUAC_BASE_STRING dispatch(AUAC_BASE_STRING tag, AUAC_BASE_STRING data);

        //Driver Function to receive formatted data from output
        AUAC_BASE_STRING receive(AUAC_BASE_STRING tag);

};


#endif //QUEUE_