#pragma once
#include "AudioFrame.h"
#include "AudioFrameRebuilder.h"

struct AudioFrameConsumer {
    void consume(AudioFrame frame);
    void rebuild(AudioFrameRebuilder rebuilder);
};
