#pragma once
#include "AudioFrameBuffer.h"
#include "../../../format/AudioDataFormat.h"
#include "../../../../../javareplica/Object.h"

class AbstractAudioFrameBuffer : AudioFrameBuffer {
protected:
    AudioDataFormat format;
    object synchronizer;
    volatile bool locked;
    volatile bool receivedFrames;
    bool terminated;
    bool terminateOnEmpty;
    bool clearOnInsert;

    AbstractAudioFrameBuffer(AudioDataFormat format) {
        this->format = format;
        this->synchronizer = new object();
        locked = false;
        receivedFrames = false;
        terminated = false;
        terminateOnEmpty = false;
        clearOnInsert = false;
    }

    void signalWaiters();
public:
    void waitForTermination() {
        /* synchronized (synchronizer) {
            while (!terminated) {
                synchronizer.wait();
            }
        } */
    }
    
    void setTerminateOnEmpty()
    {
        /*
        synchronized (synchronizer) {
        // Count this also as inserting the terminator frame, hence trigger clearOnInsert
        if (clearOnInsert) {
        clear();
        clearOnInsert = false;
        }

        if (!terminated) {
        terminateOnEmpty = true;
        signalWaiters();
        }
        }
         */
    }
    
    void setClearOnInsert()
    {
        /*
        synchronized (synchronizer) {
            clearOnInsert = true;
            terminateOnEmpty = false;
        }
         */
    }
    
    bool hasClearOnInsert() {
        return clearOnInsert;
    }
    
    void lockBuffer() {
        locked = true;
    }
    
    bool hasReceivedFrames() {
        return receivedFrames;
    }
};
