#!/bin/bash

ln -s ~/topcoder/conf/contestapplet.conf     ~/contestapplet.conf
ln -s ~/topcoder/conf/contestapplet.conf.bak ~/contestapplet.conf.bak

#/usr/lib/jvm/java-6-openjdk/jre/bin/javaws.real /home/kondo/topcoder/ContestAppletProd.jnlp
/usr/lib/jvm/java-6-openjdk/jre/bin/javaws.real -J-Xmx128m -Xnofork /home/kondo/topcoder/conf/ContestAppletProd.jnlp

rm ~/contestapplet.conf
rm ~/contestapplet.conf.bak

