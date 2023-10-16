#include "StateMachine.h"

namespace Sonar
{
	void StateMachine::add_state(StateRef new_state, bool is_replacing)
	{
		this->addition = true;
		this->replacement = is_replacing;

		this->newState = std::move(new_state);
	}

	void StateMachine::remove_state()
	{
		this->remover = true;
	}

	void StateMachine::state_change()
	{
		if (this->remover && !this->_states.empty())
		{
			this->_states.pop();

			if (!this->_states.empty())
			{
				this->_states.top()->resume();
			}

			this->remover = false;
		}

		if (this->addition)
		{
			if (!this->_states.empty())
			{
				if (this->replacement)
				{
					this->_states.pop();
				}
				else
				{
					this->_states.top()->pause();
				}
			}

			this->_states.push(std::move(this->newState));
			this->_states.top()->Init();
			this->addition = false;
		}
	}

	StateRef &StateMachine::active_state()
	{
		return this->_states.top();
	}
}