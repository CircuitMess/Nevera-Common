#ifndef COMMDATA_H
#define COMMDATA_H

#include <Object/Object.h>

static constexpr const char* ControllerIP = "11.0.0.1";
static constexpr const char* VehicleIP = "11.0.0.2";
static constexpr const uint16_t UDPPort = 6001;
static constexpr const uint16_t TCPPort = 6000;

/**
 * 	Direction encoding:
 * 	0 - forward, -1 - left, 1 - right
 *
 *
 * 	Boost encoding:
 * 	max: 3, min: -3
 * 	0 - no movement
 */

class CommData : public Object {
    GENERATED_BODY(CommData, Object)

public:
    enum class DataType : uint8_t {
        None,
        Speed,
        Direction,
        Battery,
		NoFeed,
        Connection
    };

    DataType dataType = DataType::None;
    float value = 0.0f;

    virtual Archive& serialize(Archive& archive) noexcept override {
        Super::serialize(archive);

        uint8_t type =  static_cast<uint8_t>(dataType);

        archive << type;
        archive << value;

        dataType = static_cast<DataType>(type);

        return archive;
    }
};

#endif //COMMDATA_H
