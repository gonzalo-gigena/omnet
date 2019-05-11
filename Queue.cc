#ifndef QUEUE
#define QUEUE

#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Queue: public cSimpleModule {
private:
    cQueue buffer;
    cPacket *endServiceEvent;
    simtime_t serviceTime;
    cOutVector bufferSizeVector;
    cOutVector packetDropVector;
public:
    Queue();
    virtual ~Queue();
protected:
    virtual void initialize();
    virtual void finish();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Queue);

Queue::Queue() {
    endServiceEvent = NULL;
}

Queue::~Queue() {
    cancelAndDelete(endServiceEvent);
}

void Queue::initialize() {
    //stats
    bufferSizeVector.setName("Buffer Size");
    packetDropVector.setName("Packets Lost");

    buffer.setName("buffer");
    endServiceEvent = new cPacket("endService");
}

void Queue::finish() {
}

void Queue::handleMessage(cMessage *msg) {
    // causes an error
    if( buffer.getLength() >= par("bufferSize").longValue() ){

        delete msg;
        this->bubble("packet dropped");
        packetDropVector.record(1);

    }else if (msg == endServiceEvent) {
        // if packet in buffer, send next one
        if (!buffer.isEmpty()) {
            // dequeue packet
            cPacket *pkt = (cPacket*) buffer.pop();
            // send packet
            send(pkt, "out");
            // start new service
            serviceTime = pkt->getDuration();
            scheduleAt(simTime() + serviceTime, endServiceEvent);
        }
    }  else {

        buffer.insert(msg);
        bufferSizeVector.record(buffer.getLength());

        if (!endServiceEvent->isScheduled()) {
            // start the service
            scheduleAt(simTime(), endServiceEvent);
        }
    }
}

#endif /* QUEUE */
