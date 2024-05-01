#pragma once

class Utils final {
private:
    bool gamelaunch;
    const std::string displayNameModID;
    static Utils* sharedutils;
public:
    Utils();
    Utils() {};

    static Utils* get();

    bool const& getLaunch() const {return gamelaunch;}
    void const& afterLaunch() {gamelaunch = false;}
    bool const& dnInstalled() const;
    bool const& nameTransferred() const;
};