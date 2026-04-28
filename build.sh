#!/bin/bash
cd ~/projects/hypr_dock/build
make -j$(nproc) && sudo cp ./hypr_dock /usr/local/bin/
