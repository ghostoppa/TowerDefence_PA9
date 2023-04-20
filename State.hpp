#pragma once


	class State
	{
	public:
		virtual void Init() = 0;

		virtual void HandleInput() = 0;

		virtual void Update() = 0;

		//This makes sure that the state is consitant no matter the frame rate
		virtual void Draw() = 0;

		virtual void Pause() {}
		virtual void Resume() {}

	};
