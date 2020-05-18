#include<WindowsProject1/Input/InputState.h>

InputState::InputState()
{
	for (auto id : INPUT_ID())
	{
		state.try_emplace(id, KeyPair{ 0,1 });
	}
}

InputState::~InputState()
{
}

const KeyMap& InputState::State(void)
{
	return state;
}

const KeyPair InputState::State(INPUT_ID id) const
{
	try
	{
		return state.at(id);
	}
	catch (...)
	{
		AST();
	}
	return { 0, 0 };	// ‰Šú‰»Ø½Ä
}

bool InputState::State(INPUT_ID id, int data)
{
	if (state.find(id) != state.end())
	{
		state[id].first = data;
		return true;
	}
	return false;
}

void InputState::SetOld(void)
{
	for (auto id : INPUT_ID())
	{
		try
		{
			state[id].second = state[id].first;
		}
		catch (...)
		{
			AST();
			state.emplace(id, KeyPair{ 0,1 });
		}
	}
}
