
#ifndef CANTINA_BAND_CPP
#define CANTINA_BAND_CPP

#include "../types/song.cpp"

class CantinaBand : public Song
{
public:
    CantinaBand()
    {
        // Tempo is 140 BPM, so a quarter note is 60/140 = 0.42857 seconds
        float quarterNote = 60.0f / 140.0f * 4;
        float eighthNote = quarterNote / 2;
        float sixteenthNote = quarterNote / 4;
        float dottedQuarter = quarterNote * 1.5f;
        float dottedHalf = quarterNote * 3;

        float currentTime = 0.0f;

        addTone(SongTone(currentTime, NOTE_B, 4, dottedQuarter, 0)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_E, 5, dottedQuarter, 3)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_B, 4, dottedQuarter, 1)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_E, 5, dottedQuarter, 4)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_B, 4, eighthNote, 2)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_E, 5, dottedQuarter, 5)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_B, 4, eighthNote, 0)); currentTime += eighthNote;
        currentTime += eighthNote; // REST
        addTone(SongTone(currentTime, NOTE_Bb, 4, eighthNote, 6)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_B, 4, eighthNote, 1)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_B, 4, eighthNote, 3)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_Bb, 4, eighthNote, 7)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_B, 4, eighthNote, 2)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_A, 4, eighthNote, 5)); currentTime += eighthNote;
        currentTime += eighthNote; // REST
        addTone(SongTone(currentTime, NOTE_Gs, 4, eighthNote, 0)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_A, 4, eighthNote, 4)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_G, 4, eighthNote, 1)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_G, 4, quarterNote, 6)); currentTime += quarterNote;
        addTone(SongTone(currentTime, NOTE_E, 4, dottedHalf, 3)); currentTime += dottedHalf;
        addTone(SongTone(currentTime, NOTE_B, 4, dottedQuarter, 7)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_E, 5, dottedQuarter, 2)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_B, 4, dottedQuarter, 5)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_E, 5, dottedQuarter, 0)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_B, 4, eighthNote, 4)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_E, 5, dottedQuarter, 1)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_B, 4, eighthNote, 6)); currentTime += eighthNote;
        currentTime += eighthNote; // REST
        addTone(SongTone(currentTime, NOTE_Bb, 4, eighthNote, 3)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_B, 4, eighthNote, 7)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_A, 4, dottedQuarter, 2)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_A, 4, dottedQuarter, 5)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_Gs, 4, eighthNote, 0)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_A, 4, dottedQuarter, 4)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_D, 5, eighthNote, 1)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_C, 5, dottedQuarter, 6)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_B, 4, dottedQuarter, 3)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_A, 4, dottedQuarter, 7)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_B, 4, dottedQuarter, 2)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_E, 5, dottedQuarter, 5)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_B, 4, dottedQuarter, 0)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_E, 5, dottedQuarter, 4)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_B, 4, eighthNote, 1)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_E, 5, dottedQuarter, 6)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_B, 4, eighthNote, 3)); currentTime += eighthNote;
        currentTime += eighthNote; // REST
        addTone(SongTone(currentTime, NOTE_Bb, 4, eighthNote, 7)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_B, 4, eighthNote, 2)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_D, 5, quarterNote, 5)); currentTime += quarterNote;
        addTone(SongTone(currentTime, NOTE_D, 5, dottedQuarter, 0)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_B, 4, eighthNote, 4)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_A, 4, dottedQuarter, 1)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_G, 4, dottedQuarter, 6)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_E, 4, dottedHalf, 3)); currentTime += dottedHalf;
        addTone(SongTone(currentTime, NOTE_E, 4, quarterNote * 2, 7)); currentTime += quarterNote * 2;
        addTone(SongTone(currentTime, NOTE_G, 4, quarterNote * 2, 2)); currentTime += quarterNote * 2;
        addTone(SongTone(currentTime, NOTE_B, 4, quarterNote * 2, 5)); currentTime += quarterNote * 2;
        addTone(SongTone(currentTime, NOTE_D, 5, quarterNote * 2, 0)); currentTime += quarterNote * 2;
        addTone(SongTone(currentTime, NOTE_F, 5, dottedQuarter, 4)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_E, 5, dottedQuarter, 1)); currentTime += dottedQuarter;
        addTone(SongTone(currentTime, NOTE_Bb, 4, eighthNote, 6)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_Bb, 4, eighthNote, 3)); currentTime += eighthNote;
        addTone(SongTone(currentTime, NOTE_B, 4, quarterNote, 7)); currentTime += quarterNote;
        addTone(SongTone(currentTime, NOTE_G, 4, quarterNote, 2)); currentTime += quarterNote;
    }
    ~CantinaBand() = default;
};
#endif