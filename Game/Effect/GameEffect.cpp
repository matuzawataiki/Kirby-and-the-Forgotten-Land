#include "stdafx.h"
#include "GameEffect.h"
namespace nsApp {

	nsApp::nsEffect::GameEffect::GameEffect()
	{
	}

	nsApp::nsEffect::GameEffect::~GameEffect()
	{
	}

	bool nsApp::nsEffect::GameEffect::Start()
	{
		EffectEngine::GetInstance()->ResistEffect(0, u"Assets/effect/block/LossOfBlood.efkproj");
		return true;
	}
}