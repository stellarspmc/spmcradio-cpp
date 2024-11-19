#pragma once

enum AudioTrackState : std::int8_t {
    inactive,
    loading,
    playing,
    seeking,
    stopping,
    finished
};