#ifndef _NOTE_GENERATOR_LOGIC_CPP
#define _NOTE_GENERATOR_LOGIC_CPP

#include <smash.h>
#include "../types/Song.cpp"
#include "../prefabs/noteBlock.cpp"

class NoteGeneratorLogic : public smash::BehaviourScript
{
    Song m_song;
    bool m_songGenerated = false;
    void generateSong()
    {
        
        SongTone tone = m_song.readTone();
        while (tone.timestamp != -1)
        {
            // Generate note
            auto instance = std::make_shared<NoteBlock>(tone.timestamp, tone.buttonIndex, tone.note, tone.octave, tone.duration);
            instantiate(instance);

            // next tone
            tone = m_song.readTone();
        }

    }
public:
    NoteGeneratorLogic() = default;
    ~NoteGeneratorLogic() = default;

    void setSong(const Song& song)
    {
        m_song = song;
        m_songGenerated = false;
    }

    void update(double deltaTime) override
    {
        if (!m_songGenerated)
        {
            generateSong();
            m_songGenerated = true;
        }
    }

    std::string getTypeName() const override
    {
        return "NoteGeneratorLogic";
    }

};

#endif