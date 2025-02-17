#ifndef COMMDATA_H
#define COMMDATA_H

#include <Object/Object.h>

class CommData : public Object {
    GENERATED_BODY(CommData, Object)

public:
    enum class DataType : uint8_t {
        None,
        Speed,
        Direction,
        Battery
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
