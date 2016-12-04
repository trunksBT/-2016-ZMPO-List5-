#pragma once

#include <map>
#include <string>
#include <Bridges/IBridge.hpp>

class BridgesModel
{
private:
    std::map<std::string, IBridge*> bridgesMap_;

public:
    BridgesModel();
    explicit BridgesModel(const BridgesModel& inVal);
    BridgesModel(const std::map<std::string, IBridge*>& inMap);
    ~BridgesModel();

    int size();
    void removeKey(const char* inKey);
    bool contains(const char* inKey);
    void update(const char* inKey, IBridge* inValue);
    IBridge& fetch(const char* inKey);
};