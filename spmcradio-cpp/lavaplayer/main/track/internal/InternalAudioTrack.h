#pragma once
#include "../AudioTrack.h"
#include "../playback/AudioFrameProvider.h"
#include "../playback/AudioTrackExecutor.h"
#include "../playback/LocalAudioTrackExecutor.h"
#include "../../player/AudioPlayerManager.h"

struct internal_audio_track : audio_track, audio_frame_provider {
    void assign_executor(AudioTrackExecutor executor, bool apply_primordial_state);
    AudioTrackExecutor get_active_executor();
    AudioTrackExecutor create_local_executor(AudioPlayerManager player_manager);

    void process(local_audio_track_executor executor);
};
