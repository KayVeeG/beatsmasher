// ToneProvider.h

#ifndef _SMASH_TONE_PROVIDER_H_
#define _SMASH_TONE_PROVIDER_H_

#include <Arduino.h>
#include <memory>
#include "speaker.h"

namespace smash
{
    class ToneProvider
    {
    private:
        struct SpeakerNode
        {
            std::shared_ptr<Speaker> speaker;
            SpeakerNode* next;
            SpeakerNode(std::shared_ptr<Speaker> spk) : speaker(spk), next(nullptr) {}
        };

        bool m_isMaster;
        SpeakerNode* m_head;

    public:
        ToneProvider();
        ~ToneProvider();

        void addSpeaker(std::shared_ptr<Speaker> speaker);
        void removeSpeaker(std::shared_ptr<Speaker> speaker);
        void play(int index, note_t note, int octave);
        void stop(int index);
    };
}

#endif
