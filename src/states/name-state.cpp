//
// Created by Elli Furedy on 1/25/2025.
//
#include "nametag-states.hpp"

NameState::NameState() : State(displayName) {

}

NameState::~NameState() {
    
}

void NameState::onStateMounted(Device *device) {
    
}

void NameState::onStateLoop(Device *device) {
    
}

void NameState::onStateDismounted(Device *device) {
    
}

bool NameState::transitionToAlleycatLogoState() {
    return transitionToAlleycatLogo;
}

bool NameState::transitionToGlitchOutState() {
    return transitionToGlitchOut;
}