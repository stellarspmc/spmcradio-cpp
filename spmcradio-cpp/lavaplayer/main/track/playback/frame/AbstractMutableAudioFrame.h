#pragma once
#include "AudioFrame.h"
#include "../../../format/AudioDataFormat.h"

class AbstractMutableAudioFrame : AudioFrame {
public:
     long getTimecode() {
          return timecode;
     }

     void setTimecode(long timecode) {
          this.timecode = timecode;
     }

     int getVolume() {
          return volume;
     }

     void setVolume(int volume) {
          this->volume = volume;
     }

     AudioDataFormat getFormat() {
          return format;
     }

     void setFormat(AudioDataFormat format) {
          this->format = format;
     }

     bool isTerminator() {
          return terminator;
     }

     void setTerminator(bool terminator) {
          this->terminator = terminator;
     }

    ImmutableAudioFrame freeze() {
          return new ImmutableAudioFrame(timecode, getData(), volume, format);
     }

private:
     long timecode;
     int volume;
     AudioDataFormat format;
     bool terminator;
};
