#include <Geode/loader/Loader.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/binding/ProfilePage.hpp>
#include <Geode/binding/GJAccountManager.hpp>

using namespace geode::prelude;

class $modify(ProfilePage) {
    bool init(int accountID, bool ownProfile) {
        if (!ProfilePage::init(accountID, ownProfile)) return false;

        auto isOwnProfile = (ownProfile || (GJAccountManager::get()->m_username.c_str() == m_usernameLabel->getString()));

        log::info("Custom Name Profile Page: GJ Account Name is \"{}\". The Label Name is \"{}\". m_ownProfile/ownprofile is \"{}\". Combined ownprofile is \"{}\"", GJAccountManager::get()->m_username, m_usernameLabel->getString(), ownProfile, isOwnProfile);

        if (isOwnProfile) {
            auto value = Mod::get()->getSettingValue<std::string>("thename");
            m_usernameLabel->setString(value.c_str());
        }

        return true;
    }

    void loadPageFromUserInfo(GJUserScore* user) {
        ProfilePage::loadPageFromUserInfo(user);

        auto isOwnProfile = (m_ownProfile || (fmt::format("{}", GJAccountManager::get()->m_username.c_str()) == fmt::format("{}", m_usernameLabel->getString())));
        
        log::info("Custom Name Profile Page: GJ Account Name is \"{}\". The Label Name is \"{}\". m_ownProfile/ownprofile is \"{}\". Combined ownprofile is \"{}\"", GJAccountManager::get()->m_username, m_usernameLabel->getString(), m_ownProfile, isOwnProfile);

        if (isOwnProfile) {
            auto value = Mod::get()->getSettingValue<std::string>("thename");
            m_usernameLabel->setString(value.c_str());
        }
    };
};
