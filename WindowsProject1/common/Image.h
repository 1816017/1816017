#pragma once
#include <map>
#include <vector>
#include <string>
#include <WindowsProject1/common/Vector2.h>

#define IMAGE_ID(KEY) (Image::GetInstance().GetID(KEY))
#define SET_IMAGE_ID(KEY, FILENAME) (Image::GetInstance().GetID(KEY, FILENAME))
#define lpImage Image::GetInstance()

using VecInt = std::vector<int>;	// è»ó™

class Image
{
public:
	static Image& GetInstance()
	{
		if (s_Instans == nullptr)
		{
			s_Instans = new Image();
		}
		return (*s_Instans);
	}
	~Image();
	const VecInt& GetID(const std::string& key);		// IDÇìnÇ∑
	const VecInt& GetID(const std::string& key, const std::string& fileName);
	const VecInt& GetID(const std::string& key, const std::string& fileName,
		const Vector2& divcnt, const Vector2& divsize);
private:
	Image();		// º›∏ﬁŸƒ›
	std::map<std::string, VecInt> imageMap;
	static Image* s_Instans;
};