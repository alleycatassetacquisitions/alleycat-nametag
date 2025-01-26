//
// Created by Elli Furedy on 1/25/2025.
//
#include "nametag-app.hpp"

#include "nametag-states.hpp"

NameTagApp::NameTagApp(Device* nametag) : StateMachine(nametag) {

  }

NameTagApp::~NameTagApp() {
}

void NameTagApp::populateStateMap() {
  BootupState* bootup = new BootupState();
  NameState* nameState = new NameState();
  GlitchOutState* glitch = new GlitchOutState();
  AlleycatLogoState* alleycat = new AlleycatLogoState();

  bootup->addTransition(
    new StateTransition(
      std::bind(&BootupState::transitionToNameState, bootup),
      nameState));

  nameState->addTransition(
  new StateTransition(
    std::bind(&NameState::transitionToGlitchOutState, nameState),
    glitch));

  nameState->addTransition(
  new StateTransition(
    std::bind(&NameState::transitionToAlleycatLogoState, nameState),
    alleycat));

  glitch->addTransition(
  new StateTransition(
    std::bind(&GlitchOutState::transitionToNameState, glitch),
    nameState));

  alleycat->addTransition(
  new StateTransition(
    std::bind(&AlleycatLogoState::transitionToNameState, alleycat),
    nameState));

  stateMap.push_back(bootup);
  stateMap.push_back(nameState);
  stateMap.push_back(glitch);
  stateMap.push_back(alleycat);
}
