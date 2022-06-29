load('api_timer.js');
load('api_net.js');
load('api_events.js');
load('api_gpio.js');
load('api_mqtt.js');
load('api_sys.js');
load('api_pwm.js');
load('indicate.js');
load('dac.js');
load('servo.js');

dac.on();
dac.set(0);
indicate.set(0);
mServo.setDeg(0);

MQTT.sub('/sys', function (conn, topic, msg) {
  print('Topic:', topic, 'message:', msg);
  if ((msg === 'reboot')) { Sys.reboot(1000); }
  else {
    while (!MQTT.pub('/error', 'Topic: ' + topic + ',' + ' cmd: ' + ' "' + msg + '" ' + ' unknown')) { };
  }
}, null);

MQTT.sub('/led', function (conn, topic, msg) {
  print('Topic:', topic, 'message:', msg);
  dac.set(JSON.parse(msg));
}, null);

MQTT.sub('/servo', function (conn, topic, msg) {
  print('Topic:', topic, 'message:', msg);
  mServo.setDeg(JSON.parse(msg));
}, null);

MQTT.sub('/lcd', function (conn, topic, msg) {
  print('Topic:', topic, 'message:', msg);
  indicate.set(JSON.parse(msg));
}, null);

let id = Timer.set(1000, Timer.REPEAT, function () {
  if (MQTT.isConnected()) {
    MQTT.pub('/sys', '0');
    MQTT.pub('/servo', JSON.stringify(0));
    MQTT.pub('/led', JSON.stringify(0.0));
    MQTT.pub('/lcd', JSON.stringify(0));
    Timer.del(id);
  }
  else {
    indicate.set(100);
  }
}, null);

Timer.set(10000, Timer.REPEAT, function () {
  Sys.wdt_feed();
}, null);