#pragma once

#include <string>

#include "AudioItem.h"
#include "AudioTrackInfo.h"
#include "AudioTrackState.h"
#include "marker/TrackMarker.h"
#include "../source/AudioSourceManager.h"
#include "../../../javareplica/Object.h"

struct audio_track : audio_item {
    AudioTrackInfo get_info();
    std::string get_identifier();
    AudioTrackState get_state();
    
    void stop();
    bool is_seekable();
    
    long get_position();
    void set_position(long position);
    long get_duration();
    
    void add_marker(TrackMarker marker);
    void set_marker(TrackMarker marker);
    void remove_marker(TrackMarker marker);

    audio_track make_clone();

    AudioSourceManager get_source_manager();

    void set_user_data(object user_data);
    object get_user_data();
};
