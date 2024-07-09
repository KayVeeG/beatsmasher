#ifndef _SAMPLE_SCENE_CPP
#define _SAMPLE_SCENE_CPP

#include <smash.h>
#include "../prefabs/noteBlock.cpp"
#include "../prefabs/noteGenerator.cpp"
#include "../songs/AlleMeineEntchen.cpp"

class SampleScene : public smash::Scene
{

public:
    SampleScene()
    {
        /*
        // Init tone generator
        auto toneGenerator = std::make_shared<ToneGenerator>();
        
        // Set the song
        auto song = AlleMeineEntchen();
        auto noteGeneratorLogic = (NoteGeneratorLogic*)toneGenerator->getComponent("NoteGeneratorLogic");
        noteGeneratorLogic->setSong(song);

        // Instantiate tone generator
        instantiate(std::static_pointer_cast<smash::GameObject>(toneGenerator));*/

        instantiate(std::make_shared<NoteBlock>(0.0f, 0, NOTE_C, 4, 1.0f));
        instantiate(std::make_shared<NoteBlock>(0.0f, 1, NOTE_E, 4, 2.0f));
    }
    ~SampleScene() = default;

};

#endif