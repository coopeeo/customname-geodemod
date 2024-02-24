#include <Geode/loader/Loader.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/binding/ProfilePage.hpp>

using namespace geode::prelude;

class $modify(ProfilePage) {
    static void onModify(auto& self) {
        self.setHookPriority("ProfilePage::loadPageFromUserInfo", -1);
    }

    // Non-BetterInfo way
    bool init(int accountID, bool ownProfile) {
        if (!ProfilePage::init(accountID, ownProfile)) return false;
        log::debug("loadPageFromUserInfo() function called! Running Custom Name!");

        auto isOwnProfile = ownProfile||(GJAccountManager::get()->m_username.c_str() == m_usernameLabel->getString());

        log::debug("Users Own Profile: {}", isOwnProfile);

        if (isOwnProfile && !Loader::get()->isModLoaded("cvolton.betterinfo"))
        {
            auto value = Mod::get()->getSettingValue<std::string>("thename");
            m_usernameLabel->setString(value.c_str());
        }

        return true;
    }
    
    // BetterInfo way
    void loadPageFromUserInfo(GJUserScore* user) {
        ProfilePage::loadPageFromUserInfo(user);
        log::debug("loadPageFromUserInfo() function called! Running Custom Name! (this gets called multiple times)");

        auto isOwnProfile = m_ownProfile||(GJAccountManager::get()->m_username.c_str() == m_usernameLabel->getString());

        log::debug("Users Own Profile: {}", isOwnProfile);

		auto value = Mod::get()->getSettingValue<std::string>("thename");
		if (Loader::get()->isModLoaded("cvolton.betterinfo") && isOwnProfile) {
			static_cast<cocos2d::CCLabelBMFont*>(this->getChildByIDRecursive("main-menu")->getChildByID("cvolton.betterinfo/username-button")->getChildren()->objectAtIndex(0))->setString(value.c_str());
		};
    };
};
