#pragma once

#include <WPILib.h>

class Timeout_Command : public Command {
public:
	Timeout_Command(double timeout);
protected:
	bool is_timed_out();
	bool has_timed_out();
	bool timed_out;
	double timeout;
};
