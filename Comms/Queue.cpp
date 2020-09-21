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

#include"Queue.h"

//Data Structure for outbound transmissions
const AUAC_UBASE_8 OutboundtransmissionQueueLimit = 10;
AUAC_BASE_STRING sendQueue[1][OutboundtransmissionQueueLimit];

//Data Structure for inbound transmissions
const AUAC_UBASE_8 InboundtransmissionQueueLimit = 10;
AUAC_BASE_STRING receiveQueue[1][InboundtransmissionQueueLimit];

//Variable to store last transmission.| 1  = (Outbound) and 2 = (Inbound) |
AUAC_UBASE_8 lastTransmissionType = 1;

//Linear Congruential Generator function to generate a random number within set boundaries
AUAC_BASE_8 Queue::LCG(AUAC_BASE_8 x,AUAC_BASE_8 y,AUAC_BASE_8 seed){

}

//Method to determine next comm task (Send / Receive) 
AUAC_BASE_8 Queue::determineNextTask(){
    /*Function uses LCG generator to pick a random number between 1 (Outbound) and 2 (Inbound).
    If random number is equal to last transmission stored (variable denoted lastTransmissionType),
    opposite transmission type will be returned to dispatch function*/

    //Check to see if lastTransmissionType has a valid value
    
    //Create temp array and fill with 
    AUAC_UBASE_8 *_temp = (AUAC_UBASE_8*)malloc(2);
    _temp[0] = 1; _temp[1] = 2;
    //LCG random number
    AUAC_BASE_8 randomValue = LCG(1,2,RAND_SEED);
    //Variable holding nextTask
    AUAC_BASE_8 nextTask = randomValue;
    if(randomValue != lastTransmissionType){
        //Update nextTask as Current Value
    }else{
        //Update nextTask as Other Value in 2 value array
        for(size_t i = 0; i < 2;++i)
            if(_temp[i] == randomValue)
                nextTask = _temp[i + 1];
            else{
                nextTask = _temp[i];
            }
    }
    //Update last transmission type
    lastTransmissionType = nextTask;
    //Free mem
    free(_temp);
    return nextTask;
}

//Method to add transmission request to queue
NO_RETURN Queue::addToSendQueue(AUAC_BASE_STRING tag, AUAC_BASE_STRING data){
    /*Unlike stack (last in, first out) structure will be implemented as a 
    queue (first in, first out). This is implemented by shifting array groups(2D array)
    to the left(towards[0]) when a transmission is fulfilled and adding to the last
    index (torwards[ength]) when a transmission is added to the queue.*/

}

//Method to remove transmission request to queue once fulfilled
NO_RETURN Queue::removeFromSendQueue(AUAC_BASE_STRING tag, AUAC_BASE_STRING data){
    /*Unlike stack (last in, first out) structure will be implemented as a 
    queue (first in, first out). This is implemented by shifting array groups(2D array)
    to the left(towards[0]) when a transmission is fulfilled and adding to the last
    index (torwards[ength]) when a transmission is added to the queue.*/

    //Verify transmission tag and data are at the queue-front
    AUAC_BASE_BOOL verification = true;
    if(sendQueue[0][0] != tag || sendQueue[0][1] != data){
        verification = false;
        /*Error Handling*/

        //Exit
        return;
    }
    
    //Shift data left 
    //Iterate through structure and move (i) <- (i + 1)
    for(size_t i = 0; i < OutboundtransmissionQueueLimit;++i){
        sendQueue[i][0] = sendQueue[i + 1][0];
        sendQueue[i][1] = sendQueue[i + 1][1];
    }
}

//Driver Function to dispatch formatted data to output
AUAC_BASE_STRING Queue::dispatch(AUAC_BASE_STRING tag, AUAC_BASE_STRING data){
    //Object for tranfer class
    Transfer *func = new Transfer();
    //Determine Next task 
    AUAC_BASE_8 task = Queue::determineNextTask();
    
    //Delete Object
    delete func;
}

//Driver Function to receive formatted data from output
AUAC_BASE_STRING Queue::receive(AUAC_BASE_STRING tag){

}