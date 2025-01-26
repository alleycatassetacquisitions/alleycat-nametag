#pragma once

#include <functional>
#include <set>
#include <vector>

#include "device.hpp"

class State;

//StateId is a simple wrapper in case we eventually need to add more data to identify a state.
struct StateId {
    explicit StateId(int stateid) {
        id = stateid;
    }

    int id;
};

/*
 * A State transition is a tuple that holds a condition as well as
 * the state which the condition, when valid, will be transitioned to.
 *
 *  condition: A function that returns a boolean signifying the state machine
 *  should transition to the new state.
 *
 *  nextState: A pointer to the next valid state.
 */
class StateTransition {
public:
    // Constructor
    StateTransition(std::function<bool()> condition, State *nextState)
        : condition(condition), nextState(nextState) {
    };

    // Method to check if the transition condition is met
    bool isConditionMet() const {
        return condition();
    }

    // Getter for the next state
    State *getNextState() const {
        return nextState;
    };

    std::function<bool()> condition; // Function pointer that returns true based on the global state
    State *nextState; // Pointer to the next state
};

/*
 * A state is meant to encapsulate a specific set of functionality within the context
 * of an application, ie quickdraw. States are broken up into a set of lifecycle methods.
 *
 * The process looks like this:
 *
 * onStateMounted: Invoked exactly one time the first time this state becomes
 * the "current" state in a state machine.
 *  - this method should include "setup" code for a state like starting timers,
 *  attaching callbacks to hardware, etc.
 *  - when mounting a new state is also when we register valid Serial messages for
 *  sending and receiving.
 *
 * onStateLoop: Invoked 1 to N times.
 * - this method is where the bulk of the functionality of a state occurs in.
 * - it is also where the conditions for state transitions will change and update.
 *
 * onStateDismounted: Invoked exactly 1 time, after any state transition condition
 * has been met.
 * - This method should be used for tearing down any long running logic and to reset
 * the conditions for state transitions - ie invalidating timers and resetting hardware
 * peripherals on the PDN.
 */
class State {
public:
    virtual ~State() {
        transitions.erase(transitions.begin(), transitions.end());
    };

    explicit State(int stateId): name(stateId) {
    }

    void addTransition(StateTransition *transition) {
        transitions.push_back(transition);
    };

    State *checkTransitions() {
        for (StateTransition *transition: transitions) {
            if (transition->isConditionMet()) {
                return transition->nextState;
            }
        }
        return nullptr;
    };

    int getStateId() const { return name.id; };

    virtual void onStateMounted(Device *device) {
    };

    virtual void onStateLoop(Device *device) {
    };

    virtual void onStateDismounted(Device *device) {
    };

    virtual bool isTerminalState() {
        return false;
    }

protected:
    std::vector<StateTransition *> transitions;

private:
    StateId name;
};
