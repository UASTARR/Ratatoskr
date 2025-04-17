# Ratatoskr Scripts Doc

## Overview

This document specifies a high-level overview of each script.

## Restart

Shuts down, then restarts, the docker images specified by the docker compose v2 plugin. 

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
