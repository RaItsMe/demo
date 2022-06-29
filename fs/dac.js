let dacOn = ffi('void dac_ch1_enable(void)');
let dacSetVoltage = ffi('void dac_ch1_voltage(int)');
let dac = {
    pin: 25,
    vdd: 3.3,
    value: 0.0,
    on: function () {
        dacOn();
    },
    set: function (x) {
        this.value = x;
        dacSetVoltage((x * 255) / this.vdd);
    }
};