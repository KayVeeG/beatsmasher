#ifndef _SAMPLE_SCENE_CPP
#define _SAMPLE_SCENE_CPP

#include <smash.h>
#include "../prefabs/noteBlock.cpp"

class SampleScene : public smash::Scene
{

public:
    SampleScene()
    {
        instantiate(std::make_shared<NoteBlock>());
    }
    ~SampleScene() = default;

};

#endif