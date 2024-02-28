#include <Geode/Geode.hpp>
#include <Geode/modify/CommentCell.hpp>
#include <Geode/binding/CommentCell.hpp>

using namespace geode::prelude;

class $modify(CommentCell) {
    /*static void onModify(auto& self) {
        self.setHookPriority("LevelBrowserLayer::updateLevelsLabel", -2);
    }*/

    void loadFromComment(GJComment* p0) {
        CommentCell::loadFromComment(p0);
        log::debug("loadFromComment() function called! Running Custom Name!");
        
        
        auto mainObj = static_cast<cocos2d::CCLayer*>(this->getChildren()->objectAtIndex(1));
        if (mainObj == nullptr) {log::info("Failed to move on because \"the CCLayer in CommentCell (index 1)\" doesnt exist CommentCell"); return;}
        auto menuStuff = mainObj->getChildByID("main-menu");
        if (menuStuff == nullptr) {log::info("Failed to move on because \"main-menu\" doesnt exist in \"the CCLayer in CommentCell (index 1)\" -> CommentCell"); return;}
        auto creatorname = menuStuff->getChildByID("username-button");
        if (creatorname == nullptr) {log::info("Failed to move on because \"username-button\" doesnt exist in \"main-menu\" -> \"the CCLayer in CommentCell (index 1)\" -> CommentCell"); return;}
        else {
            auto obj = static_cast<cocos2d::CCLabelBMFont*>(creatorname->getChildren()->objectAtIndex(0));
            std::string objString(obj->getString());
            auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);
            if(static_cast<std::string>(GJAccountManager::get()->m_username) == objString){
                auto value = Mod::get()->getSettingValue<std::string>("thename");

                obj->setString(value.c_str());
            }
        }
	}
};