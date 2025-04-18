# Ratatoskr Scripts Doc

## Overview

This document specifies a high-level overview of each script.

## Restart

Shuts down and then restarts the docker images specified by the docker compose v2 plugin. 

#### Usage

This is basically the only thing that needs to be done. Use this to simplify smoke testing

```sh
$ ./restart.sh
```


## Serialize

Serializes the docker images specified by tag name of format: \<namespace\>/\<name\>

All images serialized are those specified by the latest tag. Ensure each of the latest
images are compatible with each other via usage of docker compose v2.

For further details on running with docker compose, see the root repo README.

Results in an artifact called "ratatoskr-flash" as a tar file. Use this with scp to
manually port things over to the nano.

#### Usage

```sh
$ ./serialize \[-o output-directory\]
```

#### Example

Saves a deployable tar to the current file.

```sh
$ ./serialize -o .
```


## Transfer

This script does a reverse-download to the jetson nano. Putting the source to the jetson
nano destination by ipv4.

Note that the login user credential is always specified to "uastarr". Alternate logins are not supported.

#### Usage

```sh
$ ./transfer.sh \[-s \<src-path\>\] \[-d \<dst-ipv4\>\]
```

Where:
    \<src-path\> is the OS host path to a given file and...
    \<dst-ipv4\> is the ipv4 of the ssh agent (typically the jetson nano)

Note that reverse-downloads are always placed in the `/home/user/Downloads` directory of the jetson nano.

#### Example

First we serialize the current instance of the application using the "serialize" script above...

```sh
$ ./serialize
```

Which creates an osi-container tar into the ratatoskr-flash.tar.gz in the `\<pwd\>/build/bin` directory.

To transfer to the nano hosted on `192.168.1.200` via a connected ethernet cable...

```sh
# Note that the ipv4 may be different (probably should be) for your subnet and ISP. See root documentation for setup details.
$ transfer -s ./build/bin/ratatoskr-flash.tar.gz -d 192.168.1.200
```

Which will place the tar file into the jetson nano downloads directly. Switching to the jetson nano using:

```sh
$ ssh uastarr@192.168.1.200
```

And after authenticating with the current password, we can navigate to the Downloads directory and install the application.

```sh
$ cd /home/uastarr/Downloads
$ docker load ./ratatoskr-flash.tar.gz
```

Which will replace and load the docker application components into the jetson nano docker engine. They are now tagged, and can be launched. Note that for production-styled testing we have a `/home/user/Production/ratatoskr` directory. 

For release, see the release instructions on the github pages wiki.
