#!/bin/bash

INTERFACE=$1
ACTION=$2

if [ "$ACTION" == "up" ]; then
  sudo -u kaikaci DISPLAY=:0 XDG_RUNTIME_DIR=/run/user/$(id -u kaikaci) xdg-open /home/kaikaci/Pictures/duo.jpeg
fi
#put it in /etc/NetworkManager/dispatcher.d/
