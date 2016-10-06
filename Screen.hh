#ifndef Screen_hh
#define Screen_hh

class Screen
{
	public:
		Screen(unsigned screenSize_); //Constructor

		void clear_screen();

		Screen(const Screen &given); //Copy constructor to create own copy

		void print_screen();

		~Screen();

		void put(int particlePosition_, char particleSymbol_);

		char & operator[](unsigned const particlePosition_);

		Screen& operator=(Screen given);

		friend void swap(Screen& lhs, Screen& rhs);

	private:
		char * screen; 	
		unsigned screenSize;
};

#endif
