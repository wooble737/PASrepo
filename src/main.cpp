#include "Geode/binding/CCMenuItemSpriteExtra.hpp"
#include "Geode/binding/FLAlertLayer.hpp"
#include "Geode/binding/GameLevelManager.hpp"
#include "Geode/binding/LevelInfoLayer.hpp"
#include "Geode/binding/MenuGameLayer.hpp"
#include "Geode/cocos/sprite_nodes/CCSprite.h"
#include "Geode/loader/Log.hpp"
#include "Geode/modify/Modify.hpp" 
#include "Geode/ui/BasedButtonSprite.hpp"
#include "Geode/ui/Popup.hpp"
#include "ccTypes.h"
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <cmath>
#include <cstddef>
#include <windef.h>
#include <winuser.h>

using namespace geode::prelude;

class $modify(MyLevelInfoLayer, LevelInfoLayer){

	//struct Fields{
	//	ccColor3B m_backgroundColor;
	//};
	$override
	bool init(GJGameLevel *level, bool challenge){
		if (!LevelInfoLayer::init(level, challenge)) return false;

		auto buttonSprite = ButtonSprite::create("PAS");
		auto myButton = CCMenuItemSpriteExtra::create(
			buttonSprite,
			this,
			menu_selector(MyLevelInfoLayer::onMyButton)
		);
		myButton->setID("pas-button"_spr);

		auto leftSideMenu = getChildByID("left-side-menu");
		leftSideMenu->addChild(myButton);
		leftSideMenu->updateLayout();

		// auto levelIdVariable = GameLevelManager::get()->getSavedLevel(m_level);
		// if (!levelIdVariable) return true;
		// m_playBtnMenu-> getChildByID("play-menu")
		// ->getChildByID("play-button")
		// ->getChildByType<CCSprite>(0);
		// return true;                        THIS IS THE GARBAGE THAT I WAS TRYING TO DO BY MYSELF TO JUST TRIGGER THE PLAYBUTTON
		return true;
	}


	void onMyButton (CCObject*){
		geode::createQuickPopup(
			"PAS",
			"Start the Calculation?",
			"Cancel",
			"OK",
			[](FLAlertLayer* layer, bool selected) -> void {
				log::info("Selected {}", selected);
				PlayLayer::get()->togglePracticeMode(true); //Just got this in, but this gets the thing inside of PlayLayer, while I am modifiying LevelInfoLayer
			}
		);
	}
}; 

