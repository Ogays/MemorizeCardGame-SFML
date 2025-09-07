#pragma once
/*
 * File:   StateMachine.hpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */


#include <memory>
#include <stack>

#include "State.hpp"

namespace Ogay {
    
//    typedef std::unique_ptr<State> StateRef;
    
    class StateMachine {
    public:
        StateMachine() {}
        ~StateMachine() {}
        
        void AddState( std::unique_ptr<State> newState, bool isReplacing = true );
        void RemoveState( );
        void ProcessStateChanges();
        
        std::unique_ptr<State> &GetActiveState();
        
    private:
        std::unique_ptr<State> _newState;
        std::stack<std::unique_ptr<State>> _states;
        
        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
    };
}