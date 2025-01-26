//
// Created by Elli Furedy on 1/25/2025.
//
#pragma once
#include <state.hpp>

#include "simple-timer.hpp"

enum NameTagStateId {
    bootup = 0,
    displayName = 1,
    alleycatLogo = 2,
    glitchOut = 3
};

class BootupState : public State {
    public:
    BootupState();
    ~BootupState();
    void onStateMounted(Device *device) override;

    void onStateLoop(Device *device) override;

    void onStateDismounted(Device *device) override;

    bool transitionToNameState();

private:
    SimpleTimer timer;
    bool transitionToName = false;
};

class NameState : public State {
public:
    NameState();
    ~NameState();
    void onStateMounted(Device *device) override;

    void onStateLoop(Device *device) override;

    void onStateDismounted(Device *device) override;

    bool transitionToAlleycatLogoState();

    bool transitionToGlitchOutState();

private:
    SimpleTimer timer;
    bool transitionToAlleycatLogo = false;
    bool transitionToGlitchOut = false;

};

class AlleycatLogoState : public State {
public:
    AlleycatLogoState();
    ~AlleycatLogoState();
    void onStateMounted(Device *device) override;

    void onStateLoop(Device *device) override;

    void onStateDismounted(Device *device) override;

    bool transitionToNameState();

private:
    SimpleTimer timer;
    bool transitionToName = false;
};

class GlitchOutState : public State {
public:
    GlitchOutState();
    ~GlitchOutState();
    void onStateMounted(Device *device) override;

    void onStateLoop(Device *device) override;

    void onStateDismounted(Device *device) override;

    bool transitionToNameState();

private:
    SimpleTimer timer;
    bool transitionToName = false;
};

