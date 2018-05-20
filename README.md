![L12-R](images/L12-R-256.png "L12-R")

# arduino-lock
:satellite::unlock: Remote Controlled Security

This project was inspired by the [Replica Prop Forum thread by JohnnyNeutron](https://www.therpf.com/showthread.php?t=245997)
which in turn was inspired by [*The Amazing Spider-Man 2* (2014)](https://www.imdb.com/title/tt1872181/)
feature film, and consists of a simple Arduino [C++ software](https://github.com/trending/c++)
script and a step-by-step guide on how to create the prop replica using
[Arduino Uno hardware](https://www.arduino.cc/) and other assorted tools.

_**Disclaimer:** This is just a **hobby** project and provides absolutely no
guarantee of security or warranty of any kind. Use at your own risk!!!_

### Table of Contents
- [Features](#features)
  - [Upcoming](#upcoming)
- [Requirements](#requirements)
  - [Software](#software)
  - [Tools](#tools)
  - [Hardware](#hardware)
- [Installation](#installation)
- [Configuration](#configuration)
- [Usage](#usage)
- [Example](#example)
  - [L12-R](#l12-r)
  - [ProtonRev2](#protonrev2)
- [Resources](#resources)
- [Development](#development)
  - [Future](#future)
  - [History](#history)
- [Credits](#credits)
- [License](#license)

## Features
- 315MHz Receiver/Transmitter Support
- L12-R Micro Linear Servo Support
- SG92R Micro Servo Support

### Upcoming
- Prop Replica Step-By-Step Guide
- Spektrum AR500 Receiver Support
- Spektrum DX5e Transmitter Support

## Requirements

### Software
- [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- [Git](https://git-scm.com/downloads)

### Tools
- Power Drill and Drill/Driver Bits
- Rotary Tool, Cut-Off Wheels, and Sanding Drums
- Hot Glue Gun and Glue Sticks
- Soldering Iron and Solder (Recommended)

### Hardware
- [U 9997 Keyed Bolt Lock](https://duckduckgo.com/?q=U+9997+Keyed+Bolt+Lock)
- [315MHz RF Momentary Receiver](https://www.adafruit.com/products/1096)
- [315MHz RF Keyfob Transmitter](https://www.adafruit.com/products/1095)
- [Connecting Arm 3D Printer STL](https://www.thingiverse.com/download:1661462)
- Linear Servo Kit
  1. [L12-R Micro Linear Servo](https://www.actuonix.com/L12-R-Linear-Servo-For-Radio-Control-p/l12-r.htm)
  2. [ProtonRev2 Linear Servo Extender](https://github.com/tscha70/3DPrinterSTLFiles/tree/master/Proton%20Rev%202%20-%20Easter%20Edition) for [SG92R Micro Servo](https://duckduckgo.com/?q=SG92R+Micro+Servo)
- [Arduino Uno Rev3 Micro controller](https://duckduckgo.com/?q=Arduino+Uno)
- Arduino Uno Power Adapter
- 170 Points Breadboard
- 4 3/4" x 4 3/4" x 1/2" Plate
- 1/2" Pipe Strap or similar
- Screws, Nuts, and Bolts
- Male to Male Jumper Wires
- 315MHz Spring Antenna (Recommended)
- Arduino Uno Case (Optional)
- [Spektrum AR500 Receiver](http://www.spektrumrc.com/Products/Default.aspx?ProdId=SPMAR500) (Optional)
- [Spektrum DX5e Transmitter](http://www.spektrumrc.com/Products/Default.aspx?ProdId=SPM5500) (Optional)

## Installation
```bash
$ mkdir -vp ~/sketchbook
$ cd ~/sketchbook
$ git clone https://github.com/nathanurwin/arduino-lock.git
```

## Configuration
Set `bool L12_R_SERVO` to `true` or `false` in `linearServo.ino`.

## Usage
1. Run the Arduino IDE.
2. Select `File > Sketchbook > arduino-lock > src`.
3. Setup and Connect the Arduino board to PC.
4. Compile and Upload to the Arduino board.
5. Mount your new door lock and try it out!

## Example

### L12-R
![L12-R Example](images/L12-R.gif "L12-R Example")

### ProtonRev2
![ProtonRev2 Example](images/ProtonRev2.gif "ProtonRev2 Example")

## Resources
- [The RPF Original Thread](http://www.therpf.com/showthread.php?t=245997)
- [Arduino Servo Reference](https://www.arduino.cc/en/Reference/Servo)

## Development
See [CONTRIBUTING](CONTRIBUTING.md)

### Future
See [ROADMAP](ROADMAP.md)

### History
See [CHANGELOG](CHANGELOG.md)

## Credits
See [AUTHORS](AUTHORS.md)

## License
See [LICENSE](LICENSE)
