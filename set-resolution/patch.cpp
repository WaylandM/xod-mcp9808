
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_MCP9808` class instance
    auto sensor = getValue<input_DEV>(ctx);
    uint8_t resolution = getValue<input_RESOLUTION>(ctx);
    sensor -> setResolution(resolution);
    emitValue<output_DONE>(ctx, 1);
}
