#pragma once
#include "Entity.h"
#include "Globals.h"

void EntityList::printEntLocations()
{
    for (int i{}; i < *maxNumbersOfPlayers; ++i) //should not overflow now as 
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
