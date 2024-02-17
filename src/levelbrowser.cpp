#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include <Geode/binding/LevelBrowserLayer.hpp>

using namespace geode::prelude;

class $modify(LevelBrowserLayer) {
    /*static void onModify(auto& self) {
        self.setHookPriority("LevelBrowserLayer::updateLevelsLabel", -2);
    }*/

    void updateLevelsLabel() {
		//if(!LevelBrowserLayer::init(p0))
			//return false;
        LevelBrowserLayer::updateLevelsLabel();
        log::debug("loaded!!!!!!!!!!!!!!!!!!!!!");
        
        // auto theContent = p0;
        auto theContent3 = static_cast<GJListLayer*>(this->m_list);
        auto theContent = static_cast<CustomListView*>(theContent3->getChildren()->objectAtIndex(0));
        //auto theContent = theContent2->getChildren()->objectAtIndex(0);
        //auto theContent = static_cast<cocos2d::CCNode*>(theContent1->getChildren()->objectAtIndex(0));
        auto theContentChildren = theContent->getChildren();
        log::debug("gonna do some shit {} times",theContent->getChildrenCount());
        for (size_t i = 0; i < theContent->getChildrenCount(); i++)
        {
            //std::string ee(i);
            log::debug("did it ({})",i);
            auto mainObj = static_cast<CCNode*>(theContentChildren->objectAtIndex(i))->getChildByID("main-layer");

            auto creatorname = mainObj->getChildByID("main-menu")->getChildByID("creator-name");
            if (creatorname != nullptr) {
                auto obj = static_cast<cocos2d::CCLabelBMFont*>(creatorname->getChildren()->objectAtIndex(0));
                std::string objString(obj->getString());
                auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);

                if(static_cast<std::string>(GJAccountManager::get()->m_username) == objString.substr(3,-1)){
                    auto value = Mod::get()->getSettingValue<std::string>("thename");

                    obj->setString(fmt::format("By {}", value).c_str());
                }

            }
            
        }
        //return true;
	}
};