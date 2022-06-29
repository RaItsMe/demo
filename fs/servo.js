let mServo = {
    min: 500,
    max: 2400,
    pin: 5,
    rangeDeg: 180,
    period_us: 20000,
    set: ffi('void hw_timer(int, int, int)'),
    setDeg: function (deg) {
        this.set(this.degToUs(deg, this.min, this.max, this.rangeDeg), this.period_us, this.pin);
    },
    degToUs: ffi('int deg_to_us(int, int, int, int)'),
}