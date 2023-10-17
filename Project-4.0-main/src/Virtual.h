#pragma once

namespace FlappyBat
{
	class Virtual
	{
	public:
		virtual void SetGameElements() = 0;

		virtual void input_handle() = 0;
		virtual void Refresh(float dt) = 0;
		virtual void Render(float dt) = 0;

		virtual void pause() {}
		virtual void resume() {}
	};
}