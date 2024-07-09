#ifndef _SONG_CPP
#define _SONG_CPP

#include <Arduino.h>
#include <queue>

struct SongTone
{
    float timestamp;
    note_t note;
    int octave;
    float duration;
    int buttonIndex;
    SongTone(float timestamp, note_t note, int octave, float duration, int buttonIndex)
     : timestamp{timestamp},  note{note}, octave{octave}, duration{duration}, buttonIndex{buttonIndex} {}
};

class Song
{
    std::queue<SongTone> tones;
protected:
    void addTone(SongTone tone)
    {
        tones.push(tone);
    }
public:
    Song() = default;
    ~Song() = default;

    // Copy constructor
    Song(const Song& other) : tones(other.tones)
    {
        // The std::queue copy constructor is called to copy the tones
    }

    // Assignment operator overload
    Song& operator=(const Song& other)
    {
        if (this != &other) // Check for self-assignment
        {
            Serial.println("ACTUALLY COPYING QUEUE");
            tones = other.tones; // Use std::queue's assignment operator
        }
        return *this;
    }

    SongTone readTone()
    {
        if (tones.empty())
        {
            return SongTone{-1, NOTE_C, -1, -1, -1};
        }
        SongTone tone = tones.front();
        tones.pop();
        return tone;
    }
};

#endif
