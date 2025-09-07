/*
 * File:   StateMachine.cpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */

#include "../include/StateMachine.hpp"
#include "../include/State.hpp"

namespace Ogay {

    void StateMachine::AddState(std::unique_ptr<State> newState, bool isReplacing) {
        this->_isAdding = true;
        this->_isReplacing = isReplacing;

        this->_newState = std::move(newState);
    }

    void StateMachine::RemoveState() {
        this->_isRemoving = true;
    }

    void StateMachine::ProcessStateChanges() {
        if (this->_isRemoving && !this->_states.empty()) {
            this->_states.pop();
            if (!this->_states.empty()) {
                this->_states.top()->Resume();
            }
            this->_isRemoving = false;
        }

        if (this->_isAdding) {
            if (!this->_states.empty()) {
                if (this->_isReplacing) {
                    this->_states.pop();
                } else {
                    this->_states.top()->Pause();
                }
            }
            this->_states.push(std::move(this->_newState));
            this->_states.top()->Init();
            this->_isAdding = false;
        }
    }

    std::unique_ptr<State> &StateMachine::GetActiveState() {
        return this->_states.top();
    }
}