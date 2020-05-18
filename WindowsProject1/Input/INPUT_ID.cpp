#include <type_traits>
#include<WindowsProject1/Input/INPUT_ID.h>


INPUT_ID begin(INPUT_ID)
{
	return INPUT_ID::SPACE;
}

INPUT_ID end(INPUT_ID)
{
	return INPUT_ID::MAX;
}

INPUT_ID operator++(INPUT_ID& id)
{
	return id = INPUT_ID(std::underlying_type<INPUT_ID>::type(id) + 1);
}

INPUT_ID operator*(INPUT_ID id)
{
	return id;
}