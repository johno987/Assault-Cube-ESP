#pragma once
#include "Entity.h"
#include "Globals.h"

void EntityList::printEntLocations()
{
    for (int i{}; i < 12; ++i) //when we have the max number of players replace the number in the loop
    {
        auto CurrentEntity = entList->entities[i];

        if (CurrentEntity != nullptr && CurrentEntity != LocalPlayer)
        {
            printf("Enemy Health: %d X: %f Y: %f Z: %f\n",
                CurrentEntity->Health, \
                CurrentEntity->HeadPos.x,
                CurrentEntity->HeadPos.y,
                CurrentEntity->HeadPos.z);
        }
    }
}
