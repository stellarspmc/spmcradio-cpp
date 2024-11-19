#pragma once
#include <stdexcept>

#include "../AudioTrackExecutor.h"
#include "../../AudioTrackInfo.h"
#include "../../marker/TrackMarkerTracker.h"
#include "../buffer/AudioFrameBuffer.h"
#include "../frame/AudioFrame.h"

struct PrimordialAudioTrackExecutor : AudioTrackExecutor {
    PrimordialAudioTrackExecutor(AudioTrackInfo trackInfo) {
        this->trackInfo = trackInfo;
        this->markerTracker = new TrackMarkerTracker();
    }

    static AudioFrameBuffer getAudioBuffer() {
        return 0;
    }

    static void execute(TrackStateListener listener) {
        throw std::runtime_error("Invalid operation");
    }

    void stop() {
        log.info("Tried to stop track {} which is not playing.", trackInfo.identifier);
    }

    long getPosition() {
        return position;
    }

    void setPosition(long timecode) {
        position = timecode;
        markerTracker.checkSeekTimecode(timecode);
    }

    static AudioTrackState getState() {
        return inactive;
    }

    void setMarker(TrackMarker marker) {
        markerTracker.set(marker, position);
    }

    void addMarker(TrackMarker marker) {
        markerTracker.add(marker, getPosition());
    }

    void removeMarker(TrackMarker marker) {
        markerTracker.remove(marker);
    }

    bool failedBeforeLoad() {
        return false;
    }

    AudioFrame provide() {
        //return provide(0, TimeUnit.MILLISECONDS);
        return 0;
    }

    AudioFrame provide(long timeout, tm unit) {
        return 0;
    }

    bool provide(MutableAudioFrame targetFrame) {
        return false;
    }

    bool provide(MutableAudioFrame targetFrame, long timeout, tm unit) {
        return false;
    }

    void applyStateToExecutor(AudioTrackExecutor executor) {
        if (position != 0) {
            executor.setPosition(position);
        }

        for (TrackMarker marker : markerTracker.getMarkers()) {
            executor.addMarker(marker);
        }

        markerTracker.clear();
    }
private:
    //static Logger log = LoggerFactory.getLogger(LocalAudioTrackExecutor.class);

    AudioTrackInfo trackInfo;
    TrackMarkerTracker markerTracker;

    volatile long position;
};
