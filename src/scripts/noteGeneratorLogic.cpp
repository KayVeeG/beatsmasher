#include <NoteGeneratorLogic.h>
#include "../prefabs/noteBlock.cpp"
#include <memory>

void NoteGeneratorLogic::generateSong()
{
    SongTone tone = m_song.readTone();
    constexpr int bufferSize = 4;
    int bufferCounter = 0;
    while (tone.timestamp != -1 && bufferCounter < bufferSize)
    {
        // Generate note
        auto instance = std::make_shared<NoteBlock>(tone.timestamp, tone.buttonIndex, tone.note, tone.octave, tone.duration);
        // Get the note block logic
        auto noteBlockLogic = static_cast<NoteBlockLogic*>(instance->getComponent("NoteBlockLogic"));
        if (noteBlockLogic)
        {
            noteBlockLogic->setGeneratorCallback(this);        
        }
        instantiate(instance);

        // next tone
        if (bufferCounter + 1 != bufferSize)
        {
            tone = m_song.readTone();
        }


        bufferCounter += 1;
    }
    m_SongGenerationTime = esp_timer_get_time();
}

void NoteGeneratorLogic::setSong(const Song& song)
{
    m_song = song;
    m_songGenerated = false;
}

void NoteGeneratorLogic::update(double deltaTime)
{
    if (!m_songGenerated)
    {
        generateSong();
        m_songGenerated = true;
    }
}

std::string NoteGeneratorLogic::getTypeName() const
{
    return "NoteGeneratorLogic";
}

void NoteGeneratorLogic::generateNextNote()
{
    SongTone tone = m_song.readTone();
    if (tone.timestamp != -1)
    {
        // Generate note
        tone.timestamp -= (float)(esp_timer_get_time() - m_SongGenerationTime) / 1000000.0f;
        auto instance = std::make_shared<NoteBlock>(tone.timestamp, tone.buttonIndex, tone.note, tone.octave, tone.duration);
        // Get the note block logic
        auto noteBlockLogic = static_cast<NoteBlockLogic*>(instance->getComponent("NoteBlockLogic"));
        if (noteBlockLogic)
        {
            noteBlockLogic->setGeneratorCallback(this);        
        }
        instantiate(instance);
    }
}
