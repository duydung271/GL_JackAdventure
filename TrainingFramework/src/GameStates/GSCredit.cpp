#include "GSCredit.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSCredit::GSCredit()
{

}
GSCredit::~GSCredit()
{

}

void GSCredit::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Background");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);


	//Logo
	texture = ResourceManagers::GetInstance()->GetTexture("avatar");
	std::shared_ptr<Sprite2D> Image = std::make_shared<Sprite2D>(model, shader, texture);
	Image->Set2DPosition(screenWidth / 2, screenHeight / 2 - 100);
	Image->SetSize(100, 100);
	m_listImage.push_back(Image);

	//Logo2
	texture = ResourceManagers::GetInstance()->GetTexture("logo");
	Image = std::make_shared<Sprite2D>(model, shader, texture);
	Image->Set2DPosition(screenWidth / 2, screenHeight / 2 );
	Image->SetSize(300, 100);
	m_listImage.push_back(Image);

	//back button
	texture = ResourceManagers::GetInstance()->GetTexture("button_back");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	//FB
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Planes_ValMore");
	m_Text_FB_Author = std::make_shared< Text>(shader, font, "fb.com/proptit.ddung", TEXT_COLOR::BLACK, 1.0);
	m_Text_FB_Author->Set2DPosition(Vector2(screenWidth / 2, screenHeight / 2+200));
}
void GSCredit::Exit()
{

}

void GSCredit::Pause()
{

}
void GSCredit::Resume()
{

}

void GSCredit::HandleEvents()
{

}
void GSCredit::HandleKeyEvents(int key, bool bIsPressed)
{

}
void GSCredit::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle())
		{
			Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_Click));
			break;
		}
			
	}
	
}

void GSCredit::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}
void GSCredit::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listImage)
	{
		it->Draw();
	}
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_Text_FB_Author->Draw();
}