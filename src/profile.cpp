#include <Geode/loader/Loader.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/binding/ProfilePage.hpp>

using namespace geode::prelude;

class $modify(ProfilePage) {
    // TODO: add non betterinfo way back later
    void loadPageFromUserInfo(GJUserScore* user) {
		ProfilePage::loadPageFromUserInfo(user);

		auto value = Mod::get()->getSettingValue<std::string>("thename");
		if (Loader::get()->isModLoaded("cvolton.betterinfo")) {
			static_cast<cocos2d::CCLabelBMFont*>(this->getChildByIDRecursive("cvolton.betterinfo/username-button")->getChildren()->objectAtIndex(0))->setString(value.c_str());
		};
    };
};