#include <DxLib.h>
#include <WindowsProject1/common/Image.h>

Image* Image::s_Instans = nullptr;

Image::Image()
{
}

Image::~Image()
{
}

const VecInt& Image::GetID(const std::string& key)
{
	GetID(key, key, { 10,10 }, { 600,300 });
	return imageMap[key];
}

const VecInt& Image::GetID(const std::string& key, const std::string& fileName)
{
	if (imageMap.find(key) == imageMap.end())
	{
		imageMap[key].resize(1);
		imageMap[key][0] = LoadGraph(fileName.c_str());
	}
	return imageMap[key];
}

const VecInt& Image::GetID(const std::string& key, const std::string& fileName, const Vector2& divcnt, const Vector2& divsize)
{
	if (imageMap.find(key) == imageMap.end())
	{
		imageMap[key].resize(divcnt.x * divcnt.y);
		LoadDivGraph(fileName.c_str(), divcnt.x * divcnt.y,
			divcnt.x, divcnt.y, divsize.x, divsize.y, &imageMap[key][0]);
	}
	return imageMap[key];
}