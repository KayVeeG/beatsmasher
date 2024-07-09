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
        /*
        SongTone tone = m_song.readTone();
        while (tone.timestamp != -1)
        {
            // Generate note
            auto instance = std::make_shared<NoteBlock>(tone.timestamp, tone.buttonIndex, tone.note, tone.octave, tone.duration);
            instantiate(instance);

            // next tone
            tone = m_song.readTone();
        }*/

        // Generate note block
        auto instance = std::make_shared<NoteBlock>(0.0f, 0, NOTE_C, 4, 1.0f);
        instantiate(instance);

        // Generate note block
        auto instance2 = std::make_shared<NoteBlock>(0.0f, 1, NOTE_E, 4, 1.0f);
        instantiate(instance2);

        // Generate note block
        //instance = std::make_shared<NoteBlock>(-2.0f, 2, NOTE_G, 4, 3.0f);
        //instantiate(instance);
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