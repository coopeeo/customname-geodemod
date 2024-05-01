#pragma once

class Utils final {
private:
    bool gamelaunch;
    const std::string displayNameModID;
    static Utils* sharedutils;
public:
    Utils();

    static Utils* get();

    bool const& getLaunch() const {return gamelaunch;}
    void afterLaunch() {gamelaunch = false;}
    bool const& dnInstalled() const;
    bool const& nameTransferred() const;
    bool const& nameTransfered() const;
};