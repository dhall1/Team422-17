#include "timeout_command.hpp"

Timeout_Command::Timeout_Command(double seconds) : timed_out (false), timeout (seconds) {

}

bool Timeout_Command::is_timed_out() {
	timed_out = TimeSinceInitialized() > timeout;
	return timed_out;
}

bool Timeout_Command::has_timed_out() {
	return timed_out;
}
