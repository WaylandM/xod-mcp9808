// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/Adafruit_MCP9808_Library"

//Include C++ libraries
{{#global}}
#include <Adafruit_MCP9808.h>
{{/global}}

// Reserve memory to store an instance of the Adafruit_MCP9808 class,
// and create the instance later:
struct State {
    uint8_t mem[sizeof(Adafruit_MCP9808)];
};

// Define our custom type as a pointer on the class instance.
using Type = Adafruit_MCP9808*;


{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);
    uint8_t address = getValue<input_ADDRESS>(ctx);
    uint8_t resolution = getValue<input_RESOLUTION>(ctx);

    // Create a new object in the memory area reserved previously.
    Type sensor = new (state->mem) Adafruit_MCP9808();

    if (!sensor->begin(address)) {
      raiseError(ctx);
      return;
    }

    sensor->setResolution(resolution);

    emitValue<output_DEV>(ctx, sensor);

}
