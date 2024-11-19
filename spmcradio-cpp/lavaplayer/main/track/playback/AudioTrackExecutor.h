#pragma once
#include "AudioFrameBuffer.h"
#include "AudioFrameProvider.h"
#include "../AudioTrackState.h"
#include "../TrackStateListener.h"
#include "../marker/TrackMarker.h"

struct AudioTrackExecutor : audio_frame_provider {
    AudioFrameBuffer getAudioBuffer();

    void execute(TrackStateListener listener);
    void stop();
    
    long getPosition();
    void setPosition(long timecode);
    
    AudioTrackState get_state();

    void setMarker(TrackMarker marker);
    void addMarker(TrackMarker marker);
    void removeMarker(TrackMarker marker);
    
    bool failedBeforeLoad();
};
