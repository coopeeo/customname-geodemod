#include "utils.hpp"
#include <Geode/loader/Loader.hpp>

Utils* Utils::sharedutils = nullptr;

Utils* Utils::get() {
    if (sharedutils == nullptr) {
        sharedutils = new (std::nothrow) Utils();
    }

    return sharedutils;
}

Utils::dnInstalled() {return geode::Loader::get()->isModLoaded(displayNameModID);}
Utils::nameTransferred() {return geode::Loader::get()->isModLoaded(displayNameModID) && geode::Loader::get()->getLoadedMod(displayNameModID)->hasSavedValue("nametransferred");}
Utils::nameTransfered() {return geode::Loader::get()->isModLoaded(displayNameModID) && geode::Loader::get()->getLoadedMod(displayNameModID)->hasSavedValue("nametransferred");}

Utils::Utils() {
    gamelaunch = true;
    displayNameModID = "coopeeo.displaynames"
}