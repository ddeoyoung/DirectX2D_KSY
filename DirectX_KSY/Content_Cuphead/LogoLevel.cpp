#include "PreCompile.h"
#include "LogoLevel.h"

LogoLevel::LogoLevel()
{

}

LogoLevel::~LogoLevel()
{

}

void LogoLevel::Start()
{
	GetMainCamera()->Transform.SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

}

void LogoLevel::Update(float _Delta)
{

}

void LogoLevel::LevelStart(GameEngineLevel* _PrevLevel)
{

}

void LogoLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}