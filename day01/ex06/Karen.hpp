#pragma once
#ifndef __KAREN_HPP
# define __KAREN_HPP

#include <string>

class Karen {
	public:
		static const std::string ldebug;
		static const std::string linfo;
		static const std::string lwarn;
		static const std::string lerr;


		Karen();
		~Karen();
		
		void complain(std::string level);

	private:
		static void (Karen::*memf[4])(void);
		static const std::string *levels[4];

		void _debug();
		void _info();
		void _warning();
		void _error();

};


#endif 
