/*********************************************************************
Matt Marchant 2016
http://trederia.blogspot.com

DoodleChum - Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#ifndef DC_MESSAGE_IDS_HPP_
#define DC_MESSAGE_IDS_HPP_

#include <xygine/MessageBus.hpp>

namespace Particle
{
    enum ID
    {
        Steam = 0x1,
        Music = 0x2,
        Sleep = 0x4
    };
}

namespace Message
{
    enum ID
    {
        TimeOfDay = xy::Message::Count,
        NewTask,
        TaskCompleted,
        Animation,
        Particle
    };

    struct TODEvent final
    {
        float time = 0.f; //< TODO really got to fix this being out by 12 hours
        float sunIntensity = 0.f;
    };

    struct TaskEvent
    {
        enum Name
        {
            Eat,
            Drink,
            Poop,
            Shower,
            Sleep,
            WatchTV,
            PlayPiano,
            PlayMusic,
            PlayComputer,
            Think,
            Travel
        }taskName;
    };

    struct AnimationEvent
    {
        enum ID
        {
            Up = 0,
            Down,
            Right,
            Left,
            Idle,
            Eat,
            Drink,
            Poop,
            TV,
            Piano,
            Computer,
            Sleep,
            Count
        }id;
    };
}

#endif //DC_MESSAGE_IDS_HPP_