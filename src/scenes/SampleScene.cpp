#ifndef _SAMPLE_SCENE_CPP
#define _SAMPLE_SCENE_CPP

#include <smash.h>
#include "../prefabs/noteBlock.cpp"
#include "../prefabs/noteGenerator.cpp"
#include "../songs/cantinaBand.cpp"
#include "../songs/marioOverworldTheme.cpp"
#include "../songs/gameOfThronesTheme.cpp"

class SampleScene : public smash::Scene
{

public:
    SampleScene()
    {
        
        // Init tone generator
        auto toneGenerator = std::make_shared<ToneGenerator>();
        
        // Set the song
        auto song = GameOfThronesTheme();
        auto noteGeneratorLogic = (NoteGeneratorLogic*)toneGenerator->getComponent("NoteGeneratorLogic");
        noteGeneratorLogic->setSong(song);

        // Instantiate tone generator
        instantiate(std::static_pointer_cast<smash::GameObject>(toneGenerator));

        /*

       instantiate(std::make_shared<NoteBlock>(0.0f, 0, NOTE_C, 4, 1.0f));
       instantiate(std::make_shared<NoteBlock>(1.0f, 1, NOTE_E, 4, 1.0f));
       instantiate(std::make_shared<NoteBlock>(2.0f, 2, NOTE_G, 4, 1.0f));
       instantiate(std::make_shared<NoteBlock>(3.0f, 3, NOTE_C, 5, 3.0f));
*/
    }
    ~SampleScene() = default;

};

#endif