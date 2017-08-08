#include <Bridges/BridgesModel.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace defaultVals;
using namespace flags;
using namespace typeLiterals;

class FetchException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "BridgeModel does not contain this key";
    }
} fetchException;

BridgesModel::BridgesModel()
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << BRIDGES_MODEL
            << POST_PRINT;
    }
}

BridgesModel::BridgesModel(const BridgesModel& inVal)
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_COPY_PRE_PRINT
            << BRIDGES_MODEL
            << POST_PRINT;
    }

    for (auto it = inVal.bridgesMap_.begin(); it != inVal.bridgesMap_.end(); ++it)
    {
        bridgesMap_[it->first] = it->second->clone();
    }
}

BridgesModel::BridgesModel(const std::map<std::string, IBridge*>& inMap)
    :bridgesMap_(inMap)
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_ARG1_PRE_PRINT
            << BRIDGES_MODEL
            << POST_PRINT;
    }
}

bool BridgesModel::contains(const char* inKey)
{
    return bridgesMap_.count(inKey) != 0;
}

void BridgesModel::update(const char* inKey, IBridge* inValue)
{
    if (contains(inKey))
    {
        bridgesMap_.emplace(
            std::piecewise_construct,
            std::forward_as_tuple(inKey),
            std::forward_as_tuple(inValue) );
    }
    else
    {
        removeKey(inKey);

        bridgesMap_.emplace(
            std::piecewise_construct,
            std::forward_as_tuple(inKey),
            std::forward_as_tuple(inValue));
    }
}

void BridgesModel::removeKey(const char* inKey)
{
    if (contains(inKey))
    {
        auto pairToRemove = bridgesMap_.find(inKey);
        if (pairToRemove != bridgesMap_.end())
        {
            delete pairToRemove->second;
            bridgesMap_.erase(inKey);
        }
    }
}

int BridgesModel::size()
{
    return bridgesMap_.size();
}

IBridge& BridgesModel::fetch(const char* inKey)
{
    if (contains(inKey))
    {
        return *bridgesMap_[inKey];
    }
    else
    {
        throw fetchException;
    }
}

BridgesModel::~BridgesModel()
{
    for (auto it = bridgesMap_.begin(); it != bridgesMap_.end(); ++it)
    {
        delete it->second;
    }

    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << BRIDGES_MODEL
            << POST_PRINT;
    }
}
