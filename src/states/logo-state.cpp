//
// Created by Elli Furedy on 1/25/2025.
//
//
// Created by Elli Furedy on 1/25/2025.
//
#include "nametag-states.hpp"

AlleycatLogoState::AlleycatLogoState() : State(alleycatLogo) {

}

AlleycatLogoState::~AlleycatLogoState() {

}

void AlleycatLogoState::onStateMounted(Device *device) {

}

void AlleycatLogoState::onStateLoop(Device *device) {

}

void AlleycatLogoState::onStateDismounted(Device *device) {

}

bool AlleycatLogoState::transitionToNameState() {
    return transitionToName;
}
