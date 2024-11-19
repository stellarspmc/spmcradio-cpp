#pragma once
#include <atomic>

#include "AudioFrameBuffer.h"
#include "../../../format/AudioDataFormat.h"

struct AudioFrameBufferFactory {
    AudioFrameBuffer create(int bufferDuration, AudioDataFormat format, std::atomic<bool> stopping);
};
