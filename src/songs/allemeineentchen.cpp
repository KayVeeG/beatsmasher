#ifndef _ALLEMEINEENTCHEN_CPP
#define _ALLEMEINEENTCHEN_CPP

#include "../types/song.cpp"

class AlleMeineEntchen : public Song
{
public:
    AlleMeineEntchen()
    {
        // Assuming 4/4 time signature, quarter note = 1.0 duration
        float timestamp = 0.0f;
        int buttonIndex = 0; // Adjust as needed

        // "Alle meine Entchen"
        addTone(SongTone(timestamp, NOTE_C, 4, 1.0f, buttonIndex)); timestamp += 1.0f;
        addTone(SongTone(timestamp, NOTE_D, 4, 1.0f, buttonIndex)); timestamp += 1.0f;
        addTone(SongTone(timestamp, NOTE_E, 4, 1.0f, buttonIndex)); timestamp += 1.0f;
        addTone(SongTone(timestamp, NOTE_F, 4, 1.0f, buttonIndex)); timestamp += 1.0f;

        // "schwimmen auf dem See"
        addTone(SongTone(timestamp, NOTE_G, 4, 1.0f, buttonIndex)); timestamp += 1.0f;
        addTone(SongTone(timestamp, NOTE_G, 4, 1.0f, buttonIndex)); timestamp += 1.0f;
        addTone(SongTone(timestamp, NOTE_A, 4, 1.0f, buttonIndex)); timestamp += 1.0f;
        addTone(SongTone(timestamp, NOTE_A, 4, 1.0f, buttonIndex)); timestamp += 1.0f;

        // "schwimmen auf dem See" (repeat)
        addTone(SongTone(timestamp, NOTE_G, 4, 1.0f, buttonIndex)); timestamp += 1.0f;
        addTone(SongTone(timestamp, NOTE_G, 4, 1.0f, buttonIndex)); timestamp += 1.0f;
        addTone(SongTone(timestamp, NOTE_F, 4, 2.0f, buttonIndex)); timestamp += 2.0f;

        // "Köpfchen in das Wasser"
        addTone(SongTone(timestamp, NOTE_A, 4, 1.0f, buttonIndex)); timestamp += 1.0f;
        addTone(SongTone(timestamp, NOTE_A, 4, 1.0f, buttonIndex)); timestamp += 1.0f;
        addTone(SongTone(timestamp, NOTE_A, 4, 1.0f, buttonIndex)); timestamp += 1.0f;
        addTone(SongTone(timestamp, NOTE_A, 4, 1.0f, buttonIndex)); timestamp += 1.0f;

        // "Schwänzchen in die Höh"
        addTone(SongTone(timestamp, NOTE_G, 4, 1.0f, buttonIndex)); timestamp += 1.0f;
        addTone(SongTone(timestamp, NOTE_G, 4, 1.0f, buttonIndex)); timestamp += 1.0f;
        addTone(SongTone(timestamp, NOTE_F, 4, 2.0f, buttonIndex)); timestamp += 2.0f;
    }
    ~AlleMeineEntchen() = default;
};

#endif
