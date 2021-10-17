#pragma once
#ifndef __BRAIN_HPP
# define __BRAIN_HPP

#include <iostream>
#include <string.h>

class Brain {
	public:
		Brain(const std::string & brainHandler);
		Brain(const Brain &r);
		Brain operator = (const Brain &r);
		virtual ~Brain();
    
        void  checkInitIdea();
        std::string ideas[100];


    private: 
		Brain();
};

#endif // __BRAIN_HPP
