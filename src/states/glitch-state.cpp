//
// Created by Elli Furedy on 1/25/2025.
//
//
// Created by Elli Furedy on 1/25/2025.
//
#include "nametag-states.hpp"

GlitchOutState::GlitchOutState() : State(glitchOut) {

}

GlitchOutState::~GlitchOutState() {

}

void GlitchOutState::onStateMounted(Device *device) {

}

void GlitchOutState::onStateLoop(Device *device) {

}

void GlitchOutState::onStateDismounted(Device *device) {

}

bool GlitchOutState::transitionToNameState() {
    return transitionToName;
}
