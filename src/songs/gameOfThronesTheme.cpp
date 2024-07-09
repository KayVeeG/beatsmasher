#ifndef GAME_OF_THRONES_THEME_CPP
#define GAME_OF_THRONES_THEME_CPP
#include "../types/song.cpp"

class GameOfThronesTheme : public Song
{
public:
    GameOfThronesTheme()
    {
        // Tempo is 85 BPM, so a quarter note is 60/85 = 0.705882 seconds
        float quarterNote = 60.0f / 85.0f * 3;
        float eighthNote = quarterNote / 2;
        float sixteenthNote = quarterNote / 4;
        float halfNote = quarterNote * 2;
        float wholeNote = quarterNote * 4;
        float dottedHalf = quarterNote * 3;
        float dottedQuarter = quarterNote * 1.5f;

        float currentTime = 0.0f;
        int currentLane = 0;

        addTone(SongTone(currentTime, NOTE_G, 4, dottedHalf, currentLane)); currentTime += dottedHalf;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_C, 4, dottedHalf, currentLane)); currentTime += dottedHalf;
        currentLane = (currentLane + 1) % 4;

        addTone(SongTone(currentTime, NOTE_Eb, 4, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_F, 4, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_G, 4, quarterNote, currentLane)); currentTime += quarterNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_C, 4, quarterNote, currentLane)); currentTime += quarterNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_Eb, 4, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_F, 4, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;

        addTone(SongTone(currentTime, NOTE_D, 4, wholeNote, currentLane)); currentTime += wholeNote;
        currentLane = (currentLane + 1) % 4;

        addTone(SongTone(currentTime, NOTE_F, 4, dottedHalf, currentLane)); currentTime += dottedHalf;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_Bb, 3, dottedHalf, currentLane)); currentTime += dottedHalf;
        currentLane = (currentLane + 1) % 4;

        addTone(SongTone(currentTime, NOTE_Eb, 4, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_D, 4, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_F, 4, quarterNote, currentLane)); currentTime += quarterNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_Bb, 3, dottedHalf, currentLane)); currentTime += dottedHalf;
        currentLane = (currentLane + 1) % 4;

        addTone(SongTone(currentTime, NOTE_Eb, 4, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_D, 4, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_C, 4, wholeNote, currentLane)); currentTime += wholeNote;
        currentLane = (currentLane + 1) % 4;

        // Continue adding the rest of the song following this pattern...

        // Last part (for demonstration, not the full song)
        addTone(SongTone(currentTime, NOTE_C, 5, eighthNote, currentLane)); currentTime += eighthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_G, 4, eighthNote, currentLane)); currentTime += eighthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_Gs, 4, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_Bb, 4, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;

        addTone(SongTone(currentTime, NOTE_C, 5, eighthNote, currentLane)); currentTime += eighthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_G, 4, eighthNote, currentLane)); currentTime += eighthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_Gs, 4, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_Bb, 4, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;

        currentTime += quarterNote; // REST
        addTone(SongTone(currentTime, NOTE_Gs, 5, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_Eb, 5, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_C, 6, eighthNote, currentLane)); currentTime += eighthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_G, 5, eighthNote, currentLane)); currentTime += eighthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_Gs, 5, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;
        addTone(SongTone(currentTime, NOTE_Eb, 5, sixteenthNote, currentLane)); currentTime += sixteenthNote;
        currentLane = (currentLane + 1) % 4;
    }
    ~GameOfThronesTheme() = default;
};
#endif