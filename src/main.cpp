#include "Geode/binding/FLAlertLayer.hpp"
#include "Geode/binding/GameLevelManager.hpp"
#include "Geode/binding/LevelInfoLayer.hpp"
#include "Geode/binding/MenuGameLayer.hpp"
#include "Geode/loader/Log.hpp"
#include "Geode/modify/Modify.hpp" 
#include "Geode/ui/BasedButtonSprite.hpp"
#include "Geode/ui/Popup.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <cmath>

using namespace geode::prelude;

class $modify(MyLevelInfoLayer, LevelInfoLayer){
	$override
	bool init(GJGameLevel *level, bool challenge){
		if (!LevelInfoLayer::init(level, challenge)) return false;


		auto buttonSprite = CircleButtonSprite::createWithSprite("PAS.png"_spr, 1.0f,CircleBaseColor::DarkPurple,CircleBaseSize::Medium);
		buttonSprite->getTopNode()->setScale(1.0f);
		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
			this,
			menu_selector(MyLevelInfoLayer::onMyButton)
		);
		myButton->setID("pas-button"_spr);

		auto leftSideMenu = this->getChildByID("left-side-menu");
		leftSideMenu->addChild(myButton);
		leftSideMenu->updateLayout();


		return true;
	}

	void onMyButton (CCObject*){
		geode::createQuickPopup(
			"PAS confirmation",
			"Are you sure?",
			"Cancel",
			"OK",
			[](FLAlertLayer* layer, bool selected) -> void {
				log::info("Selected {}", selected);
			}
		);
	}
}; 

