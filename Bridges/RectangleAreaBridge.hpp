#include <Bridges/IBridge.hpp>

class RectangleAreaBridge : public IBridge
{
public:
    boost::any perform(const InfoModel& inVal) override;
    virtual ~RectangleAreaBridge();
};