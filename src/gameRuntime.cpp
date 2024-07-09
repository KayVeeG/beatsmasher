#define R1_PIN 13
#define G1_PIN 12
#define B1_PIN 14
#define R2_PIN 27
#define G2_PIN 26
#define B2_PIN 25
#define A_PIN 23
#define B_PIN 22
#define C_PIN 21
#define D_PIN 19
#define E_PIN -1
#define CLK_PIN 18
#define LAT_PIN 5
#define OE_PIN 15


#ifndef _GAME_RUNTIME_CPP
#define _GAME_RUNTIME_CPP

#include <smash.h>
#include "scenes/SampleScene.cpp"

class GameRuntime : public smash::MasterRuntime
{
public:
    GameRuntime() = default;
    virtual ~GameRuntime() = default;

    void initialize() override
    {

        // Establish slave communication
        Serial.begin(115200);

        // Initialize scene
        auto initialScene = std::make_shared<SampleScene>();

        // Add scene
        addScene(initialScene);

        // Set active scene
        setActiveScene(initialScene.get());

       // Make matrix pins
        HUB75_I2S_CFG::i2s_pins _pins = {
            R1_PIN, G1_PIN, B1_PIN, R2_PIN, G2_PIN, B2_PIN,
            A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, LAT_PIN, OE_PIN, CLK_PIN
        };

        // Make matrix config
        HUB75_I2S_CFG mxconfig(
            64,   // Module width
            32,   // Module height
            1,    // Chain length
            _pins // Pin mapping
        );

        // initialze matrix
        auto matrix = std::make_shared<smash::Matrix>(mxconfig);

        // add matrix
        setDisplay(matrix);

    }
};

#endif