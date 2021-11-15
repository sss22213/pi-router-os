#!/bin/bash

DISTRO=```cat /etc/lsb-release | grep DISTRIB_ID= | sed 's/DISTRIB_ID=//g'```

if [ $DISTRO = "Ubuntu" ] || [ $DISTRO = "Debian" ]
then
    sudo apt update
    sudo apt install build-essential ccache ecj fastjar file g++ gawk \
    gettext git java-propose-classpath libelf-dev libncurses5-dev \
    libncursesw5-dev libssl-dev python python2.7-dev python3 unzip wget \
    python3-distutils python3-setuptools python3-dev rsync subversion \
    swig time xsltproc zlib1g-dev  -y
elif [ $DISTRO = "Arch" ]
then
    pacman -S --needed base-devel autoconf automake bash binutils bison \
    bzip2 fakeroot file findutils flex gawk gcc gettext git grep groff \
    gzip libelf libtool libxslt m4 make ncurses openssl patch pkgconf \
    python rsync sed texinfo time unzip util-linux wget which zlib
    pacman -S --needed asciidoc help2man intltool perl-extutils-makemaker
else
    echo "Can not support os as host machine."
fi