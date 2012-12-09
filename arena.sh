#!/bin/bash

if [ -L ~/contestapplet.conf ]; then rm ~/contestapplet.conf; fi
if [ -L ~/contestapplet.conf.bak ]; then rm ~/contestapplet.conf.bak; fi
ln -s ~/topcoder/conf/contestapplet.conf     ~/contestapplet.conf
ln -s ~/topcoder/conf/contestapplet.conf.bak ~/contestapplet.conf.bak

#sudo alternatives --set java /usr/lib/jvm/jre-1.7.0-openjdk.x86_64/bin/java

#/usr/lib/jvm/java-6-openjdk/jre/bin/javaws.real /home/kondo/topcoder/ContestAppletProd.jnlp
#/usr/lib/jvm/java-6-openjdk/jre/bin/javaws.real -J-Xmx128m -Xnofork /home/kondo/topcoder/conf/ContestAppletProd.jnlp
#/usr/lib/jvm/java-6-openjdk/jre/bin/javaws -J-Xmx128m -Xnofork /home/kondo/topcoder/conf/ContestAppletProd.jnlp
#/usr/lib/jvm/java-1.6.0-ibm-1.6.0.12.0.x86_64/jre/bin/javaws -J-Xmx128m -Xnofork /home/kondo/topcoder/conf/ContestAppletProd.jnlp
/usr/java/jre1.7.0_09/bin/javaws -J-Xmx128m -Xnofork /home/kondo/topcoder/conf/ContestAppletProd.jnlp

#sudo alternatives --auto java

