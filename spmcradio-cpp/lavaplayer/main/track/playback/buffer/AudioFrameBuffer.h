#pragma once
#include "../frame/AudioFrameConsumer.h"
#include "../frame/AudioFrameProvider.h"

struct AudioFrameBuffer : AudioFrameProvider, AudioFrameConsumer {
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
};
