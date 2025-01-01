#!/bin/bash

packages=("cowsay" "sysvbanner" "libsqlite3-dev" "cmatrix" "toilet" "libncurses-dev" "g++")

for pkg in "${packages[@]}"; do
	if(which $pkg | grep -q "/" || dpkg --list |grep -q "$pkg"); then 
		echo "Already installed $pkg";
	else
		echo -n "Installing $pkg ... ";
		sudo apt-get install $pkg -y &> ./installationLogs.dat
		if(which $pkg | grep -q "/"); then
			echo "OK";
		fi
	fi
done
