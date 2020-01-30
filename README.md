# freertps
a free, portable, minimalist RTPS implementation under development

Some documentation is available in the [wiki](https://github.com/ros2/freertps/wiki)

## How to build
You need cmake. To build without ROS on x86 POSIX systems, do as below.

```
mkdir build
cd build
cmake .. -Dfreertps_standalone=ON
make
```
