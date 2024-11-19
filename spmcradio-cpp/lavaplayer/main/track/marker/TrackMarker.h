#pragma once
#include "TrackMarkerHandler.h"

struct TrackMarker {
    TrackMarker(long timecode, TrackMarkerHandler handler) {
        this->timecode = timecode;
        this->handler = handler;
    }

    long timecode;
    TrackMarkerHandler handler;
};
