#pragma once

#include <string>
#include "main.h"

// selector configuration
// #define HUE 130
// #define DEFAULT 1
// #define AUTONS "Far Side", "Close Side", "Do Nothing"

namespace strait
{
    namespace selector
    {
        extern int auton;
        void init();
    }

    //extern const char *b[];
    //void init(int hue = HUE, int default_auton = DEFAULT, const char **autons = b);

}