//
// Created by Elli Furedy on 1/25/2025.
//
#pragma once

#include "state-machine.hpp"

class NameTagApp : public StateMachine {
public:
    NameTagApp(Device* nametag);
    ~NameTagApp();

    void populateStateMap() override;

};
