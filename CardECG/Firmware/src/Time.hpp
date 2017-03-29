/*
 * This file is part of MobilECG, an open source clinical grade Holter
 * ECG. For more information visit http://mobilecg.hu
 *
 * Copyright (C) 2016  Robert Csordas, Peter Isza
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _TIME_HPP_
#define _TIME_HPP_

#include <stdint.h>

namespace Time{
    typedef uint32_t time_t;
    const time_t MS_PER_TICK=10;
    extern volatile time_t currTime;

    inline time_t now(){
        return currTime;
    }

    inline time_t startTimer(){
        return now();
    }

    inline bool msPassed(time_t timer, time_t ms){
        return currTime > (timer + ((MS_PER_TICK-1+ms)/MS_PER_TICK));
    }

    inline time_t msSince(time_t time){
        return (currTime - (time))*MS_PER_TICK;
    }

    
    inline void clockInit(){
        currTime=0;
    }
}

#endif
