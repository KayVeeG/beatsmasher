#ifndef _ALLEMEINEENTCHEN_CPP
#define _ALLEMEINEENTCHEN_CPP

#include "../types/song.cpp"

class AlleMeineEntchen : public Song
{
public:

    AlleMeineEntchen()
    {
        addTone(SongTone(0, NOTE_C, 3, 1.0f, 0));
        addTone(SongTone(1, NOTE_E, 3, 1.0f, 1));
        addTone(SongTone(2, NOTE_G, 3, 1.0f, 2));
        addTone(SongTone(3, NOTE_C, 4, 1.0f, 3));
        addTone(SongTone(4, NOTE_C, 4, 1.0f, 0));
        addTone(SongTone(5, NOTE_E, 4, 1.0f, 1));
        addTone(SongTone(6, NOTE_G, 4, 1.0f, 2));
        addTone(SongTone(7, NOTE_C, 5, 1.0f, 3));

    }
    ~AlleMeineEntchen() = default;
};

#endif
