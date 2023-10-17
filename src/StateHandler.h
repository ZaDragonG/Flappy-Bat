#pragma once

#include "Virtual.h"

#include <memory>
#include <stack>

namespace FlappyBat
{
	typedef std::unique_ptr<Virtual> StateRef;

	class StateHandler
	{
	public:
		StateHandler() {}
		~StateHandler() {}

		void add_state(StateRef new_state, bool is_replacing = true);
		void remove_state();

		void state_change();

		StateRef &active_state();

	private:
		std::stack<StateRef> _states;
		StateRef newState;

		bool remover;
		bool addition, replacement;
	};
}