#include <memory>
#include <WindowsProject1/common/Vector2.h>
#include <WindowsProject1/Scene/BaseScene.h>


#define SCREEN_X 800
#define SCREEN_Y 500

#define lpScene SceneMng::GetInstance()

class SceneMng
{
public:
	static SceneMng& GetInstance()	// �ݸ����
	{
		return (*s_Instance);
	}
	void Ran(void);

	Vector2 ScreenSize;	// ��ʻ���:800,500

private:
	struct SceneMngDelete
	{
		void operator()(SceneMng* sceneMng) const
		{
			delete sceneMng;
		}
	};
	SceneMng();
	~SceneMng();

	bool SysInit(void);		// ���я���

	static std::unique_ptr<SceneMng, SceneMngDelete> s_Instance;
	unique_Base activScene;		// Scene�ړ�����
};

