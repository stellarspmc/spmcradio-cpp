#pragma once

#include <ctime>
#include "AudioFrame.h"
#include "MutableAudioFrame.h"

struct audio_frame_provider {
    audio_frame provide();
    audio_frame provide(long timeout, tm unit);
    bool provide(mutable_audio_frame target_frame);
    bool provide(mutable_audio_frame target_frame, long timeout, tm unit);
};
