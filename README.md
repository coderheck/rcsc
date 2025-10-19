# ROBLOXClientSettings Copier (rcsc)

`rcsc` is a Windows command-line tool that I wrote myself  for fast copying of Roblox's `ClientAppSettings.json` without the use of [Bloxstrap](https://github.com/bloxstraplabs/bloxstrap).

## Installation

1. download from [the Releases section's "latest" tag](https://github.com/coderheck/rcsc/releases/latest), store the executable in a folder that preferredly has your other usual command-line programs 
2. add the folder where you downloaded `rcsc` to your PATH environment variable ([follow these instructions](https://stackoverflow.com/a/79361333)).

## Usage

run it from your preferred command-line interface by calling `rcsc`

`rcsc` currently only supports copying `ClientAppSettings.json` located in a folder named `ClientSettings` in the same directory as the executable (so the directory string looks like this `.\ClientSettings\ClientAppSettings.json`).

a copy of my current `ClientSettings` setup is included in this repository as an example.

I will update the source code to add custom file directories eventually.

## Building from source

### Requirements

0. an installation of the Roblox player client (why would you even use this program if you don't have a Roblox client installed).
1. a compiler that supports the C++17 standard (for `<filesystem>` library). For releases, I will be using `g++ 15.2`.

### Do the thing

you are free to compile however you want. however if you are tech illiterate you can use the following minimal compiling command: `g++ -std=c++17 -o rcsc rcsc.cpp`

(the above is for GNU `g++` only, for other compilers like Clang or MSVC you'd have to follow their own instructions.)

## TODO
01. write a more comprehensive installation and building guide
02. implement QoL features like custom `ClientSettings` directories and some kind of preset system 


