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
        
        // Init tone generator
        auto toneGenerator = std::make_shared<ToneGenerator>();
        
        // Set the song
        auto song = AlleMeineEntchen();
        auto noteGeneratorLogic = (NoteGeneratorLogic*)toneGenerator->getComponent("NoteGeneratorLogic");
        noteGeneratorLogic->setSong(song);

        // Instantiate tone generator
        instantiate(std::static_pointer_cast<smash::GameObject>(toneGenerator));

    }
    ~SampleScene() = default;

};

#endif