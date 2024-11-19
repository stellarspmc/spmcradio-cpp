#pragma once
#include <ctime>

#include "AudioFrame.h"
#include "../MutableAudioFrame.h"

struct AudioFrameProvider {
    AudioFrame provide();
    AudioFrame provide(long timeout, tm unit);
    bool provide(MutableAudioFrame targetFrame);
    bool provide(MutableAudioFrame targetFrame, long timeout, tm unit);
};
