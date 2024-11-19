#pragma once
#include <atomic>
#include <stdexcept>
#include "../AudioTrack.h"
#include "../internal/InternalAudioTrack.h"
#include "../marker/TrackMarker.h"
#include "../playback/primordial/PrimordialAudioTrackExecutor.h"

class BaseAudioTrack : internal_audio_track {
public:
    BaseAudioTrack(const AudioTrackInfo info) {
        trackInfo = info;
        executorAssigned = new std::atomic<bool>();
        initialExecutor = new PrimordialAudioTrackExecutor(trackInfo);
        activeExecutor = new std::atomic<AudioTrackExecutor>();
        accurateDuration = new std::atomic<long>(0);
    }
    
    void assignExecutor(AudioTrackExecutor executor, bool applyPrimordialState) {
        if (executorAssigned.compareAndSet(false, true)) {
            if (applyPrimordialState) {
                initialExecutor.applyStateToExecutor(executor);
            }
            activeExecutor.store(executor);
        } else {
            throw std::invalid_argument("Cannot play the same instance of a track twice, use track.makeClone().");
        }
    }

    AudioTrackExecutor getActiveExecutor() const {
        return activeExecutor.load();
    }

   void stop() {
        AudioTrackExecutor executor = activeExecutor.getAndSet(NULL);
        //if (executor == NULL) return;

        initialExecutor.setPosition(executor.getPosition());
        executor.stop();
    }

    AudioTrackState getState() {
        return getActiveExecutor().getState();
    }

    std::string getIdentifier() {
        return trackInfo.identifier;
    }

    bool isSeekable() {
        return !trackInfo.isStream;
    }

    long getPosition() {
        return getActiveExecutor().getPosition();
    }

    void setPosition(long position) {
        getActiveExecutor().setPosition(position);
    }

    void setMarker(TrackMarker marker) {
        getActiveExecutor().setMarker(marker);
    }

    void addMarker(TrackMarker marker) const {
        getActiveExecutor().addMarker(marker);
    }

    void removeMarker(TrackMarker marker) const {
        getActiveExecutor().removeMarker(marker);
    }

    audio_frame provide() {
        return getActiveExecutor().provide();
    }

    audio_frame provide(const long timeout, tm unit) {
        return getActiveExecutor().provide(timeout, unit);
    }

    bool provide(const mutable_audio_frame target_frame) {
        return getActiveExecutor().provide(target_frame);
    }

    bool provide(const mutable_audio_frame target_frame, const long timeout, tm unit) {
        return getActiveExecutor().provide(target_frame, timeout, unit);
    }

    AudioTrackInfo getInfo() {
        return trackInfo;
    }

    long getDuration() const {
        if (accurateDuration.load() == 0) {
            return trackInfo.length;
        } {
            return accurateDuration.load();
        }
    }

    audio_track makeClone() const {
        audio_track track = makeShallowClone();
        track.set_user_data(userData);
        return track;
    }

    AudioSourceManager getSourceManager() {
        return NULL;
    }

    AudioTrackExecutor createLocalExecutor(AudioPlayerManager playerManager) {
        return NULL;
    }

    void setUserData(object userData) {
        this->userData = userData;
    }

    object getUserData() {
        return userData;
    }

private:
    primordial_audio_track_executor initialExecutor;
    std::atomic<bool> executorAssigned;
    std::atomic<AudioTrackExecutor> activeExecutor;
    volatile object userData;

protected:
    AudioTrackInfo trackInfo;
    std::atomic<long> accurateDuration;
    
    static audio_track makeShallowClone() {
        throw std::runtime_error("Invalid operation");
    }
};
