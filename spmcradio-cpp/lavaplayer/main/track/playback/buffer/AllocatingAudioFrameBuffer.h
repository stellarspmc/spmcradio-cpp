#pragma once
#include "AbstractAudioFrameBuffer.h"

struct AllocatingAudioFrameBuffer : AbstractAudioFrameBuffer {
    AllocatingAudioFrameBuffer(int bufferDuration, AudioDataFormat format, std::atomic<bool> stopping) {
        this->format = format;
        this->synchronizer = new object();
        locked = false;
        receivedFrames = false;
        terminated = false;
        terminateOnEmpty = false;
        clearOnInsert = false;
        this->fullCapacity = bufferDuration / 20 + 1;
        this->audioFrames = new ArrayBlockingQueue<>(fullCapacity);
        this->stopping = stopping;
    }
    
    int getRemainingCapacity();
    int getFullCapacity();
    void waitForTermination();
    void setTerminateOnEmpty();
    void setClearOnInsert();
    bool hasClearOnInsert();
    void clear();
    void lockBuffer();
    bool hasReceivedFrames();
    long getLastInputTimecode();

private:
    int fullCapacity;
    ArrayBlockingQueue<AudioFrame> audioFrames;
    std::atomic<bool> stopping;
};
