//
// Created by Elli Furedy on 1/25/2025.
//
#include "nametag-states.hpp"

BootupState::BootupState() : State(bootup) {

}

BootupState::~BootupState() {

}

void BootupState::onStateMounted(Device *device) {

}

void BootupState::onStateLoop(Device *device) {

}

void BootupState::onStateDismounted(Device *device) {

}

bool BootupState::transitionToNameState() {
    return transitionToName;
}
