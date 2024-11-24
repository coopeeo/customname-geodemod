#include <Geode/Geode.hpp>
#include <Geode/modify/CommentCell.hpp>
#include <Geode/binding/CommentCell.hpp>

using namespace geode::prelude;

class $modify(CommentCell) {
    void loadFromComment(GJComment* p0) {
        CommentCell::loadFromComment(p0);
        
        auto mainObj = static_cast<cocos2d::CCLayer*>(this->getChildren()->objectAtIndex(1));
        if (mainObj == nullptr) {log::info("Failed to move on because \"the CCLayer in CommentCell (index 1)\" doesnt exist CommentCell"); return;}
        auto profilename = static_cast<CCLabelBMFont*>(mainObj->getChildByID("username-label"));
        // if is profile comment
        if (profilename != nullptr) {
            std::string objString(profilename->getString());
            auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);
            if(accountname == objString){
                auto value = Mod::get()->getSettingValue<std::string>("thename");

                profilename->setString(value.c_str());
            }
            return;
        }
        
        // Continue not a profile comment
        auto menuStuff = mainObj->getChildByID("main-menu");
        if (menuStuff == nullptr) {log::info("Failed to move on because \"main-menu\" doesn't exist in \"the CCLayer in CommentCell (index 1)\" -> CommentCell"); return;}
        auto userMenu = menuStuff->getChildByID("user-menu");
        if (userMenu == nullptr) {log::info("Failed to move on because \"user-menu\" doesn't exist in \"main-menu\" -> \"the CCLayer in CommentCell (index 1)\" -> CommentCell"); return;}
        auto usernameMenu = userMenu->getChildByID("username-menu");
        if (usernameMenu == nullptr) {log::info("Failed to move on because \"username-menu\" doesn't exist in \"user-menu\" -> \"main-menu\" -> \"the CCLayer in CommentCell (index 1)\" -> CommentCell"); return;}
        auto creatorname = usernameMenu->getChildByID("username-button");
        if (creatorname == nullptr) {log::info("Failed to move on because \"username-button\" doesn't exist in \"username-menu\" -> \"user-menu\" -> \"main-menu\" -> \"the CCLayer in CommentCell (index 1)\" -> CommentCell"); return;}
        

        auto obj = static_cast<cocos2d::CCLabelBMFont*>(creatorname->getChildren()->objectAtIndex(0));
        std::string objString(obj->getString());
        auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);
        if(static_cast<std::string>(GJAccountManager::get()->m_username) == objString){
            auto value = Mod::get()->getSettingValue<std::string>("thename");

            obj->setString(value.c_str());
        }
	}
};