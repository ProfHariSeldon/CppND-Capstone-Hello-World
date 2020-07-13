# CPPND: Capstone Hello World Repo

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application starting with this repo, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./HelloWorld`.

## #include TensorFlow fails

The #includes recommended by the Udacity C++ course using this link: https://www.tensorflow.org/guide/create_op
```
#include "tensorflow/core/framework/op.h"
#include "tensorflow/core/framework/shape_inference.h"
```

The actual location of those two files in my Ubuntu 18.04.4 LTS Virtual Machine
```
#include "./.local/lib/python2.7/site-packages/tensorflow_core/include/tensorflow/core/framework/op.h"
#include "./.local/lib/python2.7/site-packages/tensorflow_core/include/tensorflow/core/framework/shape_inference.h"
```

Neither #include works both say "cannot open source file" in Visual Studio Code

## TensorFlow install errors

Here is the full install text output:
```
tlroot@tlroot-VirtualBox:~$ sudo apt install python-pip
[sudo] password for tlroot: 
Reading package lists... Done
Building dependency tree       
Reading state information... Done
The following packages were automatically installed and are no longer required:
  cmake-data libcurl4 libjsoncpp1 librhash0 libuv1
Use 'sudo apt autoremove' to remove them.
The following additional packages will be installed:
  libpython-all-dev libpython-dev libpython2.7-dev python-all python-all-dev
  python-asn1crypto python-cffi-backend python-crypto python-cryptography
  python-dbus python-dev python-enum34 python-gi python-idna python-ipaddress
  python-keyring python-keyrings.alt python-pip-whl python-pkg-resources
  python-secretstorage python-setuptools python-six python-wheel python-xdg
  python2.7-dev
Suggested packages:
  python-crypto-doc python-cryptography-doc python-cryptography-vectors
  python-dbus-dbg python-dbus-doc python-enum34-doc python-gi-cairo
  libkf5wallet-bin gir1.2-gnomekeyring-1.0 python-fs python-gdata
  python-keyczar python-secretstorage-doc python-setuptools-doc
The following NEW packages will be installed:
  libpython-all-dev libpython-dev libpython2.7-dev python-all python-all-dev
  python-asn1crypto python-cffi-backend python-crypto python-cryptography
  python-dbus python-dev python-enum34 python-gi python-idna python-ipaddress
  python-keyring python-keyrings.alt python-pip python-pip-whl
  python-pkg-resources python-secretstorage python-setuptools python-six
  python-wheel python-xdg python2.7-dev
0 upgraded, 26 newly installed, 0 to remove and 12 not upgraded.
Need to get 31.9 MB of archives.
After this operation, 52.4 MB of additional disk space will be used.
Do you want to continue? [Y/n] y
Get:1 http://us.archive.ubuntu.com/ubuntu bionic-updates/main amd64 libpython2.7-dev amd64 2.7.17-1~18.04ubuntu1 [28.3 MB]
Get:2 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 libpython-dev amd64 2.7.15~rc1-1 [7,684 B]
Get:3 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 libpython-all-dev amd64 2.7.15~rc1-1 [1,092 B]
Get:4 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-all amd64 2.7.15~rc1-1 [1,076 B]
Get:5 http://us.archive.ubuntu.com/ubuntu bionic-updates/main amd64 python2.7-dev amd64 2.7.17-1~18.04ubuntu1 [279 kB]
Get:6 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-dev amd64 2.7.15~rc1-1 [1,256 B]
Get:7 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-all-dev amd64 2.7.15~rc1-1 [1,100 B]
Get:8 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-asn1crypto all 0.24.0-1 [72.7 kB]
Get:9 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-cffi-backend amd64 1.11.5-1 [63.4 kB]
Get:10 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-crypto amd64 2.6.1-8ubuntu2 [244 kB]
Get:11 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-enum34 all 1.1.6-2 [34.8 kB]
Get:12 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-idna all 2.6-1 [32.4 kB]
Get:13 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-ipaddress all 1.0.17-1 [18.2 kB]
Get:14 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-six all 1.11.0-2 [11.3 kB]
Get:15 http://us.archive.ubuntu.com/ubuntu bionic-updates/main amd64 python-cryptography amd64 2.1.4-1ubuntu1.3 [221 kB]
Get:16 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-dbus amd64 1.2.6-1 [90.2 kB]
Get:17 http://us.archive.ubuntu.com/ubuntu bionic-updates/main amd64 python-gi amd64 3.26.1-2ubuntu1 [197 kB]
Get:18 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-secretstorage all 2.3.1-2 [11.8 kB]
Get:19 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-keyring all 10.6.0-1 [30.6 kB]
Get:20 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-keyrings.alt all 3.0-1 [16.7 kB]
Get:21 http://us.archive.ubuntu.com/ubuntu bionic-updates/universe amd64 python-pip-whl all 9.0.1-2.3~ubuntu1.18.04.1 [1,653 kB]
Get:22 http://us.archive.ubuntu.com/ubuntu bionic-updates/universe amd64 python-pip all 9.0.1-2.3~ubuntu1.18.04.1 [151 kB]
Get:23 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-pkg-resources all 39.0.1-2 [128 kB]
Get:24 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 python-setuptools all 39.0.1-2 [329 kB]
Get:25 http://us.archive.ubuntu.com/ubuntu bionic/universe amd64 python-wheel all 0.30.0-0.2 [36.4 kB]
Get:26 http://us.archive.ubuntu.com/ubuntu bionic/universe amd64 python-xdg all 0.25-4ubuntu1 [31.3 kB]
Fetched 31.9 MB in 15s (2,180 kB/s)                                            
Selecting previously unselected package libpython2.7-dev:amd64.
(Reading database ... 178293 files and directories currently installed.)
Preparing to unpack .../00-libpython2.7-dev_2.7.17-1~18.04ubuntu1_amd64.deb ...
Unpacking libpython2.7-dev:amd64 (2.7.17-1~18.04ubuntu1) ...
Selecting previously unselected package libpython-dev:amd64.
Preparing to unpack .../01-libpython-dev_2.7.15~rc1-1_amd64.deb ...
Unpacking libpython-dev:amd64 (2.7.15~rc1-1) ...
Selecting previously unselected package libpython-all-dev:amd64.
Preparing to unpack .../02-libpython-all-dev_2.7.15~rc1-1_amd64.deb ...
Unpacking libpython-all-dev:amd64 (2.7.15~rc1-1) ...
Selecting previously unselected package python-all.
Preparing to unpack .../03-python-all_2.7.15~rc1-1_amd64.deb ...
Unpacking python-all (2.7.15~rc1-1) ...
Selecting previously unselected package python2.7-dev.
Preparing to unpack .../04-python2.7-dev_2.7.17-1~18.04ubuntu1_amd64.deb ...
Unpacking python2.7-dev (2.7.17-1~18.04ubuntu1) ...
Selecting previously unselected package python-dev.
Preparing to unpack .../05-python-dev_2.7.15~rc1-1_amd64.deb ...
Unpacking python-dev (2.7.15~rc1-1) ...
Selecting previously unselected package python-all-dev.
Preparing to unpack .../06-python-all-dev_2.7.15~rc1-1_amd64.deb ...
Unpacking python-all-dev (2.7.15~rc1-1) ...
Selecting previously unselected package python-asn1crypto.
Preparing to unpack .../07-python-asn1crypto_0.24.0-1_all.deb ...
Unpacking python-asn1crypto (0.24.0-1) ...
Selecting previously unselected package python-cffi-backend.
Preparing to unpack .../08-python-cffi-backend_1.11.5-1_amd64.deb ...
Unpacking python-cffi-backend (1.11.5-1) ...
Selecting previously unselected package python-crypto.
Preparing to unpack .../09-python-crypto_2.6.1-8ubuntu2_amd64.deb ...
Unpacking python-crypto (2.6.1-8ubuntu2) ...
Selecting previously unselected package python-enum34.
Preparing to unpack .../10-python-enum34_1.1.6-2_all.deb ...
Unpacking python-enum34 (1.1.6-2) ...
Selecting previously unselected package python-idna.
Preparing to unpack .../11-python-idna_2.6-1_all.deb ...
Unpacking python-idna (2.6-1) ...
Selecting previously unselected package python-ipaddress.
Preparing to unpack .../12-python-ipaddress_1.0.17-1_all.deb ...
Unpacking python-ipaddress (1.0.17-1) ...
Selecting previously unselected package python-six.
Preparing to unpack .../13-python-six_1.11.0-2_all.deb ...
Unpacking python-six (1.11.0-2) ...
Selecting previously unselected package python-cryptography.
Preparing to unpack .../14-python-cryptography_2.1.4-1ubuntu1.3_amd64.deb ...
Unpacking python-cryptography (2.1.4-1ubuntu1.3) ...
Selecting previously unselected package python-dbus.
Preparing to unpack .../15-python-dbus_1.2.6-1_amd64.deb ...
Unpacking python-dbus (1.2.6-1) ...
Selecting previously unselected package python-gi.
Preparing to unpack .../16-python-gi_3.26.1-2ubuntu1_amd64.deb ...
Unpacking python-gi (3.26.1-2ubuntu1) ...
Selecting previously unselected package python-secretstorage.
Preparing to unpack .../17-python-secretstorage_2.3.1-2_all.deb ...
Unpacking python-secretstorage (2.3.1-2) ...
Selecting previously unselected package python-keyring.
Preparing to unpack .../18-python-keyring_10.6.0-1_all.deb ...
Unpacking python-keyring (10.6.0-1) ...
Selecting previously unselected package python-keyrings.alt.
Preparing to unpack .../19-python-keyrings.alt_3.0-1_all.deb ...
Unpacking python-keyrings.alt (3.0-1) ...
Selecting previously unselected package python-pip-whl.
Preparing to unpack .../20-python-pip-whl_9.0.1-2.3~ubuntu1.18.04.1_all.deb ...
Unpacking python-pip-whl (9.0.1-2.3~ubuntu1.18.04.1) ...
Selecting previously unselected package python-pip.
Preparing to unpack .../21-python-pip_9.0.1-2.3~ubuntu1.18.04.1_all.deb ...
Unpacking python-pip (9.0.1-2.3~ubuntu1.18.04.1) ...
Selecting previously unselected package python-pkg-resources.
Preparing to unpack .../22-python-pkg-resources_39.0.1-2_all.deb ...
Unpacking python-pkg-resources (39.0.1-2) ...
Selecting previously unselected package python-setuptools.
Preparing to unpack .../23-python-setuptools_39.0.1-2_all.deb ...
Unpacking python-setuptools (39.0.1-2) ...
Selecting previously unselected package python-wheel.
Preparing to unpack .../24-python-wheel_0.30.0-0.2_all.deb ...
Unpacking python-wheel (0.30.0-0.2) ...
Selecting previously unselected package python-xdg.
Preparing to unpack .../25-python-xdg_0.25-4ubuntu1_all.deb ...
Unpacking python-xdg (0.25-4ubuntu1) ...
Setting up python-idna (2.6-1) ...
Setting up python-pip-whl (9.0.1-2.3~ubuntu1.18.04.1) ...
Setting up python-asn1crypto (0.24.0-1) ...
Setting up python-crypto (2.6.1-8ubuntu2) ...
Setting up python-wheel (0.30.0-0.2) ...
Setting up python-pkg-resources (39.0.1-2) ...
Setting up python-cffi-backend (1.11.5-1) ...
Setting up python-gi (3.26.1-2ubuntu1) ...
Setting up python-six (1.11.0-2) ...
Setting up python-enum34 (1.1.6-2) ...
Setting up libpython2.7-dev:amd64 (2.7.17-1~18.04ubuntu1) ...
Setting up python-dbus (1.2.6-1) ...
Setting up python-ipaddress (1.0.17-1) ...
Setting up python-pip (9.0.1-2.3~ubuntu1.18.04.1) ...
Setting up python2.7-dev (2.7.17-1~18.04ubuntu1) ...
Setting up python-all (2.7.15~rc1-1) ...
Setting up python-xdg (0.25-4ubuntu1) ...
Setting up libpython-dev:amd64 (2.7.15~rc1-1) ...
Setting up python-setuptools (39.0.1-2) ...
Setting up python-dev (2.7.15~rc1-1) ...
Setting up libpython-all-dev:amd64 (2.7.15~rc1-1) ...
Setting up python-keyrings.alt (3.0-1) ...
Setting up python-all-dev (2.7.15~rc1-1) ...
Setting up python-cryptography (2.1.4-1ubuntu1.3) ...
Setting up python-secretstorage (2.3.1-2) ...
Setting up python-keyring (10.6.0-1) ...
Processing triggers for man-db (2.8.3-2ubuntu0.1) ...
tlroot@tlroot-VirtualBox:~$ pip install --upgrade pip
Collecting pip
  Downloading https://files.pythonhosted.org/packages/43/84/23ed6a1796480a6f1a2d38f2802901d078266bda38388954d01d3f2e821d/pip-20.1.1-py2.py3-none-any.whl (1.5MB)
    100% |████████████████████████████████| 1.5MB 610kB/s 
Installing collected packages: pip
Successfully installed pip-20.1.1
tlroot@tlroot-VirtualBox:~$ pip install tensorflow
WARNING: pip is being invoked by an old script wrapper. This will fail in a future version of pip.
Please see https://github.com/pypa/pip/issues/5599 for advice on fixing the underlying issue.
To avoid this problem you can invoke Python with '-m pip' instead of running pip directly.
DEPRECATION: Python 2.7 reached the end of its life on January 1st, 2020. Please upgrade your Python as Python 2.7 is no longer maintained. pip 21.0 will drop support for Python 2.7 in January 2021. More details about Python 2 support in pip, can be found at https://pip.pypa.io/en/latest/development/release-process/#python-2-support
Defaulting to user installation because normal site-packages is not writeable
Collecting tensorflow
  Downloading tensorflow-2.1.0-cp27-cp27mu-manylinux2010_x86_64.whl (421.8 MB)
     |████████████████████████████████| 421.8 MB 7.1 kB/s 
Collecting keras-preprocessing>=1.1.0
  Downloading Keras_Preprocessing-1.1.2-py2.py3-none-any.whl (42 kB)
     |████████████████████████████████| 42 kB 494 kB/s 
Collecting opt-einsum>=2.3.2
  Downloading opt_einsum-2.3.2.tar.gz (59 kB)
     |████████████████████████████████| 59 kB 2.1 MB/s 
Collecting gast==0.2.2
  Downloading gast-0.2.2.tar.gz (10 kB)
Requirement already satisfied: enum34>=1.1.6; python_version < "3.4" in /usr/lib/python2.7/dist-packages (from tensorflow) (1.1.6)
Collecting keras-applications>=1.0.8
  Downloading Keras_Applications-1.0.8.tar.gz (289 kB)
     |████████████████████████████████| 289 kB 2.6 MB/s 
Collecting numpy<2.0,>=1.16.0
  Downloading numpy-1.16.6-cp27-cp27mu-manylinux1_x86_64.whl (17.0 MB)
     |████████████████████████████████| 17.0 MB 3.3 MB/s 
Collecting termcolor>=1.1.0
  Downloading termcolor-1.1.0.tar.gz (3.9 kB)
Collecting six>=1.12.0
  Downloading six-1.15.0-py2.py3-none-any.whl (10 kB)
Collecting tensorflow-estimator<2.2.0,>=2.1.0rc0
  Downloading tensorflow_estimator-2.1.0-py2.py3-none-any.whl (448 kB)
     |████████████████████████████████| 448 kB 5.5 MB/s 
Collecting backports.weakref>=1.0rc1; python_version < "3.4"
  Downloading backports.weakref-1.0.post1-py2.py3-none-any.whl (5.2 kB)
Collecting protobuf>=3.8.0
  Downloading protobuf-3.12.2-cp27-cp27mu-manylinux1_x86_64.whl (1.3 MB)
     |████████████████████████████████| 1.3 MB 7.3 MB/s 
Collecting mock>=2.0.0; python_version < "3"
  Downloading mock-3.0.5-py2.py3-none-any.whl (25 kB)
Collecting absl-py>=0.7.0
  Downloading absl-py-0.9.0.tar.gz (104 kB)
     |████████████████████████████████| 104 kB 2.5 MB/s 
Collecting tensorboard<2.2.0,>=2.1.0
  Downloading tensorboard-2.1.0-py2-none-any.whl (3.8 MB)
     |████████████████████████████████| 3.8 MB 4.2 MB/s 
Collecting scipy==1.2.2; python_version < "3"
  Downloading scipy-1.2.2-cp27-cp27mu-manylinux1_x86_64.whl (24.8 MB)
     |████████████████████████████████| 24.8 MB 3.9 MB/s 
Collecting astor>=0.6.0
  Downloading astor-0.8.1-py2.py3-none-any.whl (27 kB)
Collecting functools32>=3.2.3; python_version < "3"
  Downloading functools32-3.2.3-2.tar.gz (31 kB)
Requirement already satisfied: wheel; python_version < "3" in /usr/lib/python2.7/dist-packages (from tensorflow) (0.30.0)
Collecting wrapt>=1.11.1
  Downloading wrapt-1.12.1.tar.gz (27 kB)
Collecting google-pasta>=0.1.6
  Downloading google_pasta-0.2.0-py2-none-any.whl (57 kB)
     |████████████████████████████████| 57 kB 3.7 MB/s 
Collecting grpcio>=1.8.6
  Downloading grpcio-1.30.0-cp27-cp27mu-manylinux2010_x86_64.whl (3.0 MB)
     |████████████████████████████████| 3.0 MB 2.8 MB/s 
Collecting h5py
  Downloading h5py-2.10.0-cp27-cp27mu-manylinux1_x86_64.whl (2.8 MB)
     |████████████████████████████████| 2.8 MB 2.8 MB/s 
Requirement already satisfied: setuptools in /usr/lib/python2.7/dist-packages (from protobuf>=3.8.0->tensorflow) (39.0.1)
Collecting funcsigs>=1; python_version < "3.3"
  Downloading funcsigs-1.0.2-py2.py3-none-any.whl (17 kB)
Collecting google-auth<2,>=1.6.3
  Downloading google_auth-1.18.0-py2.py3-none-any.whl (90 kB)
     |████████████████████████████████| 90 kB 1.7 MB/s 
Collecting requests<3,>=2.21.0
  Downloading requests-2.24.0-py2.py3-none-any.whl (61 kB)
     |████████████████████████████████| 61 kB 303 kB/s 
Collecting google-auth-oauthlib<0.5,>=0.4.1
  Downloading google_auth_oauthlib-0.4.1-py2.py3-none-any.whl (18 kB)
Collecting markdown>=2.6.8
  Downloading Markdown-3.1.1-py2.py3-none-any.whl (87 kB)
     |████████████████████████████████| 87 kB 1.7 MB/s 
Collecting werkzeug>=0.11.15
  Downloading Werkzeug-1.0.1-py2.py3-none-any.whl (298 kB)
     |████████████████████████████████| 298 kB 2.1 MB/s 
Collecting futures>=3.1.1; python_version < "3"
  Downloading futures-3.3.0-py2-none-any.whl (16 kB)
Collecting pyasn1-modules>=0.2.1
  Downloading pyasn1_modules-0.2.8-py2.py3-none-any.whl (155 kB)
     |████████████████████████████████| 155 kB 3.1 MB/s 
Collecting cachetools<5.0,>=2.0.0
  Downloading cachetools-3.1.1-py2.py3-none-any.whl (11 kB)
Collecting rsa<4.1; python_version < "3"
  Downloading rsa-4.0-py2.py3-none-any.whl (38 kB)
Collecting certifi>=2017.4.17
  Downloading certifi-2020.6.20-py2.py3-none-any.whl (156 kB)
     |████████████████████████████████| 156 kB 3.0 MB/s 
Requirement already satisfied: idna<3,>=2.5 in /usr/lib/python2.7/dist-packages (from requests<3,>=2.21.0->tensorboard<2.2.0,>=2.1.0->tensorflow) (2.6)
Collecting chardet<4,>=3.0.2
  Downloading chardet-3.0.4-py2.py3-none-any.whl (133 kB)
     |████████████████████████████████| 133 kB 2.7 MB/s 
Collecting urllib3!=1.25.0,!=1.25.1,<1.26,>=1.21.1
  Downloading urllib3-1.25.9-py2.py3-none-any.whl (126 kB)
     |████████████████████████████████| 126 kB 2.3 MB/s 
Collecting requests-oauthlib>=0.7.0
  Downloading requests_oauthlib-1.3.0-py2.py3-none-any.whl (23 kB)
Collecting pyasn1<0.5.0,>=0.4.6
  Downloading pyasn1-0.4.8-py2.py3-none-any.whl (77 kB)
     |████████████████████████████████| 77 kB 3.1 MB/s 
Collecting oauthlib>=3.0.0
  Downloading oauthlib-3.1.0-py2.py3-none-any.whl (147 kB)
     |████████████████████████████████| 147 kB 2.7 MB/s 
Building wheels for collected packages: opt-einsum, gast, keras-applications, termcolor, absl-py, functools32, wrapt
  Building wheel for opt-einsum (setup.py) ... done
  Created wheel for opt-einsum: filename=opt_einsum-2.3.2-py2-none-any.whl size=52336 sha256=f4244bb8d92258613b48cc2f1968e772e73e65818532da517c3bc41cc9134f13
  Stored in directory: /home/tlroot/.cache/pip/wheels/ef/c4/c2/d0b07dd2a54f4d583a5de0e6ce5eb7a1832961b9a10d1ec953
  Building wheel for gast (setup.py) ... done
  Created wheel for gast: filename=gast-0.2.2-py2-none-any.whl size=7632 sha256=7d92f76e5d39594cb847fb701197b41feb2cb44a6ffa048502f2cc57d6c3f425
  Stored in directory: /home/tlroot/.cache/pip/wheels/0f/10/f7/29260ef8a721b90061c8c70a4f0130a64036e8dafe15acc097
  Building wheel for keras-applications (setup.py) ... done
  Created wheel for keras-applications: filename=Keras_Applications-1.0.8-py2-none-any.whl size=50943 sha256=3072ca9dc8fbe70e5fd180ef552572a9006fe9e6db38bee6c9066e522bb87ab7
  Stored in directory: /home/tlroot/.cache/pip/wheels/71/a0/64/e2e0c93740e0460f4b7f036141b7c73b5e44ff38f690ddff9f
  Building wheel for termcolor (setup.py) ... done
  Created wheel for termcolor: filename=termcolor-1.1.0-py2-none-any.whl size=5678 sha256=cb7cffcfd350d3d47aa2f3d751dc4efd6b34c78df3c8d23a58b80de44c0b33d9
  Stored in directory: /home/tlroot/.cache/pip/wheels/48/54/87/2f4d1a48c87e43906477a3c93d9663c49ca092046d5a4b00b4
  Building wheel for absl-py (setup.py) ... done
  Created wheel for absl-py: filename=absl_py-0.9.0-py2-none-any.whl size=119398 sha256=b5dd75656e5570fbdb5ac562a427e06a2347e65d12decc6b664973b5c859e7e5
  Stored in directory: /home/tlroot/.cache/pip/wheels/37/83/b0/40d9e9f3d5a7021dfda2f3ea1f0088235679cd7747761c7b93
  Building wheel for functools32 (setup.py) ... done
  Created wheel for functools32: filename=functools32-3.2.3.post2-py2-none-any.whl size=10943 sha256=74bd9ff5183216c9bdb0745af129d24a05f73c7f8079df9ac3250e093a09d2ee
  Stored in directory: /home/tlroot/.cache/pip/wheels/c2/ea/a3/25af52265fad6418a74df0b8d9ca8b89e0b3735dbd4d0d3794
  Building wheel for wrapt (setup.py) ... done
  Created wheel for wrapt: filename=wrapt-1.12.1-cp27-cp27mu-linux_x86_64.whl size=51208 sha256=e5d6c1224c7403be17e2c2b8166d83f4e5f7e8c6a1b3098b25d48981a1dff7b9
  Stored in directory: /home/tlroot/.cache/pip/wheels/5b/d8/8e/81a83cb5321b940a954996f5b57fddc8976e712b3ac3a1a54b
Successfully built opt-einsum gast keras-applications termcolor absl-py functools32 wrapt
ERROR: tensorboard 2.1.0 has requirement setuptools>=41.0.0, but you'll have setuptools 39.0.1 which is incompatible.
ERROR: google-auth 1.18.0 has requirement setuptools>=40.3.0, but you'll have setuptools 39.0.1 which is incompatible.
Installing collected packages: six, numpy, keras-preprocessing, opt-einsum, gast, h5py, keras-applications, termcolor, tensorflow-estimator, backports.weakref, protobuf, funcsigs, mock, absl-py, pyasn1, pyasn1-modules, cachetools, rsa, google-auth, certifi, chardet, urllib3, requests, futures, grpcio, oauthlib, requests-oauthlib, google-auth-oauthlib, markdown, werkzeug, tensorboard, scipy, astor, functools32, wrapt, google-pasta, tensorflow
  WARNING: The scripts f2py, f2py2 and f2py2.7 are installed in '/home/tlroot/.local/bin' which is not on PATH.
  Consider adding this directory to PATH or, if you prefer to suppress this warning, use --no-warn-script-location.
  WARNING: The scripts pyrsa-decrypt, pyrsa-encrypt, pyrsa-keygen, pyrsa-priv2pub, pyrsa-sign and pyrsa-verify are installed in '/home/tlroot/.local/bin' which is not on PATH.
  Consider adding this directory to PATH or, if you prefer to suppress this warning, use --no-warn-script-location.
  WARNING: The script chardetect is installed in '/home/tlroot/.local/bin' which is not on PATH.
  Consider adding this directory to PATH or, if you prefer to suppress this warning, use --no-warn-script-location.
  WARNING: The script google-oauthlib-tool is installed in '/home/tlroot/.local/bin' which is not on PATH.
  Consider adding this directory to PATH or, if you prefer to suppress this warning, use --no-warn-script-location.
  WARNING: The script markdown_py is installed in '/home/tlroot/.local/bin' which is not on PATH.
  Consider adding this directory to PATH or, if you prefer to suppress this warning, use --no-warn-script-location.
  WARNING: The script tensorboard is installed in '/home/tlroot/.local/bin' which is not on PATH.
  Consider adding this directory to PATH or, if you prefer to suppress this warning, use --no-warn-script-location.
  WARNING: The scripts estimator_ckpt_converter, saved_model_cli, tensorboard, tf_upgrade_v2, tflite_convert, toco and toco_from_protos are installed in '/home/tlroot/.local/bin' which is not on PATH.
  Consider adding this directory to PATH or, if you prefer to suppress this warning, use --no-warn-script-location.
Successfully installed absl-py-0.9.0 astor-0.8.1 backports.weakref-1.0.post1 cachetools-3.1.1 certifi-2020.6.20 chardet-3.0.4 funcsigs-1.0.2 functools32-3.2.3.post2 futures-3.3.0 gast-0.2.2 google-auth-1.18.0 google-auth-oauthlib-0.4.1 google-pasta-0.2.0 grpcio-1.30.0 h5py-2.10.0 keras-applications-1.0.8 keras-preprocessing-1.1.2 markdown-3.1.1 mock-3.0.5 numpy-1.16.6 oauthlib-3.1.0 opt-einsum-2.3.2 protobuf-3.12.2 pyasn1-0.4.8 pyasn1-modules-0.2.8 requests-2.24.0 requests-oauthlib-1.3.0 rsa-4.0 scipy-1.2.2 six-1.15.0 tensorboard-2.1.0 tensorflow-2.1.0 tensorflow-estimator-2.1.0 termcolor-1.1.0 urllib3-1.25.9 werkzeug-1.0.1 wrapt-1.12.1
tlroot@tlroot-VirtualBox:~$
```
