# PlatformIO + remote dev containers

This repo is demo setup / me trying to conjure alternative setup in one evening. As PoC it's working with no glaring problems, but something will likely pop up.

## Reasoning

1. I need to program large device, which I can't confortably move to my coding place.
2. PIO setup was always painful to get working from the first time. This streamlines it. Also functions as groundwork for CI.
3. In current setup, all software, drivers & toolchains are semi-manually installed in host OS. Trying to cleanup.


## Setup

### Physical

```mermaid
flowchart LR
    A[Editing Station] -->|WiFi| B[Build Server]
    B -->|Cable| C[Device to program]
```

Key point - Editing Station is not connecting to Device.

### Editing Station

Windows 10 (could be anything) Desktop (could be anything) with VS Code installed.

No other dev tools: 
- no compilers
- no git
- no python
- ...

VS Code has Remote Development pack installed, for "Remote - SSH" and dev containers support.

### Build Server

Raspberry PI 4 (4GB) with "Raspberry Pi OS Lite 64bit" installed via "Raspberry Pi Imager".

Customziation of Raspi OS:
1. [Installed Docker using apt](https://docs.docker.com/engine/install/debian/#install-using-the-repository)
2. [Manage Docker as a non-root user](https://docs.docker.com/engine/install/linux-postinstall/) (add user to docker group)
3. Git user.name and email needs to be configured (need better approach)

Resource utilization:
1. Raspi 3 with 1GB memory runs, but struggles too much when installing PIO toolchains, then IDE does indexing. SD card IO doesn't help
2. So far, Raspi4 with 4GB looks happy. 

## Future work

1. Try with JetBrains IDE. As of now, I still like it more than VS Code
2. VS Code could run in browser via https://github.com/coder/code-server
3. Try using Steam Deck as editing station. Because why not.
4. Looks like on every dev container rebuild VS Code's Platform IO extension needs to be reinstalled. Feels like it's stored inside dev container. Could this be pre-installed?
5. Test with bigger project - how's the performance?
6. PlatformIO has Remote Agent feature, but I'm not sure I'm interested.