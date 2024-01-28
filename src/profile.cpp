#include <Geode/loader/Loader.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/binding/ProfilePage.hpp>

static geode::Loader* get();

using namespace geode::prelude;

class $modify(ProfilePage) {
	static void onModify(auto& self) {
        if (Loader::get()->isModLoaded("cvolton.betterinfo")) {
			self.setHookPriority("ProfilePage::init", -1); // try to fix with BetterInfo
    	}
	}

	 bool init(int accountID, bool ownProfile) {
        if (!ProfilePage::init(accountID, ownProfile)) return false;

		if (ownProfile)
		{
			auto value = Mod::get()->getSettingValue<std::string>("thename");
    		m_usernameLabel->setString(value.c_str());
			if (Loader::get()->isModLoaded("cvolton.betterinfo")) {
				static_cast<cocos2d::CCLabelBMFont*>(this->getChildByID("cvolton.betterinfo/username-button")->getChildren()->objectAtIndex(1))->setString(value.c_str()); //honestly i have no clue lol
			}
		}
		
		return true;
	}
};