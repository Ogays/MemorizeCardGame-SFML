#pragma once
/*
 * File:   State.hpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */

namespace Ogay {
    
    class State {
    public:
        virtual void Init() = 0;
        
        virtual void HandleInput() = 0;
        virtual void Update( float dt ) = 0;
        virtual void Draw(float dt) = 0;
        
        virtual void Pause() {}
        virtual void Resume() {}
    };
}