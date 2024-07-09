#ifndef _NOTE_GENERATOR_LOGIC_HPP
#define _NOTE_GENERATOR_LOGIC_HPP

#include <smash.h>
#include "types/song.cpp"

class NoteGeneratorLogic : public smash::BehaviourScript
{
    double m_SongGenerationTime = -1;
private:
    Song m_song;
    bool m_songGenerated = false;
    void generateSong();

public:
    NoteGeneratorLogic() = default;
    ~NoteGeneratorLogic() = default;

    void setSong(const Song& song);
    void update(double deltaTime) override;
    std::string getTypeName() const override;
    void generateNextNote();
};
#endif