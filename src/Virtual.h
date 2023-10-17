#pragma once

namespace FlappyBat
{
	class State
	{
	public:
		virtual void Init() = 0;

		virtual void input_handle() = 0;
		virtual void Refresh(float dt) = 0;
		virtual void Render(float dt) = 0;

		virtual void pause() {}
		virtual void resume() {}
	};
}