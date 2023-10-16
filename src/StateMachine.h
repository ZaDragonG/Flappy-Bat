#pragma once

#include "State.h"

#include <memory>
#include <stack>

namespace FlappyBat
{
	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public:
		StateMachine() {}
		~StateMachine() {}

		void add_state(StateRef new_state, bool is_replacing = true);
		void remove_state();
		// Run at start of each loop in Game.cpp
		void state_change();

		StateRef &active_state();

	private:
		std::stack<StateRef> _states;
		StateRef newState;

		bool remover;
		bool addition, replacement;
	};
}